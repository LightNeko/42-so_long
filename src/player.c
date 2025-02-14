/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:06:49 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 09:49:34 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_player *player, t_map map)
{
	size_t x;
	size_t y;
	
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
	load_img(data, &data->p.s, IMG_PATH, "player.xpm");	
	data->p.s = img_to_alpha(*data, data->p.s);	
	data->p.on_tile = '0';
	get_player_position(&data->p, data->m);
}
