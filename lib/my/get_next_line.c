/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** get_next_line
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../../include/my.h"

char	*should_skip(char *buffer)
{
	char *skip = malloc(sizeof(char) * READ_SIZE + 1);
	int i = 0;
	int k = 0;

	if (buffer[0] == 0) {
		free(skip);
		return (NULL);
	}
	while (skip && buffer[i++] != 10 && i != READ_SIZE);
	if (skip && i != READ_SIZE) {
		for (int j = 0; j != i; j++)
			skip[j] = buffer[j];
		skip[i - 1] = 0;
		for (int m = i; m != READ_SIZE; m++, k++)
			buffer[k] = buffer[m];
		buffer[k] = 0;
		return (skip);
	}
	return (NULL);
}

int	check_buffer(char *buffer, int rd)
{
	if (rd == 1) {
		if (READ_SIZE <= 0)
			exit(84);
		else
			return (READ_SIZE);
	}
	for (int i = 0; i != READ_SIZE; i++) {
		if (buffer[i] == 10)
			return (i);
	}
	return (-1);
}

char	*new_buffer(char *line, char *buffer, int i)
{
	char boffer[READ_SIZE + 1] = "\0";
	int m = i + 1;
	int k = 0;
	int j = 0;

	i = i == -1 ? 0 : i;
	for (; buffer[j] != 10; j++)
		boffer[j] = buffer[j];
	boffer[j] = 0;
	line = my_strcat(line, boffer, 1);
	for (; m != READ_SIZE; m++, k++)
		buffer[k] = buffer[m];
	buffer[k] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1] = "\0";
	char *line = should_skip(buffer);

	if (line)
		return (line);
	line = my_strcat(NULL, buffer, 0);
	while (read(fd, buffer, READ_SIZE)) {
		if (!line)
			return (NULL);
		if (check_buffer(buffer, 0) == -1)
			line = my_strcat(line, buffer, 1);
		else {
			line = ADD_BUF;
			return (line);
		}
	}
	return (NULL);
}
