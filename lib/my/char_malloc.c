/*
** EPITECH PROJECT, 2017
** char_malloc
** File description:
** char_malloc
*/

#include "../../include/my.h"

char	*char_dim1_malloc(int dim1)
{
	char *dim1_char = malloc(sizeof(char) * dim1 + 1);

	if (dim1_char == NULL)
		return (NULL);
	for (int i = 0; i <= dim1; i++)
		dim1_char[i] = 0;
	dim1_char[dim1] = 0;
	return (dim1_char);
}

char	**char_dim2_malloc(int dim1, int dim2)
{
	char **dim2_char = malloc(sizeof(char *) * (dim2 + 1));

	if (dim2_char == NULL)
		return (NULL);
	for (int i = 0; i != dim2; i++)
		dim2_char[i] = char_dim1_malloc(dim1);
	dim2_char[dim2] = NULL;
	return (dim2_char);
}

char	***char_dim3_malloc(int dim1, int dim2, int dim3)
{
	char ***dim3_char = malloc(sizeof(char **) * (dim3 + 1));

	if (dim3_char == NULL)
		return (NULL);
	for (int i = 0; i != dim3; i++)
		dim3_char[i] = char_dim2_malloc(dim1, dim2);
	dim3_char[dim3] = NULL;
	return (dim3_char);
}

char	****char_dim4_malloc(int dim1, int dim2, int dim3, int dim4)
{
	char ****dim4_char = malloc(sizeof(char ***) * (dim4 + 1));

	if (dim4_char == NULL)
		return (NULL);
	for (int i = 0; i != dim4; i++)
		dim4_char[i] = char_dim3_malloc(dim1, dim2, dim3);
	dim4_char[dim4] = NULL;
	return (dim4_char);
}
