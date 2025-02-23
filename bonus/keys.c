/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:55:24 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 18:01:28 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_keys(t_data *data)
{
	data->k.up = 0;
	data->k.down = 0;
	data->k.right = 0;
	data->k.left = 0;
	data->k.just_pressed = 0;
}
