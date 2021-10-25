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

# define TEXTURE_SIZE			64
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
void		parse_args(char *filename);
void		read_map(const int fd, t_game *game);
void		check_mem_alloc(void *p);
t_d_list	*ft_my_lstnew(void *content, t_d_list **prev);
int			exit_game(t_game *game, int code);
int			clear_window(t_game *game);
void		clear_textures(t_game *game);
void		init_keys(t_game *game);
int			init_window(t_game *game);
void		initialize_game(t_game *game);
void		ft_exit_error(t_game *game, char *msg, int err_num);
void		ft_put_error_exit(char *msg, int err_num);
void		check_map_bits(t_game *game);
void		check_horizontal_border(t_game *game, const char *str);
void		check_vertical_borders(t_game *game);
void		check_sign(t_game *game);
void		check_rectangular(t_game *game);
void		ft_error_close(t_game *game, int error_code);
bool		is_valid_map_bit(char c);
void		build_frame(t_game *game);
void		load_textures(t_game *game);
void		parse_map(t_game *game);
void		create_map(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		free_list(t_d_list *list);
void		free_map(t_game *game);
void		draw_player(t_game *game, int i, int j);
void		draw_collect(t_game *game, int i, int j);
void		draw_space(t_game *game);
void		count_map_objects(t_game *game, int row, int column);
void		print_steps(const t_game *game);
void		finish_game(t_game *game);
void		make_step(t_game *game, char next_step, int step_y, int step_x);

#endif