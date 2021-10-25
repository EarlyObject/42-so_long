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
	if (game->keys.w)
		move_up(game);
	if (game->keys.s)
		move_down(game);
	if (game->keys.a)
		move_left(game);
	if (game->keys.d)
		move_right(game);
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
