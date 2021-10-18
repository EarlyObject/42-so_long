/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:55:06 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 12:01:01 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: add new element at beginning of list
**
** DESCRIPTION:
** 		Adds the element ’new’ at the beginning of the list.
*/

#include "libft.h"

void
	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (alst)
	{
		if (*alst)
			new->next = *alst;
	}
	*alst = new;
}
