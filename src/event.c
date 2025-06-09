/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:16:43 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 21:36:31 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	handle_rotation_keys(int key, t_fdf *data)
{
	if (key == KEY_RIGHT)
		data->cam.beta += 0.05f;
	if (key == KEY_LEFT)
		data->cam.beta -= 0.05f;
	if (key == KEY_UP)
		data->cam.alpha += 0.05f;
	if (key == KEY_DOWN)
		data->cam.alpha -= 0.05f;
	if (key == KEY_Q)
		data->cam.gamma += 0.05f;
	if (key == KEY_W)
		data->cam.gamma -= 0.05f;
}

static void	handle_view_keys(int key, t_fdf *data)
{
	if (key == KEY_I)
		set_isometric_view(&data->cam);
	if (key == KEY_T)
		set_top_view(&data->cam);
	if (key == KEY_F)
		set_front_view(&data->cam);
	if (key == KEY_L)
		set_lateral_view(&data->cam);
	if (key == KEY_P)
		set_pov_view(&data->cam);
}

static void	handle_scale_keys(int key, t_fdf *data)
{
	if (key == KEY_PLUS1 || key == KEY_PLUS2)
		scale_map_z(data->map.points, data->map.width, data->map.height, 1.1f);
	if (key == KEY_MINUS1 || key == KEY_MINUS2)
		scale_map_z(data->map.points, data->map.width, data->map.height, 0.9f);
}

int	handle_key(int key, t_fdf *data)
{
	printf("key: %d\n", key);
	if (key == ESC_KEY)
		close_exit(data);
	handle_rotation_keys(key, data);
	handle_view_keys(key, data);
	handle_scale_keys(key, data);
	render_fdf(data, &data->map);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	printf("button: %d\n", button);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	if (button == ROTATE_RIGHT)
		data->cam.gamma += 0.05f;
	if (button == ROTATE_LEFT)
		data->cam.gamma -= 0.05f;
	if (button == ZOOM_IN)
		data->cam.zoom *= 1.1f;
	if (button == ZOOM_OUT)
		data->cam.zoom /= 1.1f;
	render_fdf(data, &data->map);
	return (0);
}
