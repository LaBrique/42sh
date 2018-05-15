/*
** EPITECH PROJECT, 2017
** my_char1d_to_char2d
** File description:
** my_char1d_to_char2d
*/

#include "../../include/my.h"

int	wordcounter(char *string, char *breaker)
{
	int count = 1;
	int expr = 0;

	if (!string)
		return (0);
	for (int i = 0; string[i]; i++) {
		expr += string[i] == '\"' ? 1 : 0;
		if (expr % 2 != 1)
			count += my_charstr(string[i], breaker) ? 1 : 0;
	}
	return (count);
}

void	fill_2dchar(char *string, char *word, char *breaker, int *j)
{
	int expr = 0;
	for (int k = 0; string[*j]; *j += 1, k++) {
		if (string[*j] == '\"') {
			expr++;
			*j += 1;
			continue;
		}
		if (my_charstr(string[*j], breaker) && expr % 2 != 1) {
			*j += 1;
			break;
		} else
			word[k] = string[*j];
		word[k + 1] = 0;
	}
}

char	**my_char1d_to_char2d(char *string, char *breaker)
{
	int wordcount = wordcounter(string, breaker);
	char **dim2_char = char_dim2_malloc(my_strlen(string), wordcount);

	for (int i = 0, j = 0; i != wordcount; i++)
		fill_2dchar(string, dim2_char[i], breaker, &j);
	return (dim2_char);
}
