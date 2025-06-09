/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:31:12 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 21:31:17 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	interpolate_color(int color1, int color2, float t)
{
	t_color	c;

	c.r1 = (color1 >> 16) & 0xFF;
	c.g1 = (color1 >> 8) & 0xFF;
	c.b1 = (color1) & 0xFF;
	c.r2 = (color2 >> 16) & 0xFF;
	c.g2 = (color2 >> 8) & 0xFF;
	c.b2 = (color2) & 0xFF;
	c.r = c.r1 + (int)((c.r2 - c.r1) * t);
	c.g = c.g1 + (int)((c.g2 - c.g1) * t);
	c.b = c.b1 + (int)((c.b2 - c.b1) * t);
	return ((c.r << 16) | (c.g << 8) | c.b);
}

int	assign_height_color(t_point *point, t_map *map)
{
	float	t;

	if (map->min_z == 0 && map->max_z == 0)
		find_min_max_z(map);
	t = (point->z - map->min_z) / (float)(map->max_z - map->min_z);
	if (t < 0.7)
		return (interpolate_color(COLOR_LOW, COLOR_MID, t * 2));
	else
		return (interpolate_color(COLOR_MID, COLOR_HIGH, (t - 0.5) * 2));
}
