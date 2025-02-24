/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:09:56 by znicola           #+#    #+#             */
/*   Updated: 2025/02/24 14:35:54 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_left(t_data *data, int *y, int *x)
{
	data->m.map[*y][*x] = data->f.on_tile;
	(*x)--;
	data->f.on_tile = data->m.map[*y][*x];
	data->m.map[*y][*x] = 'F';
	if (data->f.on_tile == 'P')
	{
		free_resources(data);
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_printf("GAME OVER!\n");
		exit(0);
	}
}

void	move_enemy_up(t_data *data, int *y, int *x)
{
	data->m.map[*y][*x] = data->f.on_tile;
	(*y)--;
	data->f.on_tile = data->m.map[*y][*x];
	data->m.map[*y][*x] = 'F';
	if (data->f.on_tile == 'P')
	{
		free_resources(data);
		mlx_destroy_window(data->mlx, data->window);
		free(data->mlx);
		ft_printf("GAME OVER!\n");
		exit(0);
	}
}

void	move_enemy_right(t_data *data, int *y, int *x)
{
	data->m.map[*y][*x] = data->f.on_tile;
	(*x)++;
	data->f.on_tile = data->m.map[*y][*x];
	data->m.map[*y][*x] = 'F';
	if (data->f.on_tile == 'P')
	{
		free_resources(data);
		mlx_destroy_window(data->mlx, data->window);
		free(data->mlx);
		ft_printf("GAME OVER!\n");
		exit(0);
	}
}

void	move_enemy_down(t_data *data, int *y, int *x)
{
	data->m.map[*y][*x] = data->f.on_tile;
	(*y)++;
	data->f.on_tile = data->m.map[*y][*x];
	data->m.map[*y][*x] = 'F';
	if (data->f.on_tile == 'P')
	{
		free_resources(data);
		mlx_destroy_window(data->mlx, data->window);
		free(data->mlx);
		ft_printf("GAME OVER!\n");
		exit(0);
	}
}
