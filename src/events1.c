/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:56:13 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/11 22:53:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	handle_3d_rotation_keys(int key, t_fdf *data)
{
	if (key == KEY_RIGHT)
		data->cam.beta += 0.05f;
	if (key == KEY_LEFT)
		data->cam.beta -= 0.05f;
	if (key == KEY_UP)
		data->cam.alpha += 0.05f;
	if (key == KEY_DOWN)
		data->cam.alpha -= 0.05f;
	if (key == KEY_MENOR)
		data->cam.gamma += 0.05f;
	if (key == KEY_MAYOR)
		data->cam.gamma -= 0.05f;
}

static void	handle_4d_rotation_keys(int key, t_fdf *data)
{
	if (key == KEY_A)
	{
		data->cam.epsilon -= 0.05f;
		data->cam.theta -= 0.05f;
	}
	if (key == KEY_D)
	{
		data->cam.epsilon += 0.05f;
		data->cam.theta += 0.05f;
	}
	if (key == KEY_W)
	{
		data->cam.delta -= 0.05f;
		data->cam.iota -= 0.05f;
	}
	if (key == KEY_S)
	{
		data->cam.delta += 0.05f;
		data->cam.iota += 0.05f;
	}
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
	handle_3d_rotation_keys(key, data);
	handle_4d_rotation_keys(key, data);
	handle_view_keys(key, data);
	handle_scale_keys(key, data);
	render_fdf(data, &data->map);
	return (0);
}
