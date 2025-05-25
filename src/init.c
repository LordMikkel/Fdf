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

void	init_data(t_fdf *data)
{
	printf("1\n");
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	init_map(&data->map);
}
