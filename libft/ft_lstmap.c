/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:54:22 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/07 17:20:16 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: apply function to content of all list's elements into new list
**
** DESCRIPTION:
** 		Iterates the list ’lst’ and applies the function ’f’ to the content of
**	each element. Creates a new list resulting of the successive applications of
**	the function ’f’. The ’del’ function is used to delete the content of an
**	element if needed.
*/

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = ft_lstnew((*f)(lst->content));
	if (!temp)
		return (NULL);
	first = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = ft_lstnew((*f)(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (first);
}
