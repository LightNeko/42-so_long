/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:45:56 by znicola           #+#    #+#             */
/*   Updated: 2025/02/22 17:03:46 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_exit_position(t_exit *exit, t_map map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map.len)
	{
		x = 0;
		while (x < map.llen)
		{
			if (map.map[y][x] == 'E')
			{
				exit->pos_x = x;
				exit->pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	init_exit(t_data *data)
{
	load_img(data, &data->e.s, IMG_PATH, "door_closed.xpm");
	load_img(data, &data->e.so, IMG_PATH, "door_open.xpm");
	get_exit_position(&data->e, data->m);
}
