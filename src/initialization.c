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

int
	init_window(t_game *game)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		ft_exit_error(game, "MLX_INIT ERROR.", -1);//check
	win = mlx_new_window(mlx, 100,
						 100, "so_long");
	if (!win)
		ft_exit_error(game, "MLX_NEW_WINDOW ERROR.", -1);//check
	game->mlx.mlx = mlx;
	game->win = win;
	game->image.img_ptr = mlx_new_image(mlx, 100,100);//check
	if (!game->image.img_ptr)
		ft_exit_error(game, "MLX IMAGE ERROR.", -1);//check
	game->image.addr = (uint32_t *)mlx_get_data_addr(game->image.img_ptr,
													 &game->image.bits_per_pixel, &game->image.line_length,
													 &game->image.endian);
	return (1);
}

void
	initialize_game(t_game *game)
{
	init_keys(game);
	init_window(game);
}
