/*
** EPITECH PROJECT, 2017
** double_malloc
** File description:
** double_malloc
*/

#include "../../include/my.h"

double	*double_dim1_malloc(int dim1)
{
	double *dim1_double = malloc(sizeof(double) * dim1);

	if (dim1_double == NULL)
		return (NULL);
	for (int i = 0; i != dim1; i++)
		dim1_double[i] = 0;
	return (dim1_double);
}

double	**double_dim2_malloc(int dim1, int dim2)
{
	double **dim2_double = malloc(sizeof(double *) * dim2);

	if (dim2_double == NULL)
		return (NULL);
	for (int i = 0; i != dim1; i++)
		dim2_double[i] = double_dim1_malloc(dim1);
	return (dim2_double);
}

double	***double_dim3_malloc(int dim1, int dim2, int dim3)
{
	double ***dim3_double = malloc(sizeof(double **) * dim3);

	if (dim3_double == NULL)
		return (NULL);
	for (int i = 0; i != dim2; i++)
		dim3_double[i] = double_dim2_malloc(dim1, dim2);
	return (dim3_double);
}

double	****double_dim4_malloc(int dim1, int dim2, int dim3, int dim4)
{
	double ****dim4_double = malloc(sizeof(double ***) * dim4);

	if (dim4_double == NULL)
		return (NULL);
	for (int i = 0; i != dim3; i++)
		dim4_double[i] = double_dim3_malloc(dim1, dim2, dim3);
	return (dim4_double);
}
