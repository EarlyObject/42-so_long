/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:00:09 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 19:00:10 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	init_keys(t_game *game)
{
	game->keys.w = 0;
	game->keys.a = 0;
	game->keys.s = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

void
	init_img_pointers(t_game *game)
{
	game->config->player = NULL;
	game->config->player_f = NULL;
	game->config->player_b = NULL;
	game->config->player_l = NULL;
	game->config->player_r = NULL;
	game->config->collect = NULL;
	game->config->collect1 = NULL;
	game->config->collect2 = NULL;
	game->config->collect3 = NULL;
	game->config->exit = NULL;
	game->config->exit_open = NULL;
	game->config->path_wall = "./textures/wall.xpm";
	game->config->path_space = "./textures/space.xpm";
	game->config->path_player_f = "./textures/player_f.xpm";
	game->config->path_player_b = "./textures/player_b.xpm";
	game->config->path_player_l = "./textures/player_l.xpm";
	game->config->path_player_r = "./textures/player_r.xpm";
	game->config->path_collect1 = "./textures/collect1.xpm";
	game->config->path_collect2 = "./textures/collect2.xpm";
	game->config->path_collect3 = "./textures/collect3.xpm";
	game->config->path_exit = "./textures/exit.xpm";
	game->config->path_exit_open = "./textures/exit_open.xpm";
}

void
	init_config(t_game *game)
{
	game->config = (t_config *)malloc(sizeof(t_config));
	game->config->map = NULL;
	game->config->rows = 0;
	game->config->columns = 0;
	game->config->player_direction = 0;
	game->config->num_e = 0;
	game->config->num_c = 0;
	game->config->wall = NULL;
	game->config->space = NULL;
	game->config->num_p = 0;
	init_img_pointers(game);
}

void
	initialize_game(t_game *game)
{
	t_image		image;

	image = (t_image){.img_ptr = NULL, .addr = NULL, .bits_per_pixel = 0,
		.line_length = 0, .endian = 0};
	(*game).win = NULL;
	(*game).image = image;
	game->mlx.mlx = NULL;
	game->mlx.window = NULL;
	game->mlx.img = NULL;
	game->update_frame = true;
	game->head = NULL;
	game->lst = NULL;
	game->tmp = NULL;
	game->plr_x = 1;
	game->plr_y = 1;
	game->steps = 0;
	init_config(game);
}
