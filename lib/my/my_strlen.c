/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** my_strlen
*/

#include <stdio.h>

int	my_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i++]);
	return (--i);
}
