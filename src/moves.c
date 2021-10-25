/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:53:44 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/25 10:53:45 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	move_left(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y][game->plr_x - 1];
	if (next_step != '1')
	{
		game->config->player_direction = 'l';
		make_step(game, next_step, game->plr_y, game->plr_x - 1);
	}
	game->keys.a = false;
}

void
	move_right(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y][game->plr_x + 1];
	if (next_step != '1')
	{
		game->config->player_direction = 'r';
		make_step(game, next_step, game->plr_y, game->plr_x + 1);
	}
	game->keys.d = false;
}

void
	move_up(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y - 1][game->plr_x];
	if (next_step != '1')
	{
		game->config->player_direction = 'u';
		make_step(game, next_step, game->plr_y - 1, game->plr_x);
	}
	game->keys.w = false;
}

void
	move_down(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y + 1][game->plr_x];
	if (next_step != '1')
	{
		game->config->player_direction = 'd';
		make_step(game, next_step, game->plr_y + 1, game->plr_x);
	}
	game->keys.s = false;
}
