/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:06:49 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 16:18:22 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_player *player, t_map map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map.len)
	{
		x = 0;
		while (x < map.llen)
		{
			if (map.map[y][x] == 'P')
			{
				player->pos_x = x;
				player->pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_data *data)
{
	load_img(data, &data->p.s_l, IMG_PATH, "p_left.xpm");
	load_img(data, &data->p.s_u, IMG_PATH, "p_up.xpm");
	load_img(data, &data->p.s_r, IMG_PATH, "p_right.xpm");
	load_img(data, &data->p.s_d, IMG_PATH, "p_down.xpm");
	load_img(data, &data->p.w_l1, IMG_PATH, "p_walk_l1.xpm");
	load_img(data, &data->p.w_l2, IMG_PATH, "p_walk_l2.xpm");
	load_img(data, &data->p.w_u1, IMG_PATH, "p_walk_u1.xpm");
	load_img(data, &data->p.w_u2, IMG_PATH, "p_walk_u2.xpm");
	load_img(data, &data->p.w_r1, IMG_PATH, "p_walk_r1.xpm");
	load_img(data, &data->p.w_r2, IMG_PATH, "p_walk_r2.xpm");
	load_img(data, &data->p.w_d1, IMG_PATH, "p_walk_d1.xpm");
	load_img(data, &data->p.w_d2, IMG_PATH, "p_walk_d2.xpm");
	data->p.direction = 3;
	data->p.state = 0;
	data->p.frame = 0;
	data->p.on_tile = '0';
	data->p.steps = 0;
	get_player_position(&data->p, data->m);
}
