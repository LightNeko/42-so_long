/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:40:39 by znicola           #+#    #+#             */
/*   Updated: 2025/01/22 20:06:43 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_img(t_data *data, t_img *im, char *path, char *imgname)
{
	path = ft_strjoin(IMG_PATH, imgname); 
	if (!path)
	{
		perror("ft_strjoin");
		exit(1);
	}
	im->img = mlx_xpm_file_to_image(data->mlx, path, &im->w, &im->h);
	if(!im->img)
	{
		ft_printf("Failed to load image: %s\n", path);
		free(path);
		exit(1);
	}
	free(path);
	im->addr = mlx_get_data_addr(im->img, &im->bpp, &im->llen, &im->endian);
}

void	render_img(t_data *data, t_img *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, img->img, x, y);
}

void	destroy_img(t_data *data, t_img *img)	
{
	if (img && img->img)
	{
		mlx_destroy_image(data->mlx, img->img);
		img->img = NULL;
	}
}

void	init_sprites(t_data *data)
{
	load_img(data, &data->floor, IMG_PATH, "floor.xpm");
	load_img(data, &data->wall, IMG_PATH, "stone.xpm");
}
