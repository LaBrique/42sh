/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** Corentin MARZIN
*/

#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"

static const struct test funcs[11] = {
	{'s', &flags},
	{'c', &flagc},
	{'d', &flagd},
	{'i', &flagd},
	{'u', &flagu},
	{'o', &flago},
	{'x', &flagx},
	{'X', &flagX},
	{'S', &flagS},
	{'p', &flagp},
	{'b', &flagb},
};

int	my_put_nbr_base(unsigned int nb, char const *base, int *k)
{
	int right;
	int left;

	left = nb % my_strlen(base);
	right = nb / my_strlen(base);
	if (right != 0)
		my_put_nbr_base(right, base, k);
	my_putchar(base[left]);
	*k += 1;
	return (0);
}

int	my_put_u_nbr(unsigned int nb, int *k)
{
	int right;
	int left;

	left = nb % 10;
	right = nb / 10;
	if (right != 0)
		my_put_u_nbr(right, k);
	my_putchar(left + '0');
	*k += 1;
	return (0);
}

void my_flag(char flag, va_list list, int *k)
{
	for (int i = 0; i != 10; i++) {
		if (funcs[i].key == flag)
			funcs[i].my_func(list, k);
	}
}

void	check_flag(char *str, int *i, int *k, va_list list)
{
	if (str[*i] == '%') {
		if (str[*i + 1] == '%')
		my_putchar('%');
		my_flag(str[*i + 1], list, k);
		*i += 1;
	}
	else
		my_putchar(str[*i]);
}

int	my_printf(char *str, ...)
{
	va_list list;
	int k = 0;

	va_start(list, str);
	for (int i = 0; str[i] != 0; i++, k++)
		check_flag(str, &i, &k, list);
	va_end(list);
	return (k);
}
