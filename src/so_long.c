/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:46:27 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 12:46:28 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	my_leaks(void)
{
	system("leaks so_long");
}

int
	main_loop(t_game *game)
{
	if (!game->keys.w && !game->keys.s && !game->keys.a && \
		!game->keys.d && !game->keys.right && !game->keys.left)
	{
		build_frame(game);
		return (0);
	}
	move_player(game);
	if (game->update_frame)
		build_frame(game);
	game->update_frame = false;
	return (0);
}

void
	ft_run(t_game game)
{
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, release_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, close_win, &game);
	mlx_loop_hook(game.mlx.mlx, main_loop, &game);
	mlx_loop(game.mlx.mlx);
}

int
	main(int argc, char *argv[])
{
	t_game	game;

	if (argc < 2)
		ft_exit_error("No map provided", 0);
	else if (argc > 2)
	{
		ft_putendl_fd("Warning", 2);
		ft_putendl_fd("Too many arguments. Only the first one will be used", 2);
	}
	initialize_game(&game);
	parse_args(argv[1]);
	read_map(open(argv[1], O_RDONLY), &game);
	parse_map(&game);
	create_map(&game);
	game.tmp = game.head;
	game.lst = game.head;
	init_keys(&game);
	init_window(&game);
	load_textures(&game);
	ft_run(game);
	return (EXIT_SUCCESS);
}
