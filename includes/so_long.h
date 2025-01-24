/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:02:50 by znicola           #+#    #+#             */
/*   Updated: 2025/01/22 20:04:23 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>

# define PIXEL_SIZE	4
# define TILE_SIZE (16 * PIXEL_SIZE)
# define WIN_W (10 * TILE_SIZE)
# define WIN_H (9 * TILE_SIZE)
# define IMG_PATH	"./assets/img/"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
	int		w;
	int		h;
	char	*path;
}				t_img;

/*typedef struct	t_layer {
	void	*img;
}*/

typedef struct	s_data {
	void	*mlx;
	void	*window;
	t_img	floor;
	t_img	wall;
}				t_data;

typedef struct	s_color {
	int r;
	int g;
	int b;
	int a;
}				t_color;

typedef struct s_pixel {
	int		w;
	int 	h;
	t_color	color;
}				t_pixel;

int		create_rgba(int r, int g, int b, int a);
int 	get_a(int argb);
int 	get_r(int argb);
int 	get_g(int argb);
int 	get_b(int argb);
int 	add_shade(int rgba, double distance);
int 	get_opposite(int rgba);
void	set_hooks(t_data *data);
void	init_sprites(t_data *data);
void	render_img(t_data *data, t_img *img, int x, int y);
void	destroy_img(t_data *data, t_img *img);
void	resize_img(t_img *src_img, t_img *dst_img, int new_width, int new_height);
void	draw_map(t_data *data);

#endif
