/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:32:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:08:17 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	move_map_to_origin(t_point *point, t_map map, t_cam cam)
{
	float	center_x;
	float	center_y;

	center_x = (map.width - 1) * cam.zoom / 2;
	center_y = (map.height - 1) * cam.zoom / 2;
	point->x -= center_x;
	point->y -= center_y;
}
