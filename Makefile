##
## EPITECH PROJECT, 2017
## mysh
## File description:
## Makefile
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCS	=	main.c			\
		core.c			\
		miscellaneous.c		\
		change_directory.c	\
		environment.c		\
		set_environment.c	\
		unset_environment.c	\
		parser.c		\
		command.c		\
		echo.c			\
		miscellaneous_bis.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -Iinclude -Llib/my -lmy -g3

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)

	make -C lib/my
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:

	make -C lib/my clean
	$(RM) $(OBJS)

fclean: clean

	make -C lib/my fclean
	$(RM) $(NAME)

re: fclean all
