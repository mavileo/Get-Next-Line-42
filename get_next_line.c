/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:25:32 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/25 09:11:34 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		ft_rest(char *rest, char *line)
{
	int count;

	count = 0;
	while (rest[count] && rest[count] != '\n')
	{
		line[count] = rest[count];
		count++;
	}
	line[count] = 0;
	if (rest[count] == '\n')
	{
		if (rest[count] == 0 || rest[count + 1] == 0)
			ft_bzero(rest, ft_strlen(rest));
		else
			ft_fill_rest(rest, rest);
		return (1);
	}
	ft_bzero(rest, ft_strlen(rest));
	return (0);
}

int		ft_loop(int fd, char **line, char *rest)
{
	char		*buff;
	int rd;
	int eof;

	rd = 1;
	eof = 0;
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buff[BUFFER_SIZE] = 0;
	while (!ft_search_nl(buff) && !eof)
	{
		ft_bzero(buff, ft_strlen(buff));
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < BUFFER_SIZE)
			eof++;
		*line = ft_strjoin(*line, buff, rest);
	}
	free(buff);
	if (eof && !*rest)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (rest && *rest)
	{
		if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return(-1);
		if (ft_rest(rest, *line))
			return (1);
	}
	else
		ft_bzero(*line, ft_strlen(*line));
	if (!rest && !(rest = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	return (ft_loop(fd, line, rest));
}