/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:30:30 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 15:42:10 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (data->m.map[y][x] == '1')
				render_img(data, &data->m.wall, render_x, render_y);
			else if (data->m.map[y][x] == '0')
				render_img(data, &data->m.floor, render_x, render_y);
			else if (data->m.map[y][x] == 'P')
				render_img(data, &data->p.s, render_x, render_y);
			else if (data->m.map[y][x] == 'C')
				render_img(data, &data->i.s, render_x, render_y);
			else if (data->m.map[y][x] == 'E')
				render_img(data, &data->e.s, render_x, render_y);
			else if (data->m.map[y][x] == 'X')
				render_img(data, &data->e.so, render_x, render_y);
			x++;
		}
		y++;
	}
}
