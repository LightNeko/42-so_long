/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:19:12 by znicola           #+#    #+#             */
/*   Updated: 2025/01/22 20:04:46 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->llen + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int render_frame(t_data *data)
{
	draw_map(data);	
    return (0);
}


int	main(void)
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, WIN_W, WIN_H, "so_long");
	init_sprites(&data);
	set_hooks(&data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
