#ifndef		MAINLOOP_H_
# define	MAINLOOP_H_
# define	UNUSED(x)	(void)x

# include	<stdio.h>

# include	"init.h"
# include	"leave.h"
# include	"SDL/SDL.h"

typedef struct	s_action t_action;

struct		s_action
{
Uint8	type;
int	(*function)(SDL_Event*);
};

int		mainloop(int *combination);

#endif		/* !MAINLOOP_H_ */
