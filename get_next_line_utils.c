/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:48:16 by lbard             #+#    #+#             */
/*   Updated: 2024/11/25 21:55:24 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	s2 = malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	while (j < i)
	{
		s2[j] = s[j];
		j++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	char	*str;

	i = 0;
	j = 0;
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	str = malloc(len1 + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*newlen;
	unsigned int	str_len;

	i = 0;
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if ((start + len) > str_len)
		len = str_len - start;
	newlen = malloc(len + 1);
	if (newlen == NULL)
		return (NULL);
	while (i < len)
	{
		newlen[i] = s[start];
		i++;
		start++;
	}
	newlen[i] = '\0';
	return (newlen);
}
