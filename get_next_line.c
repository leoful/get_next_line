/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/11/26 22:31:48 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_accumulate(int fd, char *saved)
{
	char	*tmp;
	char	*buffer;
	int		b;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	b = (int)read(fd, buffer, BUFFER_SIZE);
	while (b > 0)
	{
		buffer[b] = '\0';
		tmp = ft_strjoin(saved, buffer);
		if (!tmp)
			return (NULL);
		free(saved);
		saved = tmp;
		b = (int)read(fd, buffer, BUFFER_SIZE);
	}
	buffer[0] = '\0';
	free(buffer);
	return (saved);
}

static char	*extract_line(char *saved)
{
	char		*line;
	static int	start = 0;
	int			end;

	if (!saved || saved[start] == '\0')
		return (NULL);
	end = 0;
	while (saved[start + end] != '\0' && saved[start + end] != '\n')
		end++;
	if (saved[start + end] == '\n')
		end++;
	line = ft_substr(saved, start, end);
	if (!line)
		return (NULL);
	start += end;
	if (saved[start] == '\0')
	{
		start = 0;
		saved[0] = '\0';
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
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	if (saved && saved[0] == '\0')
	{
		free(saved);
		saved = NULL;
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("onechar.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s\n", line);
		free(line);
	}
	close(fd);
	fd = open("empty.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s", line);
		free(line);
	}
	close(fd);
	fd = open("lines.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
