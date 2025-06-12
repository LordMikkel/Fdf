/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:23:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:08:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	set_isometric_view(t_cam *cam)
{
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->delta = 0;
	cam->epsilon = 0;
	cam->theta = 0;
	cam->iota = 0;
	cam->projection = ISOMETRIC;
}

void	set_pov_view(t_cam *cam)
{
	cam->alpha = PI / 10;
	cam->beta = 0;
	cam->gamma = 0;
	cam->delta = 0;
	cam->epsilon = 0;
	cam->theta = 0;
	cam->iota = 0;
	cam->projection = POV;
}

void	scale_map_z(t_point **points, int width, int height, float scale)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			points[y][x].z *= scale;
			x++;
		}
		y++;
	}
}
