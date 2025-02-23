/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:30:13 by znicola           #+#    #+#             */
/*   Updated: 2025/02/23 16:25:43 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->m.floor.img);
	mlx_destroy_image(data->mlx, data->m.wall.img);
	mlx_destroy_image(data->mlx, data->p.s_l.img);
	mlx_destroy_image(data->mlx, data->p.s_u.img);
	mlx_destroy_image(data->mlx, data->p.s_r.img);
	mlx_destroy_image(data->mlx, data->p.s_d.img);
	mlx_destroy_image(data->mlx, data->i.s.img);
	mlx_destroy_image(data->mlx, data->e.s.img);
	mlx_destroy_image(data->mlx, data->e.so.img);
	mlx_destroy_image(data->mlx, data->p.w_l1.img);
	mlx_destroy_image(data->mlx, data->p.w_l2.img);
	mlx_destroy_image(data->mlx, data->p.w_u1.img);
	mlx_destroy_image(data->mlx, data->p.w_u2.img);
	mlx_destroy_image(data->mlx, data->p.w_r1.img);
	mlx_destroy_image(data->mlx, data->p.w_r2.img);
	mlx_destroy_image(data->mlx, data->p.w_d1.img);
	mlx_destroy_image(data->mlx, data->p.w_d2.img);
}

void	free_2d(void *to_free, size_t len)
{
	void	**arr;
	size_t	i;

	if (!to_free)
		return ;
	arr = (void **)to_free;
	i = 0;
	while (i < len)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_gnl(int fd, char *line)
{
	free(line);
	line = get_next_line(fd);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
	}
}

void	free_resources(t_data *data)
{
	free_2d(data->m.map, data->m.len);
	free_2d(data->m.dmap, data->m.len);
	free_sprites(data);
}
