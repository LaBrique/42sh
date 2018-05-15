/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int	my_strncmp(char const *s1, char const *s2, int n)
{
	for (int i = 0; i != my_strlen(s1) && i < n; i++) {
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
