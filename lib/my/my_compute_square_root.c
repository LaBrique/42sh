/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int	my_compute_square_root(int nb)
{
	int i = 1;

	if (nb == 1)
		return (1);
	if ((nb % 2 != 0 && nb % 2 != 1) ||
	nb >= 2147483647 || nb <= 0)
		return (0);
	while (i < nb)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}
