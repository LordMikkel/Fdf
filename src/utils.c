/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:04:56 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/01 18:54:11 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	square(float x)
{
	float	square;

	square = x * x;
	return (square);
}

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.length + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}
