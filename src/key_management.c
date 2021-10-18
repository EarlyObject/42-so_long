/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:17:05 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 13:17:06 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	move_player(t_game *game)
{
	game->image.addr = NULL;
	//double	oldDirX;
	//double	oldPlaneX;

	/*if (game->keys.left)
	{
		oldDirX = game->plr.dirX;
		oldPlaneX = game->screen.planeX;
		look_left(game, oldDirX, oldPlaneX);
	}
	if (game->keys.right)
	{
		oldDirX = game->plr.dirX;
		oldPlaneX = game->screen.planeX;
		look_right(game, oldDirX, oldPlaneX);
	}
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		move_left(game);
	if (game->keys.d)
		move_right(game);*/
}

int
	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		game->keys.w = true;
	if (key_code == KEY_S)
		game->keys.s = true;
	if (key_code == KEY_D)
		game->keys.d = true;
	if (key_code == KEY_A)
		game->keys.a = true;
	if (key_code == KEY_RIGHT)
		game->keys.right = true;
	if (key_code == KEY_LEFT)
		game->keys.left = true;
	return (0);
}

int
	release_key(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->keys.w = false;
	if (key_code == KEY_S)
		game->keys.s = false;
	if (key_code == KEY_D)
		game->keys.d = false;
	if (key_code == KEY_A)
		game->keys.a = false;
	if (key_code == KEY_RIGHT)
		game->keys.right = false;
	if (key_code == KEY_LEFT)
		game->keys.left = false;
	return (0);
}

int
	close_win(void)
{
	exit(0);
}

/*
void
	move_backward(t_game *cub3d)
{
	*/
/*int	mx_x;
	int	mx_y;
	int	my_x;
	int	my_y;

	mx_x = (int)(cub3d->plr.posX - cub3d->plr.dirX * MOVE_SPEED);
	mx_y = (int)(cub3d->plr.posY);
	my_x = (int)(cub3d->plr.posX);
	my_y = (int)(cub3d->plr.posY - cub3d->plr.dirY * MOVE_SPEED);
	if (cub3d->config->map[mx_x + mx_y * cub3d->config->max_len] != '1')
		cub3d->plr.posX -= cub3d->plr.dirX * MOVE_SPEED;
	if (cub3d->config->map[my_x + my_y * cub3d->config->max_len] != '1')
		cub3d->plr.posY -= cub3d->plr.dirY * MOVE_SPEED;*//*

}*/
