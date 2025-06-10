/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:04:56 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 19:05:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	find_min_max_z(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->min_z = map->points[0][0].z;
	map->max_z = map->points[0][0].z;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->points[y][x].z < map->min_z)
				map->min_z = map->points[y][x].z;
			if (map->points[y][x].z > map->max_z)
				map->max_z = map->points[y][x].z;
			x++;
		}
		y++;
	}
}

float	square(float x)
{
	float	square;

	square = x * x;
	return (square);
}

int	diff_coords(t_point *a, t_point *b)
{
	int	diff;

	diff = 0;
	if (a->x != b->x)
		diff++;
	if (a->y != b->y)
		diff++;
	if (a->z != b->z)
		diff++;
	if (a->w != b->w)
		diff++;
	return (diff);
}

double	calculate_distance(t_point *p1, t_point *p2)
{
	double	dx;
	double	dy;
	double	dz;
	double	dw;

	dx = p1->x - p2->x;
	dy = p1->y - p2->y;
	dz = p1->z - p2->z;
	dw = p1->w - p2->w;
	return (sqrt(dx * dx + dy * dy + dz * dz + dw * dw));
}
