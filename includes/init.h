#ifndef		INIT_H_
# define	INIT_H_
# define	_XOPEN_SOURCE
# define	BPP		32
# define	CAPTION		"andro-lock"
# define	ENV_CENTER	"SDL_VIDEO_CENTERED=center"
# define	SIZE_SIDE	300

# include	<SDL/SDL.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/types.h>

# include	"leave.h"

int		init(void);

#endif		/* !INIT_H_ */
