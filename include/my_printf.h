/*
** EPITECH PROJECT, 2017
** my_printf.h
** File description:
** my_printf.h
*/

#ifndef _MY_PRINTF_H_
#define _MY_PRINTF_H_
#include <stdarg.h>

struct test {
	char key;
	void (*my_func)(va_list list, int *k);
};

int	my_put_u_nbr(unsigned int nb, int *k);
int	my_put_nbr_oct(unsigned int nb, int *k);
int	my_put_nbr_bin(unsigned int nb, int *k);
int	my_put_nbr_hexa(unsigned long nbr, int MAJ, int *k);
int	my_put_nbr_base(unsigned int nbr, char const *base, int *k);
void	flagc(va_list list, int *k);
void	flagp(va_list list, int *k);
void	flagd(va_list list, int *k);
void	flags(va_list list, int *k);
void	flagS(va_list list, int *k);
void	flagx(va_list list, int *k);
void	flagX(va_list list, int *k);
void	flago(va_list list, int *k);
void	flagu(va_list list, int *k);
void	flagb(va_list list, int *k);
void	my_flag(char flag, va_list list, int *k);
int	my_printf(char *str, ...);

#endif /*_MY_PRINTF_H_*/
