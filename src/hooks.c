/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:58:30 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 07:08:39 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_hook(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
	return (0);
}

static int	keydown_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->k.left = 1;
	if (keycode == 65362)
		data->k.up = 1;
	if (keycode == 65363)
		data->k.right = 1;
	if (keycode == 65364)
		data->k.down = 1;
	if (keycode == 65307)
		close_hook(data);
	return (0);
}

static int	keyup_hook(int keycode, t_data *data)
{
	if (keycode == 65361)
		data->k.left = 0;
	if (keycode == 65362)
		data->k.up = 0;
	if (keycode == 65363)
		data->k.right = 0;
	if (keycode == 65364)
		data->k.down = 0;
	return (0);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->window, 2, 1L << 0, keydown_hook, data);
	mlx_hook(data->window, 3, 1L << 1, keyup_hook, data);
	mlx_hook(data->window, 17, 1L << 0, close_hook, data);
}
