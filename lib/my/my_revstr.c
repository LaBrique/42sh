/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** my_revstr
*/

#include "../../include/my.h"

char	*my_revstr(char *str)
{
	int j = my_strlen(str) -1;
	char temp = 0;
	int i = temp;

	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}
