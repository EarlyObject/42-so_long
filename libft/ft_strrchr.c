/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:24:04 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/01 23:58:06 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate character in string (last occurence)
**
** DESCRIPTION:
** 		The strrchr() function locates the last occurrence of c (converted to a
**	char) in the string s.  If c is `\0', strrchr() locates the terminating
**	`\0'.
*/

#include "libft.h"

char
	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	len = ft_strlen(s);
	while (len >= 0)
	{
		p = (char *)s + len;
		if (*p == (char)c)
			return (p);
		len--;
	}
	return (NULL);
}
