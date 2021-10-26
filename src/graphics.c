/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:50:34 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/20 12:50:35 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int
	init_window(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		ft_exit_error("MLX_INIT ERROR.", -1);
	game->win = mlx_new_window(game->mlx.mlx, game->config->columns
			* TEXTURE_SIZE, game->config->rows * TEXTURE_SIZE, "so_long");
	if (!game->win)
		ft_exit_error("MLX_NEW_WINDOW ERROR.", -1);
	game->image.img_ptr = mlx_new_image(game->mlx.mlx, game->config->columns
			* TEXTURE_SIZE, game->config->rows * TEXTURE_SIZE);
	if (!game->image.img_ptr)
		ft_exit_error("MLX IMAGE ERROR.", -1);
	game->image.addr = (uint32_t *)mlx_get_data_addr(game->image.img_ptr,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
	return (1);
}

void
	get_plr_images(t_game *game, int *width, int *height)
{
	game->config->player_f = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_player_f, width, height);
	game->config->player_b = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_player_b, width, height);
	game->config->player_l = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_player_l, width, height);
	game->config->player_r = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_player_r, width, height);
}

void
	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = TEXTURE_SIZE;
	height = TEXTURE_SIZE;
	game->config->wall = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_wall, &width, &height);
	game->config->space = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_space, &width, &height);
	get_plr_images(game, &width, &height);
	game->config->collect1 = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_collect1, &width, &height);
	game->config->collect2 = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_collect2, &width, &height);
	game->config->collect3 = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_collect3, &width, &height);
	game->config->exit = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_exit, &width, &height);
	game->config->exit_open = mlx_xpm_file_to_image(game->mlx.mlx,
			game->config->path_exit_open, &width, &height);
}

void
	build_frame(t_game *game)
{
	int	i;
	int	j;

	draw_space(game);
	i = 0;
	while (i < game->config->columns)
	{
		j = 0;
		while (j < game->config->rows)
		{
			if (game->config->map[j][i] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->win,
					game->config->wall, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			else if (game->config->map[j][i] == 'P')
				draw_player(game, i, j);
			else if (game->config->map[j][i] == 'C')
				draw_collect(game, i, j);
			else if (game->config->map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->win,
					game->config->exit, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			j++;
		}
		i++;
	}
	mlx_do_sync(game->mlx.mlx);
}
