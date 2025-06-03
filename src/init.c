/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:19:51 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/02 00:35:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_line(t_line *line, t_point_2d a, t_point_2d b)
{
	line->dx = abs(b.x - a.x);
	line->dy = abs(b.y - a.y);
	if (a.x < b.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (a.y < b.y)
		line->sy = 1;
	else
		line->sy = -1;
	line->error = line->dx - line->dy;
	line->color1 = a.color;
	line->color2 = b.color;
	if (line->dy > line->dx)
		line->steps = line->dy;
	else
		line->steps = line->dx;
}

void	init_cam(t_cam *cam, t_map *map)
{
	int	max_zoom_width;
	int	max_zoom_height;

	max_zoom_width = (WIN_WIDTH / map->width) / 2;
	max_zoom_height = (WIN_HEIGHT / map->height) / 2;
	cam->zoom = fmin(max_zoom_width, max_zoom_height);
	cam->x_offset = WIN_WIDTH / 2;
	cam->y_offset = WIN_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->projection = ISOMETRIC;
	printf("Succes Init Cam\n");
}

static void	init_map(t_map *map)
{
	map->points = NULL;
	map->width = 0;
	map->height = 0;
	printf("Succes Init Map\n");
}

static int	init_img(t_img *img, t_fdf *data)
{
	img->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->length, &img->endian);
	if (!img->addr)
		return (0);
	printf("Succes Init Image\n");
	return (1);
}

int	init_data(t_fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putstr_fd(ERR_MLX, STDERR), 0);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!data->win)
		return (ft_putstr_fd(ERR_MLX, STDERR), 0);
	printf("Succes Init Data\n");
	if (!init_img(&data->img, data))
		return (ft_putstr_fd(ERR_MLX, STDERR), 0);
	init_map(&data->map);
	return (1);
}
