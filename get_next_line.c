/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/11/18 22:32:59 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	i;
	size_t	b;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	while ((b = read(fd, buffer, 5)) > 0)
	{
		if (ft_newline(buffer))
			printf("%s\n", buffer);
		i++;
	}
	free(buffer);
}

int main()
{
	int fd =  open("test.txt", O_RDONLY);
	get_next_line(fd);
	return 0;
}