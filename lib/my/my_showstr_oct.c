/*
** EPITECH PROJECT, 2017
** my_showstr_oct
** File description:
** my_showstr_oct
*/

#include "../../include/my.h"

int	my_showstr_oct(char const *str, int *k)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < 32) {
			my_putstr((str[i] < 8) ? "\\00" : "\\0");
			my_put_nbr_base(str[i], "01234567", k);
		} else
			my_putchar(str[i]);
		i++;
	}
	return (i);
}
