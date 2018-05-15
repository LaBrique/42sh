##
## EPITECH PROJECT, 2017
## mysh
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=	core.c			\
		miscellaneous.c		\
		change_directory.c	\
		environment.c		\
		set_environment.c	\
		unset_environment.c	\
		parser.c		\
		command.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Iinclude -Llib/my -lmy -g3

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)

	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:

	$(RM) $(OBJS)

fclean: clean

	$(RM) $(NAME)

re: fclean all
