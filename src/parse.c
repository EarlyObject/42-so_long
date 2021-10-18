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
	parse_args(t_game *game, char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit_error(game, "File can not be opened", -1);//apply correct closings
	close(fd);
	if (!ft_endwith(filename, ".cub"))
		ft_exit_error(game, "Wrong map extension", -1); //apply correct closings
}

void
	parse_map(const int fd, t_game *game)
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
		ft_exit_error(game, "ERROR READING MAP", -1); //apply correct exit
	close(fd);
}
