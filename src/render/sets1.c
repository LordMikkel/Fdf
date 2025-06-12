/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:23:05 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:08:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	set_top_view(t_cam *cam)
{
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->delta = 0;
	cam->epsilon = 0;
	cam->theta = 0;
	cam->iota = 0;
	cam->projection = ORTHOGONAL;
}

void	set_front_view(t_cam *cam)
{
	cam->alpha = PI / 2;
	cam->beta = 0;
	cam->gamma = 0;
	cam->delta = 0;
	cam->epsilon = 0;
	cam->theta = 0;
	cam->iota = 0;
	cam->projection = ORTHOGONAL;
}

void	set_lateral_view(t_cam *cam)
{
	cam->alpha = PI / 2;
	cam->beta = PI / 2;
	cam->gamma = 0;
	cam->delta = 0;
	cam->epsilon = 0;
	cam->theta = 0;
	cam->iota = 0;
	cam->projection = ORTHOGONAL;
}
