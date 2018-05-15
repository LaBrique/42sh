/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** my_strstr
*/

#include <unistd.h>

char	*my_strstr(char *str, char *to_find)
{
	int i = 0;
	int j = 0;
	int boul = -1;

	while (str[i] != '\0') {
		while (str[i + j] == to_find[j]) {
			boul = to_find[j + 1] == 0 ? i : -1;
			j++;
		}
		i++;
		j = 0;
	}
	return (boul == -1 ? NULL : str + boul);
}
