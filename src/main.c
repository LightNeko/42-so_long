/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:19:12 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 17:23:52 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_data(t_data *data, char **argv)
{	
	data->mlx = mlx_init();
	data->p.count = 0;
	data->e.count = 0;
	data->i.count = 0;
	init_map(argv[1], data);	
	perform_map_checks(data);	
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
	data->window = mlx_new_window(data->mlx, data->ww, data->wh, "so_long");
	data->frame = 0;	
}

static void handle_movement(t_data *data)
{
	if (data->k.left)
        move_left(data);
    if (data->k.up)
        move_up(data);
    if (data->k.right)
        move_right(data);
    if (data->k.down)
        move_down(data);
}

static int	update(t_data *data)
{
	draw_map_layer(data);
	if (data->frame == SPEED)
	{
		handle_movement(data);
		data->frame = 0;
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
		manage_error(1, "Invalid arguments");		
	check_file_format(argv[1]);
	init_data(&data, argv);
	ft_printf("data initiated\n");
	set_hooks(&data);
	mlx_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
	free(data.m.map);
	return (0);
}
