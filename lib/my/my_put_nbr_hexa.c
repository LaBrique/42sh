/*
** EPITECH PROJECT, 2017
** my_put_nbr_hexa
** File description:
** my_put_nbr_hexa
*/

#include "../../include/my.h"

int	my_put_nbr_hexa(unsigned long nbr, int MAJ, int *k)
{
	long right;
	long nb;

	nb = nbr % 16;
	right = nbr / 16;
	if (right != 0)
		my_put_nbr_hexa(right, MAJ, k);
	my_putchar((nb > 9) ? nb + (MAJ == 0 ? 'W' : '7') : nb + '0');
	*k += 1;
	return (0);
}
