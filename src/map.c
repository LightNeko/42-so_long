/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:10:21 by znicola           #+#    #+#             */
/*   Updated: 2025/02/06 17:29:24 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static size_t	count_lines(t_data *data, char *path, size_t *llen)
{
	char	*line;
	size_t	count;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_error(2, "Error loading the file");
	line = get_next_line(fd);
	check_line_content(data, line);
	count = 0;
	*llen = ft_strlen(line) - 1;
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
		check_line_content(data, line);
		if (line != NULL && *llen != ft_strlen(line) - 1)
		{
			free(line);
			manage_error(1, "Map Error: Map is not rectangular");
		}
	}
	free(line);
	close(fd);
	return (count);
}

static char	**load_map(char *path, size_t len, size_t llen)
{
	char	**map;
	char	**temp;
	char	*line;
	int		fd;	

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_error(2, "Error loading the file");
	map = calloc(len, sizeof(char *));
	if (!map)
		manage_error(2, "store_map - calloc (1)");
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

void	init_map(char *map_file, t_data *data)
{
	data->m.path = ft_strjoin(MAP_PATH, map_file);
	if (!data->m.path)
		manage_error(2, "map_path");
	data->m.len = count_lines(data, data->m.path, &data->m.llen);
	if (data->p.count != 1)
		manage_error(1, "Invalid Map: P count should equal 1");
	if (data->e.count != 1)
		manage_error(1, "Invalid Map: E count should equal 1");
	if (data->i.count < 1)
		manage_error(1, "Invalid Map: There should be at least 1 C");	
	data->m.map = load_map(data->m.path, data->m.len, data->m.llen);
	load_img(data, &data->m.floor, IMG_PATH, "floor.xpm");
	load_img(data, &data->m.wall, IMG_PATH, "stone.xpm");
}
