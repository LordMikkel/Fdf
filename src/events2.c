/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:56:25 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 22:13:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	handle_expose(t_fdf *data)
{
	render_fdf(data, &data->map);
	return (0);
}

int	handle_mouse_move(int x, int y, t_fdf *data)
{
	if (data->dragging)
	{
		data->cam.x_offset += x - data->last_mouse_x;
		data->cam.y_offset += y - data->last_mouse_y;
		data->last_mouse_x = x;
		data->last_mouse_y = y;
		render_fdf(data, &data->map);
	}
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_fdf *data)
{
	if (button == 1)
		data->dragging = 0;
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	if (button == ROTATE_RIGHT)
		data->cam.gamma += 0.05f;
	if (button == ROTATE_LEFT)
		data->cam.gamma -= 0.05f;
	if (button == ZOOM_IN)
		data->cam.zoom *= 1.1f;
	if (button == ZOOM_OUT)
		data->cam.zoom /= 1.1f;
	if (button == 1)
	{
		data->dragging = 1;
		data->last_mouse_x = x;
		data->last_mouse_y = y;
	}
	render_fdf(data, &data->map);
	return (0);
}
