/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:43:07 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/13 02:22:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	render_3d_map(t_fdf *data, t_map *map)
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
			a = project_point(map->points[y][x], data->map, data->cam);
			if (x + 1 < map->width - 1)
			{
				b = project_point(map->points[y][x + 1], data->map, data->cam);
				draw_line(a, b, data);
			}
			if (y + 1 < map->height && x < map->width - 1)
			{
				b = project_point(map->points[y + 1][x], data->map, data->cam);
				draw_line(a, b, data);
			}
		}
	}
}

void	render_pentachoron_edges(t_fdf *data, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	i = 0;
	while (i < 5)
	{
		j = i + 1;
		p1 = project_point(map->points[0][i], *map, data->cam);
		while (j < 5)
		{
			p2 = project_point(map->points[0][j], *map, data->cam);
			draw_line(p1, p2, data);
			j++;
		}
		i++;
	}
}

void	render_tesseract_edges(t_fdf *data, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	i = 0;
	while (i < 16)
	{
		j = i + 1;
		p1 = project_point(map->points[0][i], *map, data->cam);
		while (j < 16)
		{
			p2 = project_point(map->points[0][j], *map, data->cam);
			if (diff_coords(&map->points[0][i], &map->points[0][j]) == 1)
				draw_line(p1, p2, data);
			j++;
		}
		i++;
	}
}

void	render_hexacosicoron_edges(t_fdf *data, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;
	double	dist;

	i = 0;
	while (i < 600)
	{
		j = i + 1;
		p1 = project_point(map->points[0][i], *map, data->cam);
		while (j < 600)
		{
			dist = calculate_distance(&map->points[0][i], &map->points[0][j]);
			if (dist > 0.4 && dist < 0.9)
			{
				p2 = project_point(map->points[0][j], *map, data->cam);
				draw_line(p1, p2, data);
			}
			j++;
		}
		i++;
	}
}

void	render_fdf(t_fdf *data, t_map *map)
{
	clear_image(data);
	if (map->type == OBJECT_3D)
		render_3d_map(data, map);
	else if (map->type == OBJECT_4D)
	{
		if (map->object == PENTACHORON)
			render_pentachoron_edges(data, map);
		else if (map->object == TESSERACT)
			render_tesseract_edges(data, map);
		else if (map->object == HEXACOSICORON)
			render_hexacosicoron_edges(data, map);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	draw_menu(data);
}
