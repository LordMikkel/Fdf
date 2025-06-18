/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:19:51 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/17 21:36:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

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
	line->c1 = a.color;
	line->c2 = b.color;
	line->steps = ft_max(line->dx, line->dy);
	line->t = 0;
}

void	init_cam(t_cam *cam, t_map *map)
{
	int		max_zoom_w;
	int		maz_zoom_h;
	int		max_zoom_d;
	int		z_range;
	float	center_z;

	ft_memset(&cam->zoom, 0, sizeof(float) * 11);
	find_min_max_z(map);
	z_range = map->max_z - map->min_z;
	if (z_range == 0)
		z_range = 1;
	max_zoom_w = (WIN_WIDTH / map->width) / 1.8;
	maz_zoom_h = (WIN_HEIGHT / map->height) / 1.8;
	max_zoom_d = ((WIN_HEIGHT / (z_range)) / 1.8);
	center_z = (map->max_z + map->min_z) / 3;
	cam->zoom = fmax(1, fmin(fmin(max_zoom_w, maz_zoom_h), max_zoom_d));
	cam->x_offset = (WIN_WIDTH / 2) + MENU_SIZE;
	cam->y_offset = ((WIN_HEIGHT / 2) + center_z * cam->zoom);
	if (map->object == PENTACHORON)
		cam->zoom = (WIN_WIDTH / 6);
	else if (map->object == TESSERACT)
		cam->zoom = (WIN_WIDTH / 8);
	else if (map->object == HEXACOSICORON)
		cam->zoom = (WIN_WIDTH / 7);
	cam->projection = ISOMETRIC;
}

static void	init_map(t_map *map)
{
	map->points = NULL;
	map->width = 0;
	map->height = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->type = 0;
	map->object = 0;
	map->error = FALSE;
	printf("Success Init Map\n");
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
	printf("Success Init Image\n");
	return (1);
}

int	init_data(t_fdf *data)
{
	data->dragging = 0;
	data->last_mouse_x = 0;
	data->last_mouse_y = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putstr_fd(ERR_MLX, STDERR), 0);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!data->win)
		return (ft_putstr_fd(ERR_MLX, STDERR), 0);
	printf("Success Init Data\n");
	if (!init_img(&data->img, data))
		return (ft_putstr_fd(ERR_MLX, STDERR), 0);
	init_map(&data->map);
	return (1);
}
