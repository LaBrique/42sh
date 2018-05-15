/*
** EPITECH PROJECT, 2017
** int_malloc
** File description:
** int_malloc
*/

#include "../../include/my.h"

int	*int_dim1_malloc(int dim1)
{
	int *dim1_int = malloc(sizeof(int) * dim1);

	if (dim1_int == NULL)
		return (NULL);
	for (int i = 0; i != dim1; i++)
		dim1_int[i] = 0;
	return (dim1_int);
}

int	**int_dim2_malloc(int dim1, int dim2)
{
	int **dim2_int = malloc(sizeof(int *) * dim2);

	if (dim2_int == NULL)
		return (NULL);
	for (int i = 0; i != dim2; i++)
		dim2_int[i] = int_dim1_malloc(dim1);
	return (dim2_int);
}

int	***int_dim3_malloc(int dim1, int dim2, int dim3)
{
	int ***dim3_int = malloc(sizeof(int **) * dim3);

	if (dim3_int == NULL)
		return (NULL);
	for (int i = 0; i != dim3; i++)
		dim3_int[i] = int_dim2_malloc(dim1, dim2);
	return (dim3_int);
}

int	****int_dim4_malloc(int dim1, int dim2, int dim3, int dim4)
{
	int ****dim4_int = malloc(sizeof(int ***) * dim4);

	if (dim4_int == NULL)
		return (NULL);
	for (int i = 0; i != dim4; i++)
		dim4_int[i] = int_dim3_malloc(dim1, dim2, dim3);
	return (dim4_int);
}
