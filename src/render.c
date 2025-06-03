/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:43:07 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/02 00:08:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	render_map(t_fdf *data, t_map *map)
{
	int			x;
	int			y;
	t_point		a;
	t_point		b;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			a = project_point(map->points[y][x], data->cam);
			if (x + 1 < map->width)
			{
				b = project_point(map->points[y][x + 1], data->cam);
				draw_line(a, b, data);
			}
			if (y + 1 < map->height)
			{
				b = project_point(map->points[y + 1][x], data->cam);
				draw_line(a, b, data);
			}
		}
	}
}

void	render_fdf(t_fdf *data, t_map *map)
{
	mlx_clear_window(data->mlx, data->win);
	render_map(data, map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
