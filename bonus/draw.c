/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:30:30 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 21:47:44 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_camera_layer(t_data *data)
{
	data->c.w = data->ww / TILE_SIZE;
	data->c.h = data->wh / TILE_SIZE;
	data->c.start_x = data->p.pos_x - data->c.w / 2;
	data->c.start_y = data->p.pos_y - data->c.h / 2;
	if (data->c.start_x < 0)
		data->c.start_x = 0;
	if (data->c.start_y < 0)
		data->c.start_y = 0;
	if (data->c.start_x + data->c.w > (int)data->m.llen)
		data->c.start_x = data->m.llen - data->c.w;
	if (data->c.start_y + data->c.h > (int)data->m.len)
		data->c.start_y = data->m.len - data->c.h;
}

static void	render_player_direction(t_data *data, int rx, int ry)
{
	if (data->p.direction == 0)
		render_img(data, &data->p.s_l, rx, ry);
	if (data->p.direction == 1)
		render_img(data, &data->p.s_u, rx, ry);
	if (data->p.direction == 2)
		render_img(data, &data->p.s_r, rx, ry);
	if (data->p.direction == 3)
		render_img(data, &data->p.s_d, rx, ry);
}

static void	render_player_movement(t_data *data, int rx, int ry)
{
	if (data->p.direction == 0 && data->p.frame == 0)
		render_img(data, &data->p.w_l1, rx, ry);
	if (data->p.direction == 0 && data->p.frame == 1)
		render_img(data, &data->p.w_l2, rx, ry);
	if (data->p.direction == 1 && data->p.frame == 0)
		render_img(data, &data->p.w_u1, rx, ry);
	if (data->p.direction == 1 && data->p.frame == 1)
		render_img(data, &data->p.w_u2, rx, ry);
	if (data->p.direction == 2 && data->p.frame == 0)
		render_img(data, &data->p.w_r1, rx, ry);
	if (data->p.direction == 2 && data->p.frame == 1)
		render_img(data, &data->p.w_r2, rx, ry);
	if (data->p.direction == 3 && data->p.frame == 0)
		render_img(data, &data->p.w_d1, rx, ry);
	if (data->p.direction == 3 && data->p.frame == 1)
		render_img(data, &data->p.w_d2, rx, ry);
}

static void	check_map_content(t_data *data, char content, int rx, int ry)
{
	if (content == '1')
		render_img(data, &data->m.wall, rx, ry);
	else if (content == '0')
		render_img(data, &data->m.floor, rx, ry);
	else if (content == 'P')
	{
		if (data->p.state == 0)
			render_player_direction(data, rx, ry);
		else
			render_player_movement(data, rx, ry);
	}
	else if (content == 'C')
		render_img(data, &data->i.s, rx, ry);
	else if (content == 'E')
		render_img(data, &data->e.s, rx, ry);
	else if (content == 'X')
		render_img(data, &data->e.so, rx, ry);
	else if (content == 'F')
	{
		if (data->f.frame == 0)
			render_img(data, &data->f.s1, rx, ry);
		if (data->f.frame == 1)
			render_img(data, &data->f.s2, rx, ry);
	}
}

void	draw_map_layer(t_data *data)
{
	int		x;
	int		y;
	int		render_x;
	int		render_y;

	set_camera_layer(data);
	y = data->c.start_y;
	while (y < data->c.start_y + data->c.h)
	{
		x = data->c.start_x;
		while (x < data->c.start_x + data->c.w)
		{
			render_x = (x - data->c.start_x) * TILE_SIZE;
			render_y = (y - data->c.start_y) * TILE_SIZE;
			check_map_content(data, data->m.map[y][x], render_x, render_y);
			x++;
		}
		y++;
	}
}
