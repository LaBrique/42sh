/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>

void	my_putchar(char c);

int	my_put_nbr(int nb, int *k)
{
	int right;
	int left;

	if (nb == -2147483648) {
		write(1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	left = nb % 10;
	right = nb / 10;
	if (right != 0)
		my_put_nbr(right, k);
	my_putchar(left + '0');
	*k += 1;
	return (0);
}
