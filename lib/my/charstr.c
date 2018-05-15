/*
** EPITECH PROJECT, 2017
** lib/my/charstr
** File description:
** lib/my/charstr
*/

#include "../../include/my.h"

int	my_charstr(char ch, char *str)
{
	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] == ch)
			return (1);
	}
	return (0);
}
