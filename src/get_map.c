/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:09:38 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/22 17:21:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_point	**fill_map(t_map *map)
{
	t_point	**points;

	while (map)
	{
		points = calloc(1, sizeof(t_point));
		if (!points)
			return (NULL);
	}
}

t_map	*get_map(char *file)
{
	int		fd;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->points = fill_map(map);
	if (!map->points)
		return (NULL);
	close(fd);
	return (map);
}
