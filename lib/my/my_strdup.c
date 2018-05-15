/*
** EPITECH PROJECT, 2017
** lib/my/my_strdup
** File description:
** lib/my/my_strdup
*/

#include "../../include/my.h"

char	*my_strdup(char const *str)
{
	int size = my_strlen(str);
	char *new = malloc(sizeof(char) * size);

	for (int i = 0; i != size; i++)
		new[i] = str[i];
	return (new);
}
