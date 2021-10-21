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
	initialize_game(t_game *game)
{
	t_image		image;

	image = (t_image){.img_ptr = NULL, .addr = NULL, .bits_per_pixel = 0, .line_length = 0, .endian = 0};
	(*game).win = NULL;
	(*game).image = image;

	game->mlx.mlx = NULL;
	game->mlx.window = NULL;
	game->mlx.img = NULL;

	game->head = NULL;
	game->lst = NULL;
	game->tmp = NULL;
	game->config = (t_config *)malloc(sizeof(t_config));
	game->config->width = 0; //
	game->config->height = 0; // initialize with?
	game->config->map = NULL;
	game->config->rows = 0;
	game->config->columns = 0;
	game->config->num_sprites = 0;
	game->config->max_len = 0;
	game->config->player_direction = 0;
	game->config->is_e = 0;
	game->config->is_c = 0;
	game->config->hit = 0;
	game->config->wall = NULL;
	game->config->space = NULL;
	game->config->is_p = 0;
	game->config->player = NULL;
	game->config->collect = NULL;
	game->config->exit = NULL;
	game->config->path_wall = "./textures/wall.xpm";
	game->config->path_space = "./textures/space.xpm";
	game->config->path_player = "./textures/player.xpm";
	game->config->path_collect = "./textures/collect.xpm";
	game->config->path_exit = "./textures/exit.xpm";
}
