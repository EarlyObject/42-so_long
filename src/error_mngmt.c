/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:26:37 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/19 13:26:38 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void
	print_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
}

void
	ft_put_error_exit(char *msg, int err_num)
{
	print_error(msg);
	exit(err_num);
}

void
	ft_exit_error(t_game *game, char *msg, int err_num)
{
	print_error(msg);
	exit_game(game, err_num);
}

void
	ft_error_close(t_game *game, int error_code)
{
	if (error_code == ERR_ARGC_MIN)
		ft_exit_error(game, "Missing map", -1);
	else if (error_code == ERR_ARGC_MAX)
		ft_exit_error(game, "Too many arguments", -1);
	else if (error_code == ERR_MAP_VALIDITY)
		ft_exit_error(game, "Invalid map", -1);
	else if (error_code == ERR_MAP_OPEN)
		ft_exit_error(game, "Map borders are not closed", -1);
	else if (error_code == ERR_MAP_BAD_ARG)
		ft_exit_error(game, "Bad map argument", -1);
}
