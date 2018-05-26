/*
** EPITECH PROJECT, 2017
** need4stek
** File description:
** made by Christophe Chauvot [MPL - 2022]
*/

#include "../../include/my.h"

int	is_char_present(char c, char *str)
{
	for (size_t i = 0; str[i]; i++) {
		if (str[i] == c)
			return (1);
	}
	return (0);
}

char	*my_strdup_except(char *str, char except)
{
	int len = 0;
	char *dup = NULL;
	int j = 0;

	for (size_t i = 0; str[i]; i++) {
		if (str[i] != except)
			len++;
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (size_t i = 0; str[i]; i++) {
		dup[j] = str[i];
		if (str[i] != except)
			j++;
	}
	dup[j] = '\0';
	return (dup);
}

void	remove_separators_backward(char *str, char *sep, char *oper)
{
	int sentence = 0;
	size_t i = (int)my_strlen(str) - 1;

	for (; i; i--) {
		if (is_char_present(str[i], oper))
			sentence = 0;
		else if (!is_char_present(str[i], sep))
			sentence = 1;
		if (sentence == 0 && is_char_present(str[i], sep))
			str[i] = '\a';
	}
}

char	*remove_separators(char *str, char *sep, char *oper)
{
	char *clean = NULL;
	int sentence = 0;
	int ignore = 0;

	for (size_t i = 0; str[i]; i++) {
		if (str[i] == '"') {
			ignore = (ignore == 1) ? 0 : 1;
			str[i] = '\a';
		}
		if (is_char_present(str[i], oper))
			sentence = 0;
		else if (!is_char_present(str[i], sep))
			sentence = 1;
		if (!ignore && (is_char_present(str[i + 1], sep) ||
			sentence == 0) && is_char_present(str[i], sep))
			str[i] = '\a';
	}
	remove_separators_backward(str, sep, oper);
	clean = my_strdup_except(str, '\a');
	return (clean);
}
