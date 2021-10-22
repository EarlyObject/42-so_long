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
//	void	*mlx;
//	void	*win;

	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		ft_exit_error(game, "MLX_INIT ERROR.", -1);//check
	game->win = mlx_new_window(game->mlx.mlx, game->config->columns * TEXTURE_SIZE, game->config->rows * TEXTURE_SIZE, "so_long");
	if (!game->win)
		ft_exit_error(game, "MLX_NEW_WINDOW ERROR.", -1); //check
	game->image.img_ptr = mlx_new_image(game->mlx.mlx, game->config->columns * TEXTURE_SIZE, game->config->rows * TEXTURE_SIZE); //check
	if (!game->image.img_ptr)
		ft_exit_error(game, "MLX IMAGE ERROR.", -1); //check
	game->image.addr = (uint32_t *)mlx_get_data_addr(game->image.img_ptr,
													 &game->image.bits_per_pixel, &game->image.line_length,
													 &game->image.endian);
	return (1);
}

void
	build_frame(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->config->columns)
	{
		j = 0;
		while (j < game->config->rows)
		{
			mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->space, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->config->columns)
	{
		j = 0;
		while (j < game->config->rows)
		{
			if (game->config->map[j][i] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->wall, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			else if (game->config->map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->player, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			else if (game->config->map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->collect, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			else if (game->config->map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->win, game->config->exit, i * TEXTURE_SIZE, j * TEXTURE_SIZE);
			j++;
		}
		i++;
	}
	mlx_do_sync(game->mlx.mlx);
}

void
	load_textures(t_game *game) //check if correct to put absolute image sizes
{
	int	tile_width;
	int	tile_height;

	tile_width = TEXTURE_SIZE;
	tile_height = TEXTURE_SIZE;
	game->config->wall = mlx_xpm_file_to_image(game->mlx.mlx, game->config->path_wall, &tile_width, &tile_height);
	game->config->space = mlx_xpm_file_to_image(game->mlx.mlx, game->config->path_space, &tile_width, &tile_height);
	game->config->player = mlx_xpm_file_to_image(game->mlx.mlx, game->config->path_player, &tile_width, &tile_height);
	game->config->collect = mlx_xpm_file_to_image(game->mlx.mlx, game->config->path_collect, &tile_width, &tile_height);
	game->config->exit = mlx_xpm_file_to_image(game->mlx.mlx, game->config->path_exit, &tile_width, &tile_height);
	game->config->exit_open = mlx_xpm_file_to_image(game->mlx.mlx, game->config->path_exit_open, &tile_width, &tile_height);

}
