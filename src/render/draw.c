/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:46:57 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/17 19:32:54 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

int	is_on_screen(int x, int y)
{
	return (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT);
}

void	ft_mlx_put_pixel(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.length + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	conv_point_to_int(t_point_2d *a, t_point_2d *b, t_point p1, t_point p2)
{
	a->x = (int)roundf(p1.x);
	a->y = (int)roundf(p1.y);
	a->color = p1.color;
	b->x = (int)roundf(p2.x);
	b->y = (int)roundf(p2.y);
	b->color = p2.color;
}

void	draw_line(t_point p1, t_point p2, t_fdf *data)
{
	t_point_2d	a;
	t_point_2d	b;
	t_line		line;

	if (!is_on_screen(p1.x, p1.y) && !is_on_screen(p2.x, p2.y))
		return ;
	conv_point_to_int(&a, &b, p1, p2);
	init_line(&line, a, b);
	while (TRUE)
	{
		line.mix_c = interpolate_color(line.c1, line.c2, line.t / line.steps);
		ft_mlx_put_pixel(data, a.x, a.y, line.mix_c);
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
		line.t++;
	}
}
