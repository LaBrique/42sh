/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** my_str_isnum
*/

int	my_str_isnum_min(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] < 48 || str[i] > 57) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
