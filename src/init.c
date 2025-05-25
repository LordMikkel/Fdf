/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:19:51 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/24 00:27:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_map(t_map *map)
{
	printf("2\n");
	map->points = NULL;
	map->width = 0;
	map->height = 0;
}

static void	init_img(t_img *img, t_fdf *data)
{
	img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
}

void	init_data(t_fdf *data)
{
	printf("1\n");
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	init_img(&data->img, data);
	init_map(&data->map);
}
