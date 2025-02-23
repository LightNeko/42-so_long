/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:23:24 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 23:01:38 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_enemy_position(t_foe *enemy, t_map map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map.len)
	{
		x = 0;
		while (x < map.llen)
		{
			if (map.map[y][x] == 'F')
			{
				enemy->pos_x = x;
				enemy->pos_y = y;
			}
			x++;
		}
		y++;
	}
}

static void	move_to_next_cell(t_data *data, int *y, int *x)
{
	int dmap_position;

	dmap_position = data->m.dmap[*y][*x];
	if (data->m.dmap[*y][*x - 1] < dmap_position && data->m.dmap[*y][*x - 1] > -1)
		move_enemy_left(data, y, x);
	else if (data->m.dmap[*y - 1][*x] < dmap_position && data->m.dmap[*y - 1][*x] > -1)
		move_enemy_up(data, y, x);
	else if (data->m.dmap[*y][*x + 1] < dmap_position && data->m.dmap[*y][*x + 1] > -1)
		move_enemy_right(data, y, x);
	else if (data->m.dmap[*y + 1][*x] < dmap_position && data->m.dmap[*y + 1][*x] > -1)
		move_enemy_down(data, y, x);
}

void	move_enemy(t_data *data)
{
	struct timeval	tv;
	long long		current_time;
	long long		elapsed;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed = current_time - data->f.last_move_time;
	if (elapsed >= data->f.move_cooldown)
	{
		if (data->f.frame == 0)
			data->f.frame = 1;
		else
			data->f.frame = 0;
		move_to_next_cell(data, &data->f.pos_y, &data->f.pos_x);
		data->f.last_move_time = current_time;
	}
}

void	init_enemy(t_data *data)
{
	load_img(data, &data->f.s1, IMG_PATH, "enemy1.xpm");
	load_img(data, &data->f.s2, IMG_PATH, "enemy2.xpm");
	data->f.frame = 0;
	data->f.on_tile = '0';
	data->f.last_move_time = 0;
	data->f.move_cooldown = ENEMY_MOVE_RATE;
	get_enemy_position(&data->f, data->m);
}
