/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/11/25 21:55:23 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_accumulate(int fd, char *saved)
{
	char	*tmp;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (saved == NULL)
    	saved = ft_strdup("");
	while ((read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		tmp = saved;
		saved = ft_strjoin(saved, buffer);
		free(tmp);
	}
	free(buffer);
	if (fd == -1)
		return (NULL);
	return (saved);
}

static char	*extract_line(char *saved)
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
		free(saved);
		saved = (NULL);
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
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	line = extract_line(saved);
	return (line);
}

/*int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("LINE COPIED \n");
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}*/