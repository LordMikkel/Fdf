/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:16:43 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/02 00:02:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	handle_key(int key, t_fdf *data)
{
	printf("key: %d\n", key);
	if (key == ESC_KEY)
		close_exit(data);
	if (key == KEY_RIGHT)
		data->cam.gamma += 0.05f;
	if (key == KEY_LEFT)
		data->cam.gamma -= 0.05f;
	if (key == KEY_UP)
		data->cam.beta += 0.05f;
	if (key == KEY_DOWN)
		data->cam.beta -= 0.05f;
	mlx_clear_window(data->mlx, data->win);
	render_fdf(data, &data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	printf("button: %d\n", button);
	printf("pos x: %d\n", x);
	printf("pos y: %d\n", y);
	if (button == ZOOM_IN)
		data->cam.zoom += 0.05f;
	if (button == ZOOM_OUT)
		data->cam.zoom -= 0.05f;
	return (0);
}
