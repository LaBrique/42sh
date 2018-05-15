/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Corentin MARZIN
*/

#include <stdarg.h>
#include "../../include/my.h"

void	flagc(va_list list, int *k)
{
	my_putchar(va_arg(list, int));
	*k += 1;
}

void	flagp(va_list list, int *k)
{
	*k += my_putstr("0x");
	my_put_nbr_hexa(va_arg(list, unsigned long), 0, k);
}

void	flagd(va_list list, int *k)
{
	my_put_nbr(va_arg(list, int), k);
}

void	flags(va_list list, int *k)
{
	char *str = va_arg(list, char *);

	if (!str)
		*k += my_printf("(null)");
	else *k += my_putstr(str);
}

void	flagS(va_list list, int *k)
{
	*k += my_showstr_oct(va_arg(list, char *), k);
}
