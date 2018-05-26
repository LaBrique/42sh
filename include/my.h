/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdlib.h>
#include "my_printf.h"
#include "get_next_line.h"

int	my_put_nbr_hexa(unsigned long nbr, int MAJ, int *k);
int	max(int size, ...);
int	verify_sorted(int *array, int size);
int	min(int size, ...);
int	*int_dim1_malloc(int dim1);
int	**int_dim2_malloc(int dim1, int dim2);
int	***int_dim3_malloc(int dim1, int dim2, int dim3);
int	****int_dim4_malloc(int dim1, int dim2, int dim3, int dim4);
double	*double_dim1_malloc(int dim1);
double	**double_dim2_malloc(int dim1, int dim2);
double	***double_dim3_malloc(int dim1, int dim2, int dim3);
double	****double_dim4_malloc(int dim1, int dim2, int dim3, int dim4);
char	*char_dim1_malloc(int dim1);
char	**char_dim2_malloc(int dim1, int dim2);
char	***char_dim3_malloc(int dim1, int dim2, int dim3);
char	****char_dim4_malloc(int dim1, int dim2, int dim3, int dim4);
int wordcounter2d(char **dim2_char);
int *my_char2d_to_int1d(char **dim2_char);
int wordcounter(char *string, char *breaker);
void fill_2dchar(char *string, char *word, char *breaker, int *j);
//char **my_char1d_to_char2d(char *string, char *breaker);
char **my_char1d_to_char2d(char *str, char *separators);
void my_putchar(char c);
int my_put_nbr(int nb, int *k);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_showstr_oct(char const *str, int *k);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src, int heap);
char *my_strncat(char *dest, char const *src, int nb);
void free_2d(void *tab, int dim2);
void free_3d(void *tab, int dim2, int dim3);
void free_4d(void *tab, int dim2, int dim3, int dim4);
char *my_itoa(int nbr);
char *my_strdup(char const *str);
char	*my_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
int	my_str_isnum(char const *str);
int	my_str_isalpha(char const *str);
int	my_charstr(char ch, char *str);
int	is_char_present(char c, char *str);
char	*my_strdup_except(char *str, char except);
void	remove_separators_backward(char *str, char *sep, char *oper);
char	*remove_separators(char *str, char *sep, char *oper);
#endif /*_MY_H_*/
