/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:22:17 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 19:07:06 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_decimals(int *arr)
{
	int i;
	int n;
	
	i = 9;
	n = 1;
	while (i >= 0)
	{
		arr[i] = n;
		n *= 10;
		i--;
	}
}

static void	render_digits(t_data *data, int digit, int i)
{
	if (digit == 0)
		render_img(data, &data->u.d0, i * TILE_SIZE / 2, 0);
	else if (digit == 1)
		render_img(data, &data->u.d1, i * TILE_SIZE / 2, 0);
	else if (digit == 2)
		render_img(data, &data->u.d2, i * TILE_SIZE / 2, 0);
	else if (digit == 3)
		render_img(data, &data->u.d3, i * TILE_SIZE / 2, 0);
	else if (digit == 4)
		render_img(data, &data->u.d4, i * TILE_SIZE / 2, 0);
	else if (digit == 5)
		render_img(data, &data->u.d5, i * TILE_SIZE / 2, 0);
	else if (digit == 6)
		render_img(data, &data->u.d6, i * TILE_SIZE / 2, 0);
	else if (digit == 7)
		render_img(data, &data->u.d7, i * TILE_SIZE / 2, 0);
	else if (digit == 8)
		render_img(data, &data->u.d8, i * TILE_SIZE / 2, 0);
	else if (digit == 9)
		render_img(data, &data->u.d9, i * TILE_SIZE / 2, 0);
}

void	draw_ui_layer(t_data *data)
{
	int	dec[10];
	int digits[10];
	int	i;
	int	count;
	
	get_decimals(dec);
	count = data->p.steps;
	i = 0;
	while (i < 10)
	{
		digits[i] = count / dec[i];
		count %= dec[i];
		i++;
	}
	i = 0;
	while (i < 10)
	{
		render_digits(data, digits[i], i);
		i++;
	}
}
