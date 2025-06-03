/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:46:57 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/02 01:10:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	convert_point_to_int(t_point_2d *a, t_point_2d *b, t_point p1, t_point p2)
{
	a->x = (int)roundf(p1.x);
	a->y = (int)roundf(p1.y);
	b->x = (int)roundf(p2.x);
	b->y = (int)roundf(p2.y);
}

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.length + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_point p1, t_point p2, t_fdf *data)
{
	float	t;
	t_line	line;
	t_point_2d	a;
	t_point_2d	b;

	convert_point_to_int(&a, &b, p1, p2);
	init_line(&line, a, b);
	while (TRUE)
	{
		ft_mlx_put_pixel(data, a.x, a.y, DEFAULT_COLOR);
		if (a.x == b.x && a.y == b.y)
			break ;
		line.double_error = 2 * line.error;
		if (line.double_error > -line.dy)
		{
			line.error = line.error - line.dy;
			a.x += line.sx;
		}
		if (line.double_error < line.dx)
		{
			line.error = line.error + line.dx;
			a.y += line.sy;
		}
		t++;
	}
}
