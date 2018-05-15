/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>

int	my_strlen(char const *str);

char	*my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0') {
		i++;
	}
	while (src[i] != '\0' && j != nb) {
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}
