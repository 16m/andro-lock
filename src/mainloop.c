#include	"mainloop.h"

static int	continue_loop = 1;
static int	keys[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
static int	pos = 0;
static int	is_locked = 0;

/**
 ** Set the static global variable continue_loop to 0 and display an exit 
 ** message. This has the effect to stop the main loop.
 **
 ** @param event the last event that happened
 ** @return always 1
 */
static int	quit(SDL_Event *event)
{
  UNUSED(event);
  continue_loop = 0;
  puts("Leaving. Bye, see you next time !");
  return (1);
}

/**
 ** Handle the keyboard. Just make a call to the quit function if the escape
 ** button was pressed
 **
 ** @param event the last event that happened
 ** @return always 1
 */
static int	keyboard(SDL_Event *event)
{
  if (event->key.keysym.sym == SDLK_ESCAPE && !is_locked)
    return (quit(event));
  return (1);
}

/**
 ** Triggered when any mouse button is down. If it's the button 1, then
 ** a new key is recorded in the keys tab.
 **
 ** @param event the last event that happened
 ** @return always 1
 */
static int	mouse_down(SDL_Event *event)
{
  int		x;
  int		y;
  int		offset;

  if (event->button.button != 1)
    return (1);
  if (!is_locked)
    {
      SDL_WM_GrabInput(SDL_GRAB_ON);
      is_locked = 1;
      return (1);
    }
  SDL_GetMouseState(&x, &y);
  offset = x / (SIZE_SIDE / 3) + 3 * (y / (SIZE_SIDE / 3));
  keys[pos] = offset;
  pos = (pos + 1) % 9;
  return (1);
}

t_action	actions[] =
  {
    {SDL_QUIT, &quit},
    {SDL_KEYDOWN, &keyboard},
    {SDL_MOUSEBUTTONDOWN, &mouse_down},
    {-1, NULL}
  };

/**
 ** Check if the correct combination is the same that the recorded keys
 **
 ** @param combination the correct combination
 ** @return 1 if combination match, 0 otherwise
 */
static int	check_keys(int *combination)
{
  int		i;
  int		off;

  off = pos;
  for (i = 0; i < 9; ++i, off = (off + 1) % 9)
    {
      if (combination[i] != keys[off])
	return (0);
    }
  SDL_WM_GrabInput(SDL_GRAB_OFF);
  is_locked = 0;
  for (i = 0; i < 9; ++i)
    keys[i] = -1;
  return (1);
}

/**
 ** The main loop of the program.
 **
 ** @return 1 on success, 0 on failure
 */
int		mainloop(int *combination)
{
  SDL_Event	event;
  int		i;

  while (continue_loop)
    {
      if (!SDL_WaitEvent(&event))
	return (leave());
      for (i = 0; actions[i].function; ++i)
	{
	  if (event.type == actions[i].type &&
	      !actions[i].function(&event))
	    return (leave());
	  if (check_keys(combination))
	    return (1);
	}
    }
  return (1);
}
