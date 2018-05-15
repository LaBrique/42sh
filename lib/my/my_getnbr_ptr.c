/*
** EPITECH PROJECT, 2017
** my_getnbr_ptr
** File description:
** my_getnbr_ptr
*/

#include "../../include/my.h"

int	*my_getnbr_ptr(char const *str)
{
	int *number = malloc(sizeof(int));
	int print_sign = 0;

	if (!str)
		return (NULL);
	while (*str == '-' || *str == '+')
		*str++ == '-' ? print_sign++ : 0;
	while (*str >= '0' && *str <= '9') {
		*number = *number * 10;
		*number = *number + *str++ - 48;
	}
	*number = print_sign % 2 == 1 ? *number * -1 : *number;
	return (number);
}
