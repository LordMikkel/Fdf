/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_allocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:03:55 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:07:18 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static int	allocate_row_memory(t_map *map, int i)
{
	map->points[i] = ft_calloc(map->width, sizeof(t_point));
	if (!map->points[i])
		return (0);
	return (1);
}

int	allocate_points_map_memory(t_map *map)
{
	int	i;

	map->points = ft_calloc(map->height, sizeof(t_point *));
	if (!map->points)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!allocate_row_memory(map, i))
			return (0);
		i++;
	}
	return (1);
}
