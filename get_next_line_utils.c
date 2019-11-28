/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:00:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/28 01:03:15 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int count;

	count = 0;
	if (!s)
		return (0);
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
	while (buff[count] && buff[count] != '\n')
		count++;
	if (buff[count] == '\n')
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

char	*ft_strjoin(char *s1, char *s2, char *rest, int begin)
{
	char	*res;
	int		len;
	int		count;

	count = 0;
	len = 0;
	if (s1 && !begin)
		len = ft_strlen(s1);
	if (!(res = malloc(sizeof(char) * (BUFFER_SIZE + len + 1))))
		return (NULL);
	len = 0;
	if (s1 && !begin)
	{
		while (s1[count])
			res[len++] = s1[count++];
		free(s1);
	}
	count = 0;
	if (s2)
		while (s2[count] && s2[count] != '\n')
			res[len++] = s2[count++];
	res[len] = 0;
	if (s2)
		ft_fill_rest(s2, rest);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;
	size_t			count;

	if (!s || n < 1)
		return ;
	res = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*res++ = 0;
		count++;
	}
}
