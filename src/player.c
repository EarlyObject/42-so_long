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
	change_plr_position(t_game *game, int step_y, int step_x)
{
	if (step_x < game->plr_x)
		game->plr_x -= 1;
	else if (step_x > game->plr_x)
		game->plr_x += 1;
	else if (step_y < game->plr_y)
		game->plr_y -= 1;
	else if (step_y > game->plr_y)
		game->plr_y += 1;
}

void
	make_step(t_game *game, char next_step, int step_y, int step_x)
{
	if (next_step != 'E')
	{
		if (game->config->num_c > 0 && next_step == 'C')
		{
			game->config->num_c -= 1;
			if (!game->config->num_c)
				game->config->exit = game->config->exit_open;
		}
		game->config->map[game->plr_y][game->plr_x] = '0';
		game->config->map[step_y][step_x] = 'P';
		change_plr_position(game, step_y, step_x);
		game->steps += 1;
		print_steps(game);
		game->update_frame = true;
	}
	else
	{
		if (game->config->num_c == 0)
		{
			game->steps += 1;
			finish_game(game);
		}
	}
}

void
	finish_game(t_game *game)
{
	game->config->map[game->plr_y][game->plr_x] = '0';
	print_steps(game);
	build_frame(game);
	exit_game(EXIT_SUCCESS);
}
