/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/11/19 20:30:48 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

char	*read_and_accumulate(int fd, char *saved)
{
	char	*tmp;
	char	*buffer;
	size_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		tmp = saved;
		saved = ft_strjoin(saved, buffer);
		free(tmp);
		printf("Accumulating data: %s\n", saved);
	}
	free(buffer);
	if (bytes == -1)
	{
		perror("Read error");
		return (NULL);
	}
	if (bytes == 0)
		printf("End of file reached.\n"); // Fin du fichier
	return (saved);
}

char	*extract_line(char *saved)
{
	char		*line;
	int			newline;
	static int	start = 0;

	newline = ft_strchr(saved + start, '\n') - (saved + start);
	if (newline >= 0)
	{
		line = ft_substr(saved, start, newline + 1);
		start = start + newline + 1;
	}
	else
	{
		line = ft_strdup(saved + start);
		start = ft_strlen(saved);
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_accumulate(fd, saved);
	if (saved == NULL || saved[0] == '\0')
		free(saved);
	saved = NULL;
	return (NULL);
	line = extract_line(saved);
	if (line == NULL)
	{
		free(saved);
		saved = NULL;
	}
	return (line);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}

	// Appeler get_next_line pour obtenir la première ligne
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Imprimer chaque ligne
		free(line);         // Libérer la mémoire allouée pour chaque ligne
	}

	close(fd); // Ne pas oublier de fermer le fichier
	return (0);
}