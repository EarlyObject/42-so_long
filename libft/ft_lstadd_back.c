/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:28:17 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/05 10:07:35 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: add new element at end of list
**
** DESCRIPTION:
** 		Adds the element ’new’ at the end of the list.
*/

#include "libft.h"

void
	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		new->next = NULL;
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
