/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:01:52 by znicola           #+#    #+#             */
/*   Updated: 2025/02/24 14:20:58 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_file_format(char *filename)
{
	char	*p_format;

	p_format = ft_strrchr(filename, '.');
	if (!p_format || ft_strcmp(p_format, ".ber"))
		manage_error(NULL, 1, "File extension is not .ber\n", NULL);
}

static int	check_boundaries(t_map map)
{
	size_t	i;

	i = 0;
	while (i < map.llen)
	{
		if (map.map[0][i] != '1' || map.map[map.len - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < map.len)
	{
		if (map.map[i][0] != '1' || map.map[i][map.llen - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_reachable_items(t_data *data, t_map *map)
{
	size_t	x;
	size_t	y;

	bfs(map, data->p.pos_x, data->p.pos_y);
	y = 0;
	while (y < map->len)
	{
		x = 0;
		while (x < map->llen)
		{
			if (map->map[y][x] == 'C' && map->dmap[y][x] == -1)
				manage_error(data, 4, "Invalid Map: non-reachable items", NULL);
			if (map->map[y][x] == 'E' && map->dmap[y][x] == -1)
				manage_error(data, 4, "Invalid Map: non-reachable exit", NULL);
			x++;
		}
		y++;
	}
}

void	check_line_content(t_data *data, int fd, char *l)
{
	char	*p;

	if (l == NULL)
		return ;
	p = l;
	while (*p != '\n')
	{
		if (*p == '0' || *p == '1')
			;
		else if (*p == 'F')
			data->f.count++;
		else if (*p == 'P')
			data->p.count++;
		else if (*p == 'C')
			data->i.count++;
		else if (*p == 'E')
			data->e.count++;
		else
		{
			free_gnl(fd, l);
			manage_error(data, 1, "Invalid Map: forbidden key", data->m.path);
		}
		p++;
	}
}

void	perform_map_checks(t_data *data)
{
	int	check;

	check = 0;
	check = check_boundaries(data->m);
	if (check == 1)
		manage_error(data, 4, "Invalid Map: not surrounded by walls", NULL);
}
