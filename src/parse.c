/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:40:03 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 18:40:14 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	parse_args(char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_put_error_exit("File can not be opened", 0);
	close(fd);
	if (!ft_endwith(filename, ".ber"))
		ft_put_error_exit("Wrong map extension", 0);
}

void
	read_map(const int fd, t_game *game)
{
	int				bytes;

	game->lst = ft_my_lstnew(NULL, NULL);
	check_mem_alloc(game->lst);
	game->head = game->lst;
	while (true)
	{
		bytes = get_next_line(fd, (char **)&game->lst->content);
		if (bytes == 1)
		{
			check_mem_alloc(game->lst->content);
			game->lst->next = ft_my_lstnew(NULL, &game->lst);
			check_mem_alloc(game->lst->next);
			game->lst->len = ft_strlen(game->lst->content);
			game->lst = game->lst->next;
		}
		else
			break ;
	}
	game->lst->len = ft_strlen(game->lst->content);
	if (bytes == -1)
		ft_exit_error(game, "Error reading map", -1); //apply correct exit
	close(fd);
}

void
	parse_map(t_game *game)
{
	game->tmp = game->lst;
	check_rectangular(game);
	check_map_bits(game);
	game->tmp = game->head;
	check_horizontal_border(game, game->tmp->content);
	game->tmp = game->head;
	int step;
	step = game->config->rows - 1;
	while (step)
	{
		game->tmp = game->tmp->next;
		step--;
	}
	check_horizontal_border(game, game->tmp->content);
	check_vertical_borders(game);
	check_sign(game);
}
