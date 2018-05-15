/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
	int len = my_strlen(s1);

	if (len != my_strlen(s2) || !s1 || !s2)
		return (0);
	for (int i = 0; i != len; i++) {
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int	my_str_isnum(char const *str)
{
	if (!str)
		return (0);
	for (int i = 0; str[i]; i++) {
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
