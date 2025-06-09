/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:17:51 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 22:12:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	mlx_setup(t_fdf *data)
{
	mlx_hook(data->win, CLOSE_EVENT, NO_FILTER, close_exit, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, 5, 1L << 3, handle_mouse_release, data);
	mlx_hook(data->win, 6, 1L << 6, handle_mouse_move, data);
	mlx_hook(data->win, 12, 1L << 15, handle_expose, data);
	mlx_loop(data->mlx);
}

void	clear_image(t_fdf *data)
{
	int	total_bytes;

	mlx_clear_window(data->mlx, data->win);
	total_bytes = WIN_WIDTH * WIN_HEIGHT * (data->img.bpp / 8);
	ft_memset(data->img.addr, 0, total_bytes);
}
