/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:23:05 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/07 15:15:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_top_view(t_cam *cam)
{
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->projection = ORTHOGONAL;
}

void	set_front_view(t_cam *cam)
{
	cam->alpha = PI / 2;
	cam->beta = 0;
	cam->gamma = 0;
	cam->projection = ORTHOGONAL;
}

void	set_lateral_view(t_cam *cam)
{
	cam->alpha = PI / 2;
	cam->beta = PI / 2;
	cam->gamma = 0;
	cam->projection = ORTHOGONAL;
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
