/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:00:17 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/26 21:47:42 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
void	ft_fill_rest(char *buff, char *rest);
int		ft_search_nl(char *str);
char	*ft_strjoin(char *s1, char *s2, char *rest);
char	*ft_strdup(char *s, char *rest);
void	ft_bzero(void *s, size_t n);

#endif
