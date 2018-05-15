/*
** EPITECH PROJECT, 2017
** realloc
** File description:
** realloc
*/

#include "../../include/my.h"

char	*my_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	for (unsigned int i = 0; i < old_size && ptr[i]; i++)
		new_ptr[i] = ptr[i];
	for (unsigned int i = old_size; i < new_size; i++)
		new_ptr[i] = 0;
	free(ptr);
	return(new_ptr);
}
