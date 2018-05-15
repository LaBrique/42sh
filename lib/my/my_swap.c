/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** my_swap
*/
void	my_putchar(char);

void	my_swap(int *a, int *b)
{
	int c = 0;

	c = *b;
	*b = *a;
	*a = c;
}
