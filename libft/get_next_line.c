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

int	get_next_line(int fd, char **line)
{
	int			n;
	char		buf[BUFFER_SIZE + (n = 1)];
	static char	*rdline = NULL;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rdline == NULL ? rdline = ft_make_str(0) : NULL;
	while (!ft_strchr(rdline, '\n') && (n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		temp = ft_strjoin(rdline, buf);
		free_mem((void **)&rdline);
		rdline = temp;
	}
	if (n < 0)
		return (-1);
	*line = (n == 0) ? ft_strdup(rdline) : ft_substr(rdline, 0, (ft_strchr(rdline, '\n') - rdline));
	temp = ft_strdup(rdline + (ft_strlen(*line) + ((n > 0) ? +1 : +0)));
	free_mem((void **)&rdline);
	rdline = temp;
	if (n == 0)
		free_mem((void **)&rdline);
	return (n == 0) ? 0 : 1;
}

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
