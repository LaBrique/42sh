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
/*

int	is_separator(const char c, const char *separators)
{
	int i = 0;

	while (separators[i]) {
		if (c == separators[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(const char *str, const char *separators)
{
	int nb_words = 0;
	int i = -1;

	while (is_separator(str[i], separators))
		i++;
	while (str[++i]) {
		if ((is_separator(str[i - 1], separators) || i == 0) &&
		!(is_separator(str[i], separators)))
			nb_words++;
	}
	return (nb_words);
}

int	word_size(const char *str, const char *separators, int word_place)
{
	int cur_word = 0;
	int size = 0;
	int i = -1;

	word_place++;
	while (is_separator(str[++i], separators));
	while (str[i]) {
		if ((is_separator(str[i - 1], separators) || i == 0) &&
		!(is_separator(str[i], separators)))
			cur_word++;
		if (word_place == cur_word && !(is_separator
			(str[i], separators)))
			size++;
		else if (cur_word > word_place)
			break;
		i++;
	}
	return (size + 1);
}

void	fill_word(const char *str, const char *separators, int word_place,
	char *to_fill)
{
	int cur_word = 0;
	int i = -1;
	int j = -1;

	word_place++;
	while (is_separator(str[i], separators))
		i++;
	while (str[++i]) {
		if ((is_separator(str[i - 1], separators) || i == 0) &&
		!(is_separator(str[i], separators)))
			cur_word++;
		if (word_place == cur_word && !(is_separator(str[i],
		separators)))
			to_fill[++j] = str[i];
		else if (cur_word > word_place)
			break;
	}
	to_fill[j + 1] = '\0';
}
char	**my_char1d_to_char2d(char *str, char *separators)
{
	int i = -1;
	int nb_words = count_words(str, separators);
	char **array = malloc((nb_words + 1) * sizeof(char*));

	if (array == NULL)
		return (NULL);
	while (++i < nb_words) {
		array[i] = malloc(word_size(str, separators, i) * sizeof(char));
		if (array[i] == NULL)
			return (NULL);
		fill_word(str, separators, i, array[i]);
	}
	array[i] = NULL;
	return (array);
}
*/
