/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_4d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:26:03 by migarrid          #+#    #+#             */
/*   Updated: 2025/07/06 00:42:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	rotate_xy(float *x, float *y, float angle)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle) - prev_y * sin(angle);
	*y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	rotate_xz(float *x, float *z, float angle)
{
	float	prev_x;
	float	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(angle) - prev_z * sin(angle);
	*z = prev_x * sin(angle) + prev_z * cos(angle);
}

void	rotate_yw(float *y, float *w, float angle)
{
	float	prev_y;
	float	prev_w;

	prev_y = *y;
	prev_w = *w;
	*y = prev_y * cos(angle) - prev_w * sin(angle);
	*w = prev_y * sin(angle) + prev_w * cos(angle);
}

void	rotate_zw(float *z, float *w, float angle)
{
	float	prev_z;
	float	prev_w;

	prev_z = *z;
	prev_w = *w;
	*z = prev_z * cos(angle) - prev_w * sin(angle);
	*w = prev_z * sin(angle) + prev_w * cos(angle);
}
