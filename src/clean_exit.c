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

void
	free_list(t_d_list *list)
{
	t_d_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}

int
	exit_game(t_game *game, int code)
{
	clear_window(game);
	ft_free_2d_arr((void **)game->config->map);
	free(game->config);
	free_list(game->head);
	clear_textures(game);
	free(game);
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
	//залить текстуры в массив и очищать разом
	printf("%d\n", game->image.bits_per_pixel);
	//int	i;

	if (game->config->wall != NULL)
		mlx_destroy_image(game->mlx.mlx, game->config->wall);
	if (game->config->player != NULL)
		mlx_destroy_image(game->mlx.mlx, game->config->player);

	/*while (i < TEXTURES)
	{
		if (game->config->wallTexture[i] != NULL)
			free(game->config->wallTexture[i]);
		i++;
	}*/
}
