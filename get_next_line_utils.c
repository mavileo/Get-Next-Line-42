/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:00:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/25 10:03:02 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
int		ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	ft_fill_rest(char *buff, char *rest)
{
	int		c_rest;
	int		count;

	count = 0;
	c_rest = 0;
	while (buff[count] && buff[count - 1] != '\n')
		count++;
	while (buff[count])
		rest[c_rest++] = buff[count++];
	rest[c_rest] = 0;
}

int		ft_search_nl(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\n' && str[count])
		count++;
	if (str[count] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, char *rest)
{
	char	*res;
	int		len;
	int		count;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	count = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = malloc(sizeof(char) * len)))
		return (NULL);
	len = 0;
	while (s1[count])
		res[len++] = s1[count++];
	count = 0;
	while (s2[count] && s2[count] != '\n')
		res[len++] = s2[count++];
	res[len] = 0;
	ft_fill_rest(s2, rest);
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		count;

	count = 0;
	if (!(res = malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[count])
	{
		res[count] = s[count];
		count++;
	}
	res[count] = 0;
	return (res);
}
