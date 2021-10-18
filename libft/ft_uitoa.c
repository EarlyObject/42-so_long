/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:44:26 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/15 19:44:31 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: convert unsigned integer to ASCII string
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns a string representing the
**	unsigned integer received as an argument.
*/

#include "libft.h"

static unsigned int
	count_ulen(unsigned int n)
{
	unsigned int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char
	*ft_uitoa(unsigned int n)
{
	char			*p;
	unsigned int	len;

	len = count_ulen(n);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	p[len] = '\0';
	while (len)
	{
		p[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (p);
}
