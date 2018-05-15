/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char	*my_strcapitalize(char *str)
{
	int i = 1;

	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	while (str[i] != '\0') {
		if (str[i] >= 97 && str[i] <= 122 && (!((str[i - 1] >= 97 &&
			str[i - 1] <= 122) ||
			(str[i - 1] >= 65 && str[i - 1] <= 90))))
			str[i] = str[i] - 32;
		else if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
