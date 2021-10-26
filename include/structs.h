/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:21:15 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/18 13:21:16 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

typedef struct s_d_list {
	void			*content;
	int				len;
	struct s_d_list	*next;
	struct s_d_list	*previous;
}	t_d_list;

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	void			*img;
}	t_mlx;

typedef struct s_keys {
	bool			w;
	bool			s;
	bool			a;
	bool			d;
	bool			left;
	bool			right;
}	t_keys;

typedef struct s_image
{
	void			*img_ptr;
	uint32_t		*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}	t_image;

typedef struct s_config
{
	char			**map;
	int				rows;
	int				columns;
	char			player_direction;
	unsigned int	num_p;
	unsigned int	num_e;
	unsigned int	num_c;
	void			*wall;
	void			*space;
	void			*player;
	void			*player_f;
	void			*player_b;
	void			*player_l;
	void			*player_r;
	void			*collect;
	void			*collect1;
	void			*collect2;
	void			*collect3;
	void			*exit;
	void			*exit_open;
	char			*path_wall;
	char			*path_space;
	char			*path_player_f;
	char			*path_player_b;
	char			*path_player_l;
	char			*path_player_r;
	char			*path_collect1;
	char			*path_collect2;
	char			*path_collect3;
	char			*path_exit;
	char			*path_exit_open;
}	t_config;

typedef struct s_game
{
	void			*win;
	t_image			image;
	t_mlx			mlx;
	t_keys			keys;
	t_config		*config;
	t_d_list		*head;
	t_d_list		*lst;
	t_d_list		*tmp;
	int				plr_x;
	int				plr_y;
	unsigned int	steps;
	bool			update_frame;
}	t_game;

enum		e_errors {
	ERR_ARGC_MIN = -15,
	ERR_ARGC_MAX,
	ERR_MAP_VALIDITY,
	ERR_MAP_BAD_ARG,
	ERR_MAP_OPEN,
};

#endif