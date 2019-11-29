/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:50:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/29 04:52:16 by mavileo          ###   ########.fr       */
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

int		ft_len_line(const char *stock)
{
	int i;

	i = 0;
	while (stock && stock[i] && stock[i] != '\n')
		i++;
	return (i);
}

char	*ft_loop(char *stock, int ret, int fd, char *buffer)
{
	while (!ft_strchr(stock, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buffer[ret] = '\0';
		if (!(stock = ft_strjoin_free(stock, buffer, 1)))
			return (NULL);
	}
	return (stock);
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
	if ((stock = ft_loop(stock, ret, fd, buffer)) == NULL)
		return (-1);
	free(buffer);
	i = ft_len_line(stock);
	tmp = stock;
	*line = ft_substr(stock, 0, i);
	if (stock[i] == '\n')
		stock = ft_strdup(stock + i + 1);
	else
		stock = NULL;
	if (tmp)
		free(tmp);
	return (((stock == NULL) && !ret && !ft_strlen(*line)) ? 0 : 1);
}
