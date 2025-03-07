/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:02:50 by znicola           #+#    #+#             */
/*   Updated: 2025/03/01 11:30:33 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define PIXEL_SIZE	4
# define TILE_SIZE 64
# define WIN_W 576
# define WIN_H 640
# define IMG_PATH	"./assets/img/"
# define SPEED 300
# define DEBUG_MODE 1

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
	int		w;
	int		h;
	char	*path;
}				t_img;

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	just_pressed;
}				t_keys;

typedef struct s_player
{
	t_img	s_l;
	t_img	s_u;
	t_img	s_r;
	t_img	s_d;
	t_img	w_l1;
	t_img	w_l2;
	t_img	w_u1;
	t_img	w_u2;
	t_img	w_r1;
	t_img	w_r2;
	t_img	w_d1;
	t_img	w_d2;
	int		direction;
	int		state;
	int		frame;
	int		count;
	char	on_tile;
	int		steps;
	int		pos_x;
	int		pos_y;
}				t_player;

typedef struct s_map
{
	char	**map;
	int		**dmap;
	char	*path;
	size_t	len;
	size_t	llen;
	t_img	floor;
	t_img	wall;
}				t_map;

typedef struct s_camera
{
	int	start_x;
	int	start_y;
	int	w;
	int	h;
}				t_camera;

typedef struct s_item
{
	t_img	s;
	int		count;
	int		gained;
}				t_item;

typedef struct s_exit
{
	t_img	s;
	t_img	so;
	int		count;
	int		pos_x;
	int		pos_y;
}				t_exit;

typedef struct s_data
{
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
void	check_line_content(t_data *data, int fd, char *l);
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
void	manage_error(void *data, int error_code, char *message, void *to_free);
void	bfs(t_map *map, int x, int y);
void	check_reachable_items(t_data *data, t_map *map);
void	free_sprites(t_data *data);
void	free_2d(void *to_free, size_t len);
void	free_gnl(int fd, char *line);
void	free_resources(t_data *data);

#endif
