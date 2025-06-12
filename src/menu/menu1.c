/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:37:47 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:33:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static void	put_rotation_controls(t_fdf *data, int x, int *y, int step)
{
	*y += step * 2;
	mlx_string_put(data->mlx, data->win, x, *y, AZURE, "CONTROLS");
	*y += step;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "3D Rotation:");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "X: < / >");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "Y: Up / Down");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "Z: Left / Right");
	*y += step * 2;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "4D Rotation:");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "WX: A / D");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "WY: W / S");
}

static void	put_view_controls(t_fdf *data, int x, int *y, int step)
{
	*y += step * 2;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "Views:");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "Iso: I");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "Top: T");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "Front: F");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "Side: L");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "POV: P");
}

static void	put_scale_and_mouse_controls(t_fdf *data, int x, int *y, int step)
{
	*y += step * 2;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "Scale:");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND, "+ / -: Zoom & Z");
	*y += step * 2;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "Mouse:");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND,
		"Zoom: Vertical scroll");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 20, *y, SAND,
		"Rotation: Lateral scroll");
	*y += step * 2;
}

static void	put_stats(t_fdf *data, int x, int *y, int step)
{
	*y += step;
	mlx_string_put(data->mlx, data->win, x, *y, DARK_GREEN, "FDF");
	*y += step * 2;
	mlx_string_put(data->mlx, data->win, x, *y, AZURE, "STATS:");
	*y += step;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "Angles:");
	*y += step;
	put_angle_info(data, x, y, step);
	*y += step;
	mlx_string_put(data->mlx, data->win, x, *y, PURPLE, "Zoom:");
	*y += step;
	put_zoom_info(data, x, y);
}

void	draw_menu(t_fdf *data)
{
	int		x;
	int		y;
	int		step;

	x = 20;
	y = 20;
	step = 20;
	put_stats(data, x, &y, step);
	put_rotation_controls(data, x, &y, step);
	put_view_controls(data, x, &y, step);
	put_scale_and_mouse_controls(data, x, &y, step);
	mlx_string_put(data->mlx, data->win, x, y, PURPLE, "Exit: ESC");
}
