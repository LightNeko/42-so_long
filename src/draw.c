/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:30:30 by znicola           #+#    #+#             */
/*   Updated: 2025/01/22 20:06:57 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (x % (2 * TILE_SIZE))
				render_img(data, &data->floor, x, y);
			else
				render_img(data, &data->wall, x, y);
			y = y + TILE_SIZE;
		}
		x = x + TILE_SIZE;
	}
}
