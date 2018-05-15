/*
** EPITECH PROJECT, 2017
** min
** File description:
** min
*/

#include <stdarg.h>
#include "../../include/my.h"

int	verify_sorted(int *array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}

int	min(int size, ...)
{
	int *array = NULL;

	va_list ap;
	array = int_dim1_malloc(size);
	va_start(ap, size);
	for (int j = 0; j < size; j++) {
		array[j] = va_arg(ap, int);
	}
	while (verify_sorted(array, size) != 1)
		my_sort_int_array(array, size);
	return (*array);
}

int	max(int size, ...)
{
	int *array = NULL;

	va_list ap;
	array = int_dim1_malloc(size);
	va_start(ap, size);
	for (int j = 0; j < size; j++) {
		array[j] = va_arg(ap, int);
	}
	while (verify_sorted(array, size) != 1)
		my_sort_int_array(array, size);
	return (array[size - 1]);
}
