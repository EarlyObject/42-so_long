/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:42:35 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 18:42:36 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	check_mem_alloc(void *p)
{
	if (p == NULL)
		ft_exit_error("Memory is not allocated", 2 );
}

t_d_list
	*ft_my_lstnew(void *content, t_d_list **prev)
{
	t_d_list	*new;

	new = malloc(sizeof(t_d_list));
	if (!new)
		return (NULL);
	new->content = content;
	if (prev)
		new->previous = *prev;
	else
		new->previous = NULL;
	new->next = NULL;
	return (new);
}

void
	print_steps(const t_game *game)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd((int)game->steps, 1);
	ft_putendl_fd("", 1);
}
