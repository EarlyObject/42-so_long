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
	ft_exit_error(char *msg, int err_num)
{
	print_error(msg);
	exit_game(err_num);
}

void
	ft_error_close(int error_code)
{
	if (error_code == ERR_MAP_VALIDITY)
		ft_exit_error("Invalid map", 0);
	else if (error_code == ERR_MAP_OPEN)
		ft_exit_error("Map borders are not closed", 0);
}

int
	exit_game(int code)
{
	exit(code);
}
