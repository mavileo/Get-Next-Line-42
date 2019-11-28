/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:50:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/28 20:37:16 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*res;
	size_t			count;

	res = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*res++ = c;
		count++;
	}
	return (s);
}

void	*ft_calloc(size_t nb, size_t size)
{
	unsigned char *res;

	if (!(res = malloc(size * nb)))
		return (NULL);
	ft_memset(res, 0, nb * size);
	return (res);
}

int		ft_i(char *stock)
{
	int count;

	count = 0;
	while (stock && stock[count] && stock[count] != '\n')
		count++;
	return (count);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	int			ret;
	int			i;
	char		*tmp;
	char		*buffer;

	if (fd < 0 || !line || !(buffer = (char *)malloc(sizeof(char) *
	(BUFFER_SIZE + 1))))
		return (-1);
	if (!stock)
		stock = ft_calloc(1, 1);
	while (!ft_strchr(stock, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		stock = ft_strjoin_free(stock, buffer, 1);
	}
	free(buffer);
	i = ft_i(stock);
	tmp = stock;
	*line = ft_substr(stock, 0, i);
	stock = ft_strdup(stock + i + 1);
	free(tmp);
	if (ret || ft_strlen(stock) || ft_strlen(*line))
		return (1);
	return (0);
}
