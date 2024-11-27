/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/11/27 03:29:22 by lbard            ###   ########.fr       */
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
		if (ft_strchr(buffer, '\n'))
			break ;
		b = (int)read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (saved);
}

static char	*extract_line(char *saved)
{
	char		*line;
	char		*newline_pos;
	static int	start = 0;

	if (!saved || saved[start] == '\0')
		return (NULL);
	newline_pos = ft_strchr(saved + start, '\n');
	if (newline_pos)
		line = ft_substr(saved, start, newline_pos - (saved + start) + 1);
	else
		line = ft_substr(saved, start, ft_strlen(saved + start));
	if (!line)
		return (NULL);
	start += ft_strlen(line);
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
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("42ln.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s\n", line);
		free(line);
	}
	close(fd);
	fd = open("42.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s", line);
		free(line);
	}
	close(fd);
	fd = open("43ln.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
