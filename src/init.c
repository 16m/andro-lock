#include	"init.h"

/**
 ** Load the wallpaper and blit it on the screen.
 **
 ** @param screen the SDL_Surface structure of the screen
 ** @return 1 on success, 0 on failure
 */
static int	set_wallpaper(SDL_Surface *screen)
{
  SDL_Surface	*wallpaper;
  SDL_Rect	rect;

  if ((wallpaper = SDL_LoadBMP("./res/wallpaper.bmp")) == NULL)
    {
      puts("Error : Could not set the wallpaper");
      return (0);
    }
  rect.x = 0;
  rect.y = 0;
  rect.w = SIZE_SIDE;
  rect.h = SIZE_SIDE;
  if (SDL_BlitSurface(wallpaper, &rect, screen, NULL) == -1)
    return (0);
  SDL_Flip(screen);
  return (1);
}

/**
 ** Initialise SDL, set a caption and create a window
 **
 ** @return 1 on success, 0 on failure
 */
int		init(void)
{
  SDL_Surface	*screen;

  if (SDL_putenv(ENV_CENTER) != 0)
    puts("Warning : Could not set SDL_VIDEO_CENTER environment variable");
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (leave());
  SDL_WM_SetCaption(CAPTION, NULL);
  if ((screen = SDL_SetVideoMode(SIZE_SIDE, SIZE_SIDE, BPP,
				 SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return (leave());
  if (!set_wallpaper(screen))
    return (leave());
  return (1);
}
