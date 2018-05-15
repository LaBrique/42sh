/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** my_sort_int_array
*/

#include <stdlib.h>

void	my_sort_int_array(int *tab, int size)
{
	int *stock = NULL;
	int i = 0;

	if ((stock = malloc(sizeof(int) * size)) == NULL)
		exit(84);
	while (i < size - 1) {
		if (tab[i] > tab[i + 1] && i + 1 < size) {
			stock[i] = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = stock[i];
			i = -1;
		}
		i++;
	}
	free(stock);
}
