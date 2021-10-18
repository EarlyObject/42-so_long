/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:29:32 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/07 11:49:35 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: create new string from modifying string with specified function
**
** DESCRIPTION:
** 		Applies the function ’f’ to each character of the string ’s’ to create
**	a new string (with malloc(3)) resulting from successive applications of ’f’.
*/

#include "libft.h"

char
	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	int		i;

	copy = ft_strdup(s);
	if (!s || !copy)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		copy[i] = f(i, copy[i]);
		i++;
	}
	return (copy);
}
