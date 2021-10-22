/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:42:26 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/21 18:42:27 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	finish_game(t_game *game)
{
	game->config->map[game->plr_y][game->plr_x] = '0';
	exit_game(game, EXIT_SUCCESS);
}

void
	make_step(t_game *game, char next_step, int step_y, int step_x)
{
	if (next_step != 'E')
	{
		if (game->config->num_c > 0 && next_step == 'C')
			game->config->num_c -= 1;
		game->config->map[game->plr_y][game->plr_x] = '0';
		game->config->map[step_y][step_x] = 'P';
		if (step_x < game->plr_x)
			game->plr_x -= 1;
		else if (step_x > game->plr_x)
			game->plr_x += 1;
		else if (step_y < game->plr_y)
			game->plr_y -= 1;
		else if (step_y > game->plr_y)
			game->plr_y += 1;
	}
	else
	{
		if (game->config->num_c == 0)
			finish_game(game);
	}
}

void
	move_left(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y][game->plr_x - 1];
	if (next_step != '1')
	{
		make_step(game, next_step, game->plr_y, game->plr_x - 1);
	}
}

void
	move_right(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y][game->plr_x + 1];
	if (next_step != '1')
	{
		make_step(game, next_step, game->plr_y, game->plr_x + 1);
	}
}

void
	move_up(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y - 1][game->plr_x];
	if (next_step != '1')
	{
		make_step(game, next_step, game->plr_y - 1, game->plr_x);
	}
}

void
	move_down(t_game *game)
{
	char	next_step;

	next_step = game->config->map[game->plr_y + 1][game->plr_x];
	if (next_step != '1')
	{
		make_step(game, next_step, game->plr_y + 1, game->plr_x);
	}
}
