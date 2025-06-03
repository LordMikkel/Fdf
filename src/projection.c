/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 02:48:13 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/02 00:10:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	project_3d_to_2d(t_point *point, int projection)
{
	float	radius;
	float	theta;
	float	phi;
	float	iso_x;
	float	iso_y;

	if (projection == ISOMETRIC)
	{
		iso_x = (point->x - point->y) * cos(DEFAULT_ANG);
		iso_y = (point->x + point->y) * sin(DEFAULT_ANG) - point->z;
		point->x = iso_x;
		point->y = iso_y;
	}
	else if (projection == PARALEL)
	{
	}
	else if (projection == SPERICHAL)
	{
		radius = sqrtf(square(point->x) + square(point->y) + square(point->z));
		theta = atan2f(point->y, point->x);
		phi = acosf(point->z / (radius + 0.0001f));
		point->x = radius * sinf(phi) * cosf(theta);
		point->y = radius * sinf(phi) * sinf(theta);
	}
}

void	project_4d_to_3d(t_point *point)
{
	float	distance;
	float	factor;

	distance = 5.0f;
	if (point->w != 0.0f)
	{
		factor = distance / (distance - point->w);
		point->x = point->x * factor;
		point->y = point->y * factor;
		point->z = point->z * factor;
	}
}

t_point	project_point(t_point point, t_cam cam)
{
	point.x = point.x * cam.zoom;
	point.y = point.y * cam.zoom;
	point.z = point.z * cam.zoom;
	project_4d_to_3d(&point);
	rotate_x(&point.y, &point.z, cam.alpha);
	rotate_y(&point.x, &point.z, cam.beta);
	rotate_z(&point.x, &point.y, cam.gamma);
	project_3d_to_2d(&point, cam.projection);
	point.x = point.x + cam.x_offset;
	point.y = point.y + cam.y_offset;
	return (point);
}
