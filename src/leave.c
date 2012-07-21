#include	"leave.h"

/**
 ** Display the last SDL error message before shutting down SDL and returning 0.
 ** This function is triggered when something fails during execution.
 **
 ** returns always 0
 */
int		leave(void)
{
  puts(SDL_GetError());
  SDL_Quit();
  return (0);
}
