/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:58:39 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 19:08:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_4d_mode(const char *av, t_map *map)
{
	if (ft_strcmp(av, "pentachoron") == 0)
	{
		map->object = PENTACHORON;
		return (1);
	}
	else if (ft_strcmp(av, "tesseract") == 0)
	{
		map->object = TESSERACT;
		return (1);
	}
	return (0);
}

int	init_4d(const char *av, t_map *map)
{
	map->type = OBJECT_4D;
	if (map->object == PENTACHORON)
	{
		if (!init_pentachoron(map))
			return (0);
	}
	else if (map->object == TESSERACT)
	{
		if (!init_tesseract(map))
			return (0);
	}
	return (1);
}

int	init_pentachoron(t_map *map)
{
	map->height = 1;
	map->width = 5;
	map->points = ft_calloc(1, sizeof(t_point *));
	if (!map->points)
		return (0);
	map->points[0] = ft_calloc(5, sizeof(t_point));
	if (!map->points[0])
		return (0);
	map->points[0][0] = (t_point){1, 1, 1, -1, RED_ORANGE};
	map->points[0][1] = (t_point){1, -1, -1, -1, DARK_ORANGE};
	map->points[0][2] = (t_point){-1, 1, -1, 1, ORANGE};
	map->points[0][3] = (t_point){-1, -1, 1, 1, GOLD};
	map->points[0][4] = (t_point){0, 0, 0, -2, TOMATO};
	return (1);
}

int	init_tesseract(t_map *map)
{
	map->height = 1;
	map->width = 16;
	map->points = ft_calloc(1, sizeof(t_point *));
	if (!map->points)
		return (0);
	map->points[0] = ft_calloc(16, sizeof(t_point));
	if (!map->points[0])
		return (0);
	map->points[0][0] = (t_point){-1, -1, -1, -1, PURPLE};
	map->points[0][1] = (t_point){-1, -1, -1, 1, GREEN};
	map->points[0][2] = (t_point){-1, -1, 1, -1, PURPLE};
	map->points[0][3] = (t_point){-1, -1, 1, 1, GREEN};
	map->points[0][4] = (t_point){-1, 1, -1, -1, PURPLE};
	map->points[0][5] = (t_point){-1, 1, -1, 1, MINT};
	map->points[0][6] = (t_point){-1, 1, 1, -1, AZURE};
	map->points[0][7] = (t_point){-1, 1, 1, 1, MINT};
	map->points[0][8] = (t_point){1, -1, -1, -1, AZURE};
	map->points[0][9] = (t_point){1, -1, -1, 1, MINT};
	map->points[0][10] = (t_point){1, -1, 1, -1, AZURE};
	map->points[0][11] = (t_point){1, -1, 1, 1, GREEN};
	map->points[0][12] = (t_point){1, 1, -1, -1, PURPLE};
	map->points[0][13] = (t_point){1, 1, -1, 1, GREEN};
	map->points[0][14] = (t_point){1, 1, 1, -1, PURPLE};
	map->points[0][15] = (t_point){1, 1, 1, 1, GREEN};
	return (1);
}
