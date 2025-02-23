/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:40:39 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 16:08:51 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data, t_img *im, char *path, char *imgname)
{
	path = ft_strjoin(IMG_PATH, imgname);
	if (!path)
		manage_error(data, 2, "Invalid path", NULL);
	im->img = mlx_xpm_file_to_image(data->mlx, path, &im->w, &im->h);
	if (!im->img)
		manage_error(data, 2, "Invalid path", path);
	free(path);
	im->addr = mlx_get_data_addr(im->img, &im->bpp, &im->llen, &im->endian);
	*im = img_to_alpha(*data, *im);
}

void	render_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img->img, x, y);
}

static unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.llen) + (x * img.bpp / 8))));
}

void	render_pixel(t_data data, t_img img, int x, int y)
{
	char			*dst;
	unsigned int	old_color;
	unsigned int	new_color;

	old_color = get_pixel_img(img, x, y);
	new_color = get_pixel_img(data.m.floor, x, y);
	if (old_color != (int)0x0065FF00)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.llen + x * (img.bpp / 8));
		*(unsigned int *) dst = new_color;
	}
}

t_img	img_to_alpha(t_data data, t_img img)
{
	int	x;
	int	y;

	x = 0;
	while (x < img.w)
	{
		y = 0;
		while (y < img.h)
		{
			render_pixel(data, img, x, y);
			y++;
		}
		x++;
	}
	return (img);
}
