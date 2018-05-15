/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Corentin MARZIN
*/

#include <stdarg.h>
#include "../../include/my.h"

void	flagx(va_list list, int *k)
{
	my_put_nbr_base(va_arg(list, unsigned long), "0123456789abcdef", k);
}

void	flagX(va_list list, int *k)
{
	my_put_nbr_base(va_arg(list, unsigned long), "0123456789ABCDEF", k);
}

void	flago(va_list list, int *k)
{
	my_put_nbr_base(va_arg(list, unsigned long), "01234567", k);
}

void	flagu(va_list list, int *k)
{
	my_put_u_nbr(va_arg(list, unsigned int), k);
}

void	flagb(va_list list, int *k)
{
	my_put_nbr_base(va_arg(list, unsigned long), "01", k);
}
