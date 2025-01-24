/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:24:35 by znicola           #+#    #+#             */
/*   Updated: 2025/01/19 17:19:16 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int add_shade(int rgba, double distance)
{
	t_color	color;
	
	color.r = get_r(rgba) * (1 - distance);
	color.g = get_g(rgba) * (1 - distance);
	color.b = get_b(rgba) * (1 - distance);

	return (create_rgba(color.r, color.g, color.b, 0));
}

int get_opposite(int rgba)
{
	t_color	color;

	color.r = 255 - get_r(rgba);
	color.g = 255 - get_g(rgba);
	color.b = 255 - get_b(rgba);
	color.a = get_a(rgba);

	return (create_rgba(color.r, color.g, color.b, color.a));
}
