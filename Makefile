#----------------------------------------------------------#
#		TOOLS					   #
#----------------------------------------------------------#
CC	=	gcc
RM	=	rm -vf


#----------------------------------------------------------#
#		FLAGS					   #
#----------------------------------------------------------#
CFLAGS	=	-Wall -Wextra -Werror -pedantic -ansi $(IFLAGS)
IFLAGS	=	-I$(DIR_INC)
DEBUG	=	-g -gdb
LDFLAGS	=	-lSDL

#----------------------------------------------------------#
#		FILES					   #
#----------------------------------------------------------#
NAME	=	andro-lock

DIR_INC	=	./includes/
DIR_SRC	=	./src/
SRCS	=	$(DIR_SRC)init.c		\
		$(DIR_SRC)leave.c		\
		$(DIR_SRC)load_combination.c	\
		$(DIR_SRC)mainloop.c		\
		$(DIR_SRC)main.c
OBJS	=	$(SRCS:.c=.o)

#----------------------------------------------------------#
#		RULES					   #
#----------------------------------------------------------#
all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
