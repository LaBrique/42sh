/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>

int	my_strlen(char const *str);

char	*my_strcat(char *a, char const *b, int heap)
{
	char *s = NULL;
	int i = 0;
	int j = 0;
	int lena = a == NULL ? 0 : my_strlen(a);
	int lenb = my_strlen(b);

	if ((s = malloc(sizeof(char) * (lena + lenb) + 1)) == NULL)
		exit(84);
	while (a && a[i]) {
		s[i] = a[i];
		i++;
	}
	while (b && b[j]) {
		s[i + j] = b[j];
		j++;
	}
	s[j + i] = '\0';
	if (a && heap == 1)
		free(a);
	return (s);
}
