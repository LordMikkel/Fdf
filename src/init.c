/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:19:51 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 03:01:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_map(t_map *map)
{
	map->points = NULL;
	map->tokens = NULL;
	map->width = 0;
	map->height = 0;
}
int	init_data(t_fdf *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	init_map(&data->map);
	return (1);
}
