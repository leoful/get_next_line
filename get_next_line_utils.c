/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:48:16 by lbard             #+#    #+#             */
/*   Updated: 2024/11/18 18:48:16 by lbard            ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	i = ft_strlen(dest);
	j = 0;
	len_src = ft_strlen(src);
	if (n <= i)
	{
		return (n + len_src);
	}
	while (src[j] && n > (i + j + 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + len_src);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		all_len;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		str = malloc(ft_strlen(s2) + 1);
		ft_strlcpy(str, s2, ft_strlen(s2) + 1);
		return (str);
	}
	all_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((all_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, all_len + 1);
	ft_strlcat(str, s2, all_len + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *newlen;
	unsigned int str_len;

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