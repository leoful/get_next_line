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
	char	*buffer;
	size_t	bytes;
	int	i = 0;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	while ((bytes = read(fd, buffer, 5)) > 0)
	{
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	return (saved);
}

//char	*extract_line(char *saved)

/*char	*get_next_line(int fd)
{
	char	*buffer;
	int	i;
	size_t	b;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	while ((b = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		while (i < b)
		{
			if (buffer[i] == '\n')
			{
				printf("%s", buffer);
			}
			i++;
		}
	}
	free(buffer);
}
*/
int main()
{
	static char *saved = NULL;
	int fd =  open("test.txt", O_RDONLY);
	read_and_accumulate(fd, saved);
	return 0;
}