##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile lib
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -pedantic

SRC	=	my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c				\
		my_revstr.c				\
		my_strcat.c				\
		my_strcmp.c				\
		my_strcpy.c				\
		my_strlen.c				\
		my_strstr.c				\
		my_swap.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strncat.c				\
		my_getnbr.c				\
		my_sort_int_array.c			\
		my_showstr_oct.c			\
		my_intstrcmp.c				\
		my_printf.c				\
		my_put_nbr_hexa.c			\
		my_flags1.c				\
		my_flags2.c				\
		free.c					\
		my_char1d_to_char2d.c			\
		my_char2d_to_int1d.c			\
		char_malloc.c				\
		int_malloc.c				\
		double_malloc.c				\
		min_max.c				\
		my_itoa.c				\
		my_strdup.c				\
		get_next_line.c				\
		realloc.c				\
		charstr.c				\
		remove_separators.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
