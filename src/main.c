/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:19:12 by znicola           #+#    #+#             */
/*   Updated: 2025/02/24 15:47:27 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_dmap(t_map map, int debug)
{
	size_t	x;
	size_t	y;

	if (debug == 0)
		return ;
	y = 0;
	while (y < map.len)
	{
		x = 0;
		while (x < map.llen)
		{
			if (map.dmap[y][x] == -1 || map.dmap[y][x] >= 10)
				ft_printf(" %d", map.dmap[y][x]);
			else
				ft_printf("  %d", map.dmap[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

static void	init_data(t_data *data, char **argv)
{
	data->mlx = mlx_init();
	mlx_do_key_autorepeatoff(data->mlx);
	data->p.count = 0;
	data->e.count = 0;
	data->i.count = 0;
	init_map(argv[1], data);
	if (data->m.llen * TILE_SIZE < WIN_W)
		data->ww = data->m.llen * TILE_SIZE;
	else
		data->ww = WIN_W;
	if (data->m.len * TILE_SIZE < WIN_H)
		data->wh = data->m.len * TILE_SIZE;
	else
		data->wh = WIN_H;
	init_player(data);
	init_keys(data);
	init_items(data);
	init_exit(data);
	check_reachable_items(data, &data->m);
	print_dmap(data->m, DEBUG_MODE);
	perform_map_checks(data);
	data->window = mlx_new_window(data->mlx, data->ww, data->wh, "so_long");
	data->frame = 0;
}

static void	handle_movement(t_data *data)
{
	if (data->k.left && !data->k.right)
	{
		move_left(data);
		print_dmap(data->m, DEBUG_MODE);
	}
	if (data->k.up && !data->k.down)
	{
		move_up(data);
		print_dmap(data->m, DEBUG_MODE);
	}
	if (data->k.right && !data->k.left)
	{
		move_right(data);
		print_dmap(data->m, DEBUG_MODE);
	}
	if (data->k.down && !data->k.up)
	{
		move_down(data);
		print_dmap(data->m, DEBUG_MODE);
	}
}

static int	update(t_data *data)
{
	draw_map_layer(data);
	if (data->k.just_pressed == 1)
	{
		data->k.just_pressed = 2;
		handle_movement(data);
		data->frame = 0;
	}
	if (data->frame == SPEED)
	{
		handle_movement(data);
		data->frame = 0;
	}
	if (data->k.left == 0 && data->k.up == 0
		&& data->k.right == 0 && data->k.down == 0)
	{
		data->k.just_pressed = 0;
		data->p.state = 0;
	}
	if (data->i.count == data->i.gained)
	{
		data->i.gained++;
		data->m.map[data->e.pos_y][data->e.pos_x] = 'X';
	}
	data->frame++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		manage_error(NULL, 1, "Invalid arguments: must have 1 argument", NULL);
	check_file_format(argv[1]);
	init_data(&data, argv);
	set_hooks(&data);
	mlx_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
	return (0);
}
