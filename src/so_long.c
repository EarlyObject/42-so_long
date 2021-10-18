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

void
	ft_exit_error(t_game *game, char *msg, int err_num)
{
	perror("Error");
	perror(msg);
	exit_game(game, err_num);
	exit(err_num);
}

void
	build_frame(t_game *game)
{
	//draw_sprites(game);
	mlx_put_image_to_window(
			game->mlx.mlx, game->win, game->image.img_ptr, 0, 0);
	mlx_do_sync(game->mlx.mlx);
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
	build_frame(game);
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
	t_game	*game;

	if (argc < 2)
		ft_exit_error(NULL, "No map provided", 0);
	else if (argc > 2)
	{
		perror("Warning");
		perror(("More than 1 arguments provided. Only first will be used"));
	}
	game = (t_game *)malloc(sizeof(game));
	initialize_game(game);
	parse_args(game, argv[1]);
	parse_map(open(argv[1], O_RDONLY), game);
	ft_run(*game);
	printf("This is %s\n", argv[0]);
	return (EXIT_SUCCESS);
}
