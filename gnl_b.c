/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:25:32 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/24 20:06:41 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_rest(char *rest, char **line)
{
	char	*str;
	int		count;

	count = 0;
	*line = ft_fill_line(0, rest);
	if (rest[ft_strlen(*line) - 1] == '\n')
	{
		if (ft_strlen(*line) < ft_strlen(rest) - 1)
		{
			str = rest;
			ft_fill_rest(0, str, rest);
			return (2);
		}
		ft_bzero(rest, ft_strlen(rest));
		return (1);
	}
	ft_bzero(rest, ft_strlen(rest));
	return (0);
}

char	*ft_strdupcat(char *line, char *buff, char *rest)
{
	char	*res;
	int		len;
	int		count;

	count = 0;
	len = ft_strlen(line);
	if (!(res = malloc(sizeof(char) * (ft_strlen(buff) + len + 1))))
		return (NULL);
	len = 0;
	while (line[len])
	{
		res[len] = line[len];
		len++;
	}
	while (buff[count] && buff[count - 1] != '\n')
	{
		res[len] = buff[count];
		count++;
		len++;
	}
	ft_fill_rest(count, buff, rest);
	res[len] = '\0';
	return (res);
}

int		get_next_line(int fd, char **line)
{
	int			rd;
	char		*buff;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	printf("rest begin %s\n", rest);
	if (rest)
		if (ft_rest(rest, line))
			return (1);
	if (!rest && !(rest = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buff[BUFFER_SIZE] = 0;
	if (*line)
		ft_bzero(*line, ft_strlen(*line));
	while ((!ft_search_nl(*line)) && rd)
	{
		if (read(fd, buff, BUFFER_SIZE) < 1)
			rd = 0;
		else
			*line = ft_strdupcat(*line, buff, rest);
	}
	free(buff);
	printf("rest end %s\n", rest);
	if (!rd || !**line)
		return (0);
	return (1);
}