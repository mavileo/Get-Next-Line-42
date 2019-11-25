/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_u_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:00:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/24 20:06:52 by mavileo          ###   ########.fr       */
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

char	*ft_fill_line(int count, char *buff)
{
	char	*line;

	if (!(line = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	line[count] = 0;
	count = 0;
	while (buff[count] && buff[count - 1] != '\n')
	{
		line[count] = buff[count];
		count++;
	}
	return (line);

}

void	ft_fill_rest(int count, char *buff, char *rest)
{
	int		c_rest;
	
	c_rest = 0;
	while (buff[count] && buff[count - 1] != '\n')
		count++;
	count--;
	while (buff[count])
		rest[c_rest++] = buff[++count];
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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;
	size_t			count;

	res = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*res++ = 0;
		count++;
	}
}
