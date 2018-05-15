/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** Copies a string into another
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;
	int len = my_strlen(src);
	char *new;

	if ((new = malloc(sizeof(char) * (my_strlen(dest) + len) + 1)) == NULL)
		return (NULL);
	while (i <= len) {
		new[i] = src[i];
		i += 1;
	}
	new[i] = '\0';
	free(dest);
	return (new);
}
