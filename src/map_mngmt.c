/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mngmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:05:17 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/20 13:05:18 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool
	is_valid_map_bit(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

void
	create_map(t_game *game)
{
	int	i;
	int	rows;

	check_mem_alloc(game->config->map = (char **)malloc(
			game->config->rows * (sizeof(char *))));
	i = 0;
	rows = game->config->rows;
	while (i < rows)
	{
		check_mem_alloc(game->config->map[i] = (char *)malloc(
				(game->config->columns + 1) * sizeof(char)));
		i++;
	}
	game->lst = game->head;
	i = 0;
	while (i < rows)
	{
		ft_strlcpy(game->config->map[i], game->lst->content,
			game->config->columns + 1);
		i++;
		game->lst = game->lst->next;
	}
	if (game->lst)
		ft_exit_error("Error in map calculus", 0);
}
