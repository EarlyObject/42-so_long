/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:38:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/03/29 11:38:32 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** 		Reserves sufficient memory for creating null-terminated char array of
** size received as argument and returns the pointer to that array.
*/

#include "libft.h"

char
	*ft_make_str(size_t size)
{
	char	*p;

	p = ft_calloc(size + 1, sizeof(char *));
	ft_memset(p, 0, size + 1);
	return (p);
}
