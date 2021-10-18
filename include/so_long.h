/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:41:59 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 12:42:00 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include <fcntl.h>
# include "structs.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"


# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_LEFT				123
# define KEY_RIGHT				124

int			deal_key(int key_code, t_game *game);
int			release_key(int key_code, t_game *game);
void		move_player(t_game *game);
void		ft_run(t_game game);
int			close_win(void);
void		parse_args(t_game *game, char *filename);
void		parse_map(const int fd, t_game *game);
void		check_mem_alloc(void *p);
t_d_list	*ft_my_lstnew(void *content, t_d_list **prev);
int			exit_game(t_game *game, int code);
int			clear_window(t_game *game);
void		clear_textures(t_game *game);
void		init_keys(t_game *game);
int			init_window(t_game *game);
void		initialize_game(t_game *game);
void		ft_exit_error(t_game *game, char *msg, int err_num);

#endif