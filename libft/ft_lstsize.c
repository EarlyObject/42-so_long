/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:18:22 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/08 09:44:25 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: count elements of a list
**
** DESCRIPTION:
** 		Counts the number of elements in a list.
*/

#include "libft.h"

int
	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
