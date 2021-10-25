/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:43:51 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/19 15:43:52 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	check_map_bits(t_game *game)
{
	int		i;

	i = 0;
	game->tmp = game->head;
	while (game->tmp->next != NULL)
	{
		while (is_valid_map_bit(((char *)(game->tmp->content))[i]))
			i++;
		if ((((char *)(game->tmp->content))[i]) != '\0')
			ft_error_close(game, ERR_MAP_VALIDITY);
		i = 0;
		game->tmp = game->tmp->next;
	}
	while (is_valid_map_bit(((char *)(game->tmp->content))[i]))
		i++;
	if ((((char *)(game->tmp->content))[i]) != '\0')
		ft_error_close(game, ERR_MAP_VALIDITY);
}

void
	check_horizontal_border(t_game *game, const char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			ft_error_close(game, ERR_MAP_OPEN);
		i++;
	}
}

void
	check_vertical_borders(t_game *game)
{
	game->tmp = game->head;
	while (game->tmp)
	{
		if (((char *)(game->tmp->content))[0] != '1' || \
			((char *)(game->tmp->content))[game->tmp->len - 1] != '1')
			ft_error_close(game, ERR_MAP_OPEN);
		game->tmp = game->tmp->next;
	}
	game->tmp = game->lst;
}

void
	check_sign(t_game *game)
{
	int		row;
	int		column;

	row = 1;
	game->tmp = game->head->next;
	while (row < game->config->rows - 1)
	{
		column = 1;
		count_map_objects(game, row, column);
		row++;
		game->tmp = game->tmp->next;
	}
	if (!game->config->num_p || !game->config->num_e || !game->config->num_c
		|| game->config->num_p > 1)
		ft_exit_error(game, "Map is invalid", -1);
}

void
	check_rectangular(t_game *game)
{
	int		i;
	int		columns;
	int		rows;

	i = 0;
	game->tmp = game->head;
	while ((((char *)(game->tmp->content))[i]) != '\0')
		i++;
	columns = i;
	rows = 1;
	game->tmp = game->tmp->next;
	while (game->tmp)
	{
		i = 0;
		while ((((char *)(game->tmp->content))[i]) != '\0')
			i++;
		if (i != columns)
			ft_error_close(game, ERR_MAP_VALIDITY);
		rows++;
		game->tmp = game->tmp->next;
	}
	game->config->rows = rows;
	game->config->columns = columns;
}
