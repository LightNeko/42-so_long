/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:02:50 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 16:56:33 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define PIXEL_SIZE	4
# define TILE_SIZE (16 * PIXEL_SIZE)
# define WIN_W (9 * TILE_SIZE)
# define WIN_H (10 * TILE_SIZE)
# define IMG_PATH	"./assets/img/"
# define MAP_PATH	"./maps/"
# define SPEED 30
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

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

typedef struct	s_keys {
	int	up;
	int	down;
	int	left;
	int	right;
}				t_keys;

typedef struct	s_player {
	t_img	s;
	int		count;
	char	on_tile;
	int		pos_x;
	int		pos_y;
}				t_player;

typedef struct	s_map {
	char	**map;
	char	*path;
	size_t	len;
	size_t	llen;
	t_img	floor;
	t_img	wall;
	}			t_map;

typedef struct	s_camera {
	int	start_x;
	int start_y;
	int w;
	int h;
}				t_camera;

typedef struct	s_item {
	t_img	s;
	int		count;
	int		gained;
}				t_item;

typedef struct	s_exit {
	t_img	s;
	t_img	so;
	int		count;
	int		pos_x;
	int		pos_y;
}				t_exit;

typedef struct	s_data {
	void		*mlx;
	void		*window;
	int			ww;
	int			wh;
	int			frame;
	t_keys		k;
	t_map		m;
	t_player	p;
	t_camera	c;
	t_item		i;
	t_exit		e;
}				t_data;


void	init_map(char *map_file, t_data *data);
void	check_file_format(char *filename);
void	check_line_content(t_data *data, char *l);
void	perform_map_checks(t_data *data);
void	init_player(t_data *data);
void	init_keys(t_data *data);
void	init_items(t_data *data);
void	init_exit(t_data *data);
void	set_hooks(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
void	load_img(t_data *data, t_img *im, char *path, char *imgname);
void	render_img(t_data *data, t_img *img, int x, int y);
t_img	img_to_alpha(t_data data, t_img src);
void	render_pixel(t_data data, t_img img, int x, int y);
void	draw_map_layer(t_data *data);
void	manage_error(int error_code, char *message);

#endif
