/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:10:36 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/05 10:36:40 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: delete element from list
**
** DESCRIPTION:
** 		Takes as a parameter an element and frees the memory of the element’s
**	content using the function ’del’ given as a parameter and free the element.
**	The memory of ’next’ must not be freed.
*/

#include "libft.h"

void
	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
