/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:48:13 by migarrid          #+#    #+#             */
/*   Updated: 2025/07/11 18:13:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static void	project_3d_to_2d(t_point *point, int projection)
{
	float	iso_x;
	float	iso_y;
	float	distance;
	float	factor;

	if (projection == ISOMETRIC)
	{
		iso_x = (point->x - point->y) * cos(DEFAULT_ANG);
		iso_y = (point->x + point->y) * sin(DEFAULT_ANG) - point->z;
		point->x = iso_x;
		point->y = iso_y;
	}
	else if (projection == POV)
	{
		distance = 500.0f;
		factor = distance / (distance - point->z);
		point->x = point->x * factor;
		point->y = point->y * factor;
	}
}

static void	project_4d_to_3d(t_point *point)
{
	float	distance;
	float	factor;

	distance = 5.0f;
	factor = distance / (distance - point->w);
	point->x = point->x * factor;
	point->y = point->y * factor;
	point->z = point->z * factor;
}

t_point	project_point(t_point point, t_map map, t_cam cam)
{
	if (map.type == OBJECT_4D)
	{
		rotate_xy(&point.x, &point.y, cam.delta);
		rotate_xz(&point.x, &point.z, cam.epsilon);
		rotate_yw(&point.y, &point.w, cam.theta);
		rotate_zw(&point.z, &point.w, cam.iota);
		project_4d_to_3d(&point);
	}
	point.x = point.x * cam.zoom;
	point.y = point.y * cam.zoom;
	point.z = point.z * cam.zoom;
	if (map.type == OBJECT_3D)
		move_map_to_origin(&point, map, cam);
	rotate_x(&point.y, &point.z, cam.alpha);
	rotate_y(&point.x, &point.z, cam.beta);
	rotate_z(&point.x, &point.y, cam.gamma);
	project_3d_to_2d(&point, cam.projection);
	point.x = point.x + cam.x_offset;
	point.y = point.y + cam.y_offset;
	return (point);
}
