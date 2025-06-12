/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:58:25 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:44:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static void	get_angles(t_fdf *data, int angles[3])
{
	angles[0] = (int)(data->cam.alpha * 180 / PI) % 360;
	angles[1] = (int)(data->cam.beta * 180 / PI) % 360;
	angles[2] = (int)(data->cam.gamma * 180 / PI) % 360;
	if (angles[0] < 0)
		angles[0] += 360;
	if (angles[1] < 0)
		angles[1] += 360;
	if (angles[2] < 0)
		angles[2] += 360;
}

void	put_angle_info(t_fdf *data, int x, int *y, int step)
{
	int		angles[3];
	char	*str;

	get_angles(data, angles);
	mlx_string_put(data->mlx, data->win, x + 40, *y, SAND, "Alpha: ");
	str = ft_itoa(angles[0]);
	mlx_string_put(data->mlx, data->win, x + 100, *y, SAND, str);
	free(str);
	mlx_string_put(data->mlx, data->win, x + 120, *y, SAND, "°");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 40, *y, SAND, "Beta: ");
	str = ft_itoa(angles[1]);
	mlx_string_put(data->mlx, data->win, x + 100, *y, SAND, str);
	free(str);
	mlx_string_put(data->mlx, data->win, x + 120, *y, SAND, "°");
	*y += step;
	mlx_string_put(data->mlx, data->win, x + 40, *y, SAND, "Gamma: ");
	str = ft_itoa(angles[2]);
	mlx_string_put(data->mlx, data->win, x + 100, *y, SAND, str);
	free(str);
	mlx_string_put(data->mlx, data->win, x + 120, *y, SAND, "°");
}

void	put_zoom_info(t_fdf *data, int x, int *y)
{
	int		zoom;
	char	*str;

	zoom = (int)((data->cam.zoom / data->map.width * data->map.height) * 100);
	mlx_string_put(data->mlx, data->win, x + 40, *y, SAND, "Level: ");
	str = ft_itoa(zoom);
	mlx_string_put(data->mlx, data->win, x + 100, *y, SAND, str);
	free(str);
	mlx_string_put(data->mlx, data->win, x + 120, *y, SAND, "%");
}
