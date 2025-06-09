/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:32:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 21:26:03 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	move_map_to_origin(t_point *point, t_map map, t_cam cam)
{
	float	center_x;
	float	center_y;

	center_x = (map.width - 1) * cam.zoom / 2;
	center_y = (map.height - 1) * cam.zoom / 2;
	point->x -= center_x;
	point->y -= center_y;
}

static void	get_map_center(t_map map, float *cx, float *cy, float *cz)
{
	int		y;
	int		x;
	int		count;
	float	sum[3];

	y = 0;
	count = 0;
	ft_memset(sum, 0, sizeof((sum)));
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			sum[0] += map.points[y][x].x;
			sum[1] += map.points[y][x].y;
			sum[2] += map.points[y][x].z;
			count++;
			x++;
		}
		y++;
	}
	*cx = sum[0] / count;
	*cy = sum[1] / count;
	*cz = sum[2] / count;
}

void	move_map_to_origin_4d(t_point *point, t_map map, t_cam cam)
{
	float	center_x;
	float	center_y;
	float	center_z;

	get_map_center(map, &center_x, &center_y, &center_z);
	point->x -= center_x;
	point->y -= center_y;
	point->z -= center_z;
}
