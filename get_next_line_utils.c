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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		all_len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	all_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((all_len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str, s1, all_len + 1);
	ft_strlcat(str, s2, all_len + 1);
	return (str);
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

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}