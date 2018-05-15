/*
** EPITECH PROJECT, 2017
** my_intstrcmp
** File description:
** my_intstrcmp
*/

int	my_strlen(char const *);

int	my_intstrcmp(char const *s1, char const *s2)
{
	int lenght_1 = my_strlen(s1);
	int lenght_2 = my_strlen(s2);

	if (lenght_1 > lenght_2)
		return (1);
	else if (lenght_2 > lenght_1)
		return (-1);
	for (int i = 0; s1[i] != 0; i++) {
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}
	return (0);
}
