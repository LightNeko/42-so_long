/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:19:12 by znicola           #+#    #+#             */
/*   Updated: 2025/02/24 14:19:07 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_data(t_data *data, char **argv)
{
	data->mlx = mlx_init();
	mlx_do_key_autorepeatoff(data->mlx);
	data->p.count = 0;
	data->e.count = 0;
	data->i.count = 0;
	data->f.count = 0;
	init_map(argv[1], data);
	if (data->m.llen * TILE_SIZE < WIN_W)
		data->ww = data->m.llen * TILE_SIZE;
	else
		data->ww = WIN_W;
	if (data->m.len * TILE_SIZE < WIN_H)
		data->wh = data->m.len * TILE_SIZE;
	else
		data->wh = WIN_H;
	init_digits(data);
	init_player(data);
	init_enemy(data);
	init_keys(data);
	init_items(data);
	init_exit(data);
	check_reachable_items(data, &data->m);
	perform_map_checks(data);
	data->window = mlx_new_window(data->mlx, data->ww, data->wh, "so_long");
}

static void	handle_movement(t_data *data)
{
	struct timeval	tv;
	long long		current_time;
	long long		elapsed;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed = current_time - data->p.last_move_time;
	if (elapsed >= data->p.move_cooldown)
	{
		if (data->k.left && !data->k.right)
			move_left(data, &current_time);
		if (data->k.up && !data->k.down)
			move_up(data, &current_time);
		if (data->k.right && !data->k.left)
			move_right(data, &current_time);
		if (data->k.down && !data->k.up)
			move_down(data, &current_time);
	}
}

static int	update(t_data *data)
{
	struct timeval	tv;
	long long		current_time;
	long long		elapsed;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed = current_time - data->last_frame_time;
	if (elapsed >= 16666)
	{
		draw_map_layer(data);
		draw_ui_layer(data);
		handle_movement(data);
		if (data->f.count == 1)
			move_enemy(data);
		if (data->k.left == 0 && data->k.up == 0
			&& data->k.right == 0 && data->k.down == 0)
			data->p.state = 0;
		if (data->i.count == data->i.gained)
		{
			data->i.gained++;
			data->m.map[data->e.pos_y][data->e.pos_x] = 'X';
		}
		data->last_frame_time = current_time;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	struct timeval	tv;

	if (argc != 2)
		manage_error(NULL, 1, "Invalid arguments: must have 1 argument", NULL);
	gettimeofday(&tv, NULL);
	data.last_frame_time = tv.tv_sec * 1000000 + tv.tv_usec;
	check_file_format(argv[1]);
	init_data(&data, argv);
	set_hooks(&data);
	mlx_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
	return (0);
}
