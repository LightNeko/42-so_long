/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 05:42:24 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 17:24:42 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_items(t_data *data)
{
	load_img(data, &data->i.s, IMG_PATH, "item.xpm");
	data->i.s = img_to_alpha(*data, data->i.s);
	data->i.gained = 0;
}
