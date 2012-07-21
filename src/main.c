#include	"init.h"
#include	"load_combination.h"
#include	"mainloop.h"

int		main()
{
  int		*combination;

  if ((combination = load_combination()) == NULL)
    return (EXIT_FAILURE);
  if (!init())
    return (EXIT_FAILURE);
  if (!mainloop(combination))
    return (EXIT_FAILURE);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
