/*
** EPITECH PROJECT, 2017
** my_char2d_to_int1d
** File description:
** my_char2d_to_int1d
*/

#include "../../include/my.h"

int	wordcounter2d(char **dim2_char)
{
	int i = 0;

	if (!dim2_char)
		return (0);
	while (dim2_char[i])
		i++;
	return (i);
}

int	*my_char2d_to_int1d(char **dim2_char)
{
	int *array = NULL;
	int size = wordcounter2d(dim2_char);

	array = malloc(sizeof(int) * (size));
	for (int i = 0; i != size; i++)
		array[i] = my_getnbr(dim2_char[i]);
	return (array);
}
