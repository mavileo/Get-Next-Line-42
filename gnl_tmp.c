/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:25:32 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/23 00:30:14 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line(int count, char *buff)
{
	char	*line;

	if (!(line = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	line[count] = 0;
	count = 0;
	while (buff[count] && buff[count] != '\n')
	{
		line[count] = buff[count];
		count++;
	}
	return (line);

}

char	*ft_fill_rest(int count, char *buff)
{
	char	*rest;
	int		c_rest;
	
	c_rest = 0;
	while (buff[count] && buff[count] != '\n')
		count++;
	if (!(rest = malloc(sizeof(char) * (BUFFER_SIZE - count + 1))))
		return (NULL);
	while (buff[count])
		rest[c_rest++] = buff[++count];
	rest[c_rest] = 0;
	return (rest);
}

char	*ft_search_nl(int fd, char **line, char *buff)
{
	if 
	
}

int		get_next_line(int fd, char **line)
{
	int			count;
	char		*buff;
	static char	*rest;
	count = 0;
	if (rest)
	{
		*line = ft_fill_line(count, rest);
		rest = ft_fill_rest(count, buff);
	}
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buff[BUFFER_SIZE] = 0;
	while ()
	if (read(fd, buff, BUFFER_SIZE) < 1)
	{
		free(buff);
		return (0);
	}
	while (buff[count] != '\n' && buff[count])
		count++;
	*line = ft_fill_line(count, buff);
	rest = ft_fill_rest(count, buff);
	free(buff);
	if (*line || rest)
		return (1);
	return (-1);
}
