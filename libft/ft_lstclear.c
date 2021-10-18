/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:37:06 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/05 12:01:12 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: delete sequence of elements of list from a starting point
**
** DESCRIPTION:
** 		Deletes and frees the given element and every successor of that element,
**	using the function ’del’ and free(3). Finally, the pointer to the list must
**	be set to NULL.
*/

#include "libft.h"

void
	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
