/*
** EPITECH PROJECT, 2017
** my_putchar LOL
** File description:
** my_putchar LOL
*/
#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
