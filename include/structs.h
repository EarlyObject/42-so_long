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

typedef struct s_game
{
	void			*win;
	t_image			image;
	t_mlx			mlx;
	t_keys			keys;
	t_d_list		*head;
	t_d_list		*lst;
	t_d_list		*tmp;
}	t_game;


#endif