/*
** EPITECH PROJECT, 2017
** my_itoa
** File description:
** my_itoa
*/

#include <stdlib.h>
#include "../../include/my.h"

char	*my_itoa(int nbr)
{
	int result = nbr;
	char *str;
	int mod = 0;
	int i = 0;

	while (result != 0) {
		result /= 10;
		i++;
	}
	str = char_dim1_malloc(i);
	result = nbr;
	i = 0;
	while (result != 0) {
		mod = result % 10;
		str[i] = mod + 48;
		result = result / 10;
		i++;
	}
	return (my_revstr(str));
}
