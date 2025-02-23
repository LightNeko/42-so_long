/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:09:04 by znicola           #+#    #+#             */
/*   Updated: 2025/02/22 17:34:18 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_dmap(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < (int)map->len)
	{
		x = -1;
		while (++x < (int)map->llen)
			map->dmap[y][x] = -1;
	}
}

static void	get_directions(int *dx, int *dy)
{
	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
}

static void	inner_gen_dmap(t_map *map, t_point pos, int *rear, int *queue)
{
	int	dx[4];
	int	dy[4];
	int	i;
	int	ny;
	int	nx;

	get_directions(dx, dy);
	i = 0;
	while (i < 4)
	{
		ny = pos.y + dy[i];
		nx = pos.x + dx[i];
		if (ny >= 0 && ny < (int)map->len && nx >= 0 && nx < (int)map->llen)
		{
			if (map->map[ny][nx] != '1' && map->dmap[ny][nx] == -1)
			{
				map->dmap[ny][nx] = map->dmap[pos.y][pos.x] + 1;
				queue[(*rear)++] = ny * map->llen + nx;
			}
		}
		i++;
	}
}

static void	gen_dmap(t_map *map, int *queue, int front, int *rear)
{
	int		current;
	t_point	pos;

	while (front < *rear)
	{
		current = queue[front++];
		pos.y = current / map->llen;
		pos.x = current % map->llen;
		inner_gen_dmap(map, pos, rear, queue);
	}
}

void	bfs(t_map *map, int x, int y)
{
	int	*queue;
	int	front;
	int	rear;

	clean_dmap(map);
	queue = malloc(map->llen * map->len * sizeof(int));
	if (!queue)
		manage_error(NULL, 2, "bfs queue - malloc (1)", NULL);
	front = 0;
	rear = 0;
	map->dmap[y][x] = 0;
	queue[rear++] = y * map->llen + x;
	gen_dmap(map, queue, front, &rear);
	free(queue);
}
