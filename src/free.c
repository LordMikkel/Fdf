/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:05:48 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/22 16:54:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	free_graphics(t_fdf *data)
{
	if (!data)
		return ;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->addr)
		free(data->addr);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

static void	free_map_points(t_map *map)
{
	int	i;

	if (!map || !map->points)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->points[i])
			free(map->points[i]);
		i++;
	}
	free(map->points);
	map->points = NULL;
}

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_map_points(map);
	free(map);
}

void	free_data(t_fdf *data)
{
	if (!data)
		return ;
	free_map(data->map);
	free_graphics(data);
	free(data);
}
