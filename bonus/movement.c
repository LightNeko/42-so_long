/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:51:39 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 16:21:22 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	detect_tile(t_data *data)
{
	data->p.state = 1;
	if (data->p.frame == 0)
		data->p.frame = 1;
	else
		data->p.frame = 0;
	bfs(&data->m, data->p.pos_x, data->p.pos_y);
	data->p.steps += 1;
	ft_printf("Step count: %d\n", data->p.steps);
	if (data->p.on_tile == 'C')
	{
		data->p.on_tile = '0';
		data->i.gained++;
	}
	if (data->p.on_tile == 'X')
	{
		free_resources(data);
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_printf("CONGRATULATIONS!\n");
		exit(0);
	}
}

int	move_up(t_data *data)
{
	int	next_tile;

	data->p.direction = 1;
	next_tile = data->m.map[data->p.pos_y - 1][data->p.pos_x];
	if (next_tile == '1' || next_tile == 'E')
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

	data->p.direction = 3;
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

	data->p.direction = 0;
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

	data->p.direction = 2;
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
