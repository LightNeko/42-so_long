/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:10:21 by znicola           #+#    #+#             */
/*   Updated: 2025/02/24 15:40:19 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static void	check_first_line(char **line, int fd, t_data *data)
{
	*line = get_next_line(fd);
	if (!(*line))
		manage_error(data, 1, "Invalid Map - map is empty", data->m.path);
	check_line_content(data, fd, *line);
}

static size_t	count_lines(t_data *data, char *path, size_t *llen)
{
	char	*line;
	size_t	count;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_error(data, 2, "Error loading file", path);
	check_first_line(&line, fd, data);
	count = 0;
	*llen = ft_strlen(line) - 1;
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
		check_line_content(data, fd, line);
		if (line != NULL && *llen != ft_strlen(line) - 1)
		{
			free_gnl(fd, line);
			manage_error(data, 1, "Map Error: Map is not rectangular", path);
		}
	}
	free(line);
	close(fd);
	return (count);
}

static char	**load_map(t_data *data, char *path, size_t len, size_t llen)
{
	char	**map;
	char	**temp;
	char	*line;
	int		fd;	

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_error(data, 2, "Error loading the file", path);
	map = calloc(len, sizeof(char *));
	if (!map)
		manage_error(data, 2, "store_map - calloc (1)", path);
	temp = map;
	line = get_next_line(fd);
	while (line != NULL)
	{
		*temp = ft_substr(line, 0, llen);
		temp++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

static int	**init_distance(t_data *data, t_map map)
{
	int		**dmap;
	int		x;
	int		y;

	dmap = malloc(map.len * sizeof(int *));
	if (!dmap)
		manage_error(data, 2, "distance_map - malloc (1)", NULL);
	y = -1;
	while (++y < (int)map.len)
	{
		dmap[y] = malloc(map.llen * sizeof(int));
		if (!dmap[y])
			manage_error(data, 2, "distance_map - malloc (2)", NULL);
	}
	y = -1;
	while (++y < (int)map.len)
	{
		x = -1;
		while (++x < (int)map.llen)
			dmap[y][x] = -1;
	}
	return (dmap);
}

void	init_map(char *map_file, t_data *data)
{
	data->m.path = ft_strdup(map_file);
	if (!data->m.path)
		manage_error(data, 2, "map_path", NULL);
	data->m.len = count_lines(data, data->m.path, &data->m.llen);
	if (data->p.count != 1)
		manage_error(data, 1, "Invalid Map: P count is not 1", data->m.path);
	if (data->e.count != 1)
		manage_error(data, 1, "Invalid Map: E count is not 1", data->m.path);
	if (data->i.count < 1)
		manage_error(data, 1, "Invalid Map: missing C", data->m.path);
	data->m.map = load_map(data, data->m.path, data->m.len, data->m.llen);
	free(data->m.path);
	data->m.dmap = init_distance(data, data->m);
	load_img(data, &data->m.floor, IMG_PATH, "floor.xpm");
	load_img(data, &data->m.wall, IMG_PATH, "stone.xpm");
}
