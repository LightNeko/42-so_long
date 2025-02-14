/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:51:39 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 13:55:26 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void detect_tile(t_data *data)
{
	if (data->p.on_tile == 'C')
	{
		data->p.on_tile = '0';
		data->i.gained++;
	}
	if (data->p.on_tile == 'X')
	{
		mlx_destroy_window(data->mlx, data-> window);
		ft_printf("CONGRATULATIONS!\n");
		exit(1);
	}
}

int	move_up(t_data *data)
{
	int next_tile;

	next_tile = data->m.map[data->p.pos_y - 1][data->p.pos_x];
	if (next_tile == '1'|| next_tile == 'E')
		return (1);	
	data->m.map[data->p.pos_y][data->p.pos_x] = data->p.on_tile;
	data->p.pos_y = data->p.pos_y - 1;
	data->p.on_tile = data->m.map[data->p.pos_y][data->p.pos_x];
	data->m.map[data->p.pos_y][data->p.pos_x] = 'P';
	detect_tile(data);
	return (1);
}

int	move_down(t_data *data)
{
	int	next_tile;
	
	next_tile = data->m.map[data->p.pos_y + 1][data->p.pos_x];
	if (next_tile == '1' || next_tile == 'E')
		return (2);
	data->m.map[data->p.pos_y][data->p.pos_x] = data->p.on_tile;
	data->p.pos_y = data->p.pos_y + 1;
	data->p.on_tile = data->m.map[data->p.pos_y][data->p.pos_x];
	data->m.map[data->p.pos_y][data->p.pos_x] = 'P';
	detect_tile(data);
	return (2);
}

int	move_left(t_data *data)
{
	int	next_tile;
	
	next_tile = data->m.map[data->p.pos_y][data->p.pos_x - 1];
	if (next_tile == '1' || next_tile == 'E')
		return (3);
	data->m.map[data->p.pos_y][data->p.pos_x] = data->p.on_tile;
	data->p.pos_x = data->p.pos_x - 1;
	data->p.on_tile = data->m.map[data->p.pos_y][data->p.pos_x];
	data->m.map[data->p.pos_y][data->p.pos_x] = 'P';
	detect_tile(data);
	return (3);
}

int	move_right(t_data *data)
{
	int	next_tile;

	next_tile = data->m.map[data->p.pos_y][data->p.pos_x + 1];
	if (next_tile == '1' || next_tile == 'E')
		return (4);
	data->m.map[data->p.pos_y][data->p.pos_x] = data->p.on_tile;
	data->p.pos_x = data->p.pos_x + 1;
	data->p.on_tile = data->m.map[data->p.pos_y][data->p.pos_x];
	data->m.map[data->p.pos_y][data->p.pos_x] = 'P';
	detect_tile(data);
	return (4);
}
