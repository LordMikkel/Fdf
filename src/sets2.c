/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:23:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 21:03:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_isometric_view(t_cam *cam)
{
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->projection = ISOMETRIC;
}

void	set_pov_view(t_cam *cam)
{
	cam->alpha = PI / 10;
	cam->beta = 0;
	cam->gamma = 0;
	cam->projection = POV;
}
