/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:23:11 by lbard             #+#    #+#             */
/*   Updated: 2024/11/16 19:22:06 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 128

//char	*get_next_line(int fd)
int main()
{
	int	fd;
	char	buffer[BUFFER_SIZE];
	ssize_t b;

	fd = open("test.txt", O_RDONLY);
	while ((b = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if ()
			write(STDOUT_FILENO, buffer, b);
	}
	close(fd);
	return 0;
}

