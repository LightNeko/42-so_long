/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:58:30 by znicola           #+#    #+#             */
/*   Updated: 2025/01/19 20:18:25 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_hook(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
	return (0);
}

int keydown_hook(int keycode, t_data *data)
{
	if (keycode != 65307)
		ft_printf("Do something: %d\n", keycode);
	else
		close_hook(data);
	return(0);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->window, 2, 1L << 0, keydown_hook, data);
	mlx_hook(data->window, 17, 1L << 0, close_hook, data);
}
