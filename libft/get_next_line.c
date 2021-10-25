/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:40:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 18:02:28 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	free_mem(void **p)
{
	if (*p)
	{
		ft_memset(*p, 0, ft_strlen(*p));
		free(*p);
		*p = NULL;
	}
}

void
	read_lines(int fd, char *buf, t_gnl *gnl, char **rdline)
{
	while (!ft_strchr((*rdline), '\n'))
	{
		(*gnl).n = read(fd, buf, BUFFER_SIZE);
		if ((*gnl).n <= 0)
			break ;
		buf[(*gnl).n] = '\0';
		(*gnl).temp = ft_strjoin((*rdline), buf);
		free_mem((void **) rdline);
		(*rdline) = (*gnl).temp;
	}
}

int
	gnl_cont(t_gnl *gnl, char **rdline)
{
	free_mem((void **) rdline);
	(*rdline) = (*gnl).temp;
	if ((*gnl).n == 0)
		free_mem((void **) rdline);
	if ((*gnl).n == 0)
		return (0);
	else
		return (1);
}

int
	get_next_line(int fd, char **line)
{
	t_gnl		gnl;
	char		buf[BUFFER_SIZE + 1];
	static char	*rdline = NULL;

	gnl.n = 1;
	gnl.temp = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (rdline == NULL)
		rdline = ft_make_str(0);
	else
		NULL;
	read_lines(fd, buf, &gnl, &rdline);
	if (gnl.n < 0)
		return (-1);
	if (gnl.n == 0)
		*line = ft_strdup(rdline);
	else
		*line = ft_substr(rdline, 0, (ft_strchr(rdline, '\n') - rdline));
	if (gnl.n > 0)
		gnl.temp = ft_strdup(rdline + (ft_strlen(*line) + +1));
	else
		gnl.temp = ft_strdup(rdline + (ft_strlen(*line) + +0));
	return (gnl_cont(&gnl, &rdline));
}
