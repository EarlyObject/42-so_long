/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:52:01 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 18:52:02 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int
	exit_game(t_game *game, int code)
{
	clear_window(game);
	exit(code);
}

int
	clear_window(t_game *game)
{
	if (game->image.img_ptr)
		mlx_destroy_image(game->mlx.mlx, game->image.img_ptr);
	if (game->mlx.mlx && game->win)
		mlx_destroy_window(game->mlx.mlx, game->win);
	return (0);
}

void
	clear_textures(t_game *game)
{
	printf("%d\n", game->image.bits_per_pixel);
	/*int	i;

	i = 0;
	while (i < TEXTURES)
	{
		if (game->config->wallTexture[i] != NULL)
			mlx_destroy_image(game->mlx.mlx,
							  game->config->wallTexture[i]->img_ptr);
		i++;
	}
	while (i < TEXTURES)
	{
		if (game->config->wallTexture[i] != NULL)
			free(game->config->wallTexture[i]);
		i++;
	}*/
}
