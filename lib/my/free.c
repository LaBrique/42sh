/*
** EPITECH PROJECT, 2017
** free_2d_int
** File description:
** free_2d_int
*/

#include <stdlib.h>

void	free_2d(void **tab, int dim2)
{
	for (int i = 0; i != dim2; i++)
		free(tab[i]);
	free(tab);
}

void	free_3d(void ***tab, int dim2, int dim3)
{
	for (int i = 0; i != dim3; i++)
		free_2d(tab[i], dim2);
	free(tab);
}

void	free_4d(void ****tab, int dim2, int dim3, int dim4)
{
	for (int i = 0; i != dim4; i++)
		free_3d(tab[i], dim2, dim3);
	free(tab);
}

char	*my_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	for (int i = 0; i < (int)old_size; i++)
		new_ptr[i] = ptr[i];
	for (unsigned int i = old_size; i < new_size; i++)
		new_ptr[i] = 0;
	free(ptr);
	return(new_ptr);
}
