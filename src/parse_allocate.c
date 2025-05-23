/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_allocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:03:55 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 00:21:03 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	allocate_row_memory(t_map *map, int i)
{
	map->points[i] = ft_calloc(map->width, sizeof(t_point));
	map->colors[i] = ft_calloc(map->width, sizeof(int));
	if (!map->points[i] || !map->colors[i])
		return (0);
	return (1);
}

int	allocate_map_memory(t_map *map)
{
	int	i;

	map->points = ft_calloc(map->height, sizeof(t_point *));
	map->colors = ft_calloc(map->height, sizeof(int *));
	if (!map->points || !map->colors)
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
