/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:56:29 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 19:28:17 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_digits(t_data *data)
{
	load_img(data, &data->u.d0, IMG_PATH, "0.xpm");
	load_img(data, &data->u.d1, IMG_PATH, "1.xpm");
	load_img(data, &data->u.d2, IMG_PATH, "2.xpm");
	load_img(data, &data->u.d3, IMG_PATH, "3.xpm");
	load_img(data, &data->u.d4, IMG_PATH, "4.xpm");
	load_img(data, &data->u.d5, IMG_PATH, "5.xpm");
	load_img(data, &data->u.d6, IMG_PATH, "6.xpm");
	load_img(data, &data->u.d7, IMG_PATH, "7.xpm");
	load_img(data, &data->u.d8, IMG_PATH, "8.xpm");
	load_img(data, &data->u.d9, IMG_PATH, "9.xpm");
}
