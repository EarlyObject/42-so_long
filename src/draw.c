/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:23:12 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/25 10:23:13 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	draw_player(t_game *game, int i, int j)
{
	if (game->config->player_direction == 'l')
		game->config->player = game->config->player_l;
	else if (game->config->player_direction == 'r')
		game->config->player = game->config->player_r;
	else if (game->config->player_direction == 'u')
		game->config->player = game->config->player_b;
	else
		game->config->player = game->config->player_f;
	mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->player,
		i * TEXTURE_SIZE, j * TEXTURE_SIZE);
}

void
	draw_collect(t_game *game, int i, int j)
{
	if (i % 2 == 0)
	{
		if (j % 2 == 0)
			game->config->collect = game->config->collect1;
		else
			game->config->collect = game->config->collect2;
	}
	else
	{
		if (j % 2 == 0)
			game->config->collect = game->config->collect2;
		else
			game->config->collect = game->config->collect3;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->collect,
		i * TEXTURE_SIZE, j * TEXTURE_SIZE);
}

void
	draw_space(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->config->columns)
	{
		j = 0;
		while (j < game->config->rows)
		{
			mlx_put_image_to_window(game->mlx.mlx, game->win,
				game->config->space, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			j++;
		}
		i++;
	}
}
