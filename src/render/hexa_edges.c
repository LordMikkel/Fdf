/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:32:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:08:17 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static int	is_hexa_edge(t_map *map, int i, int j)
{
	double	dist;

	dist = calculate_distance(&map->points[0][i], &map->points[0][j]);
	return (dist > 2 && dist < 2.5);
}

static int	scan_edges(t_map *map, int fill)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = -1;
	while (++i < map->width)
	{
		j = i;
		while (++j < map->width)
		{
			if (is_hexa_edge(map, i, j))
			{
				if (fill)
				{
					map->edges[2 * n] = i;
					map->edges[2 * n + 1] = j;
				}
				n++;
			}
		}
	}
	return (n);
}

static void	build_canon(t_map *map, int *canon)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->width)
	{
		canon[i] = i;
		j = -1;
		while (++j < i && canon[i] == i)
		{
			if (diff_coords(&map->points[0][i], &map->points[0][j]) == 0)
				canon[i] = j;
		}
	}
}

static int	keep_last_unique(t_map *map, const int *canon, char *seen)
{
	int	e;
	int	n;
	int	key;

	e = map->n_edges;
	n = map->n_edges;
	while (--e >= 0)
	{
		key = canon[map->edges[2 * e]] * map->width
			+ canon[map->edges[2 * e + 1]];
		if (!seen[key])
		{
			seen[key] = 1;
			n--;
			map->edges[2 * n] = map->edges[2 * e];
			map->edges[2 * n + 1] = map->edges[2 * e + 1];
		}
	}
	return (n);
}

int	build_hexa_edges(t_map *map)
{
	int		canon[HEXA_VERTICES];
	char	*seen;
	int		start;

	map->n_edges = scan_edges(map, FALSE);
	map->edges = ft_calloc(map->n_edges * 2, sizeof(int));
	if (!map->edges)
		return (0);
	scan_edges(map, TRUE);
	seen = ft_calloc(map->width * map->width, sizeof(char));
	if (!seen)
		return (0);
	build_canon(map, canon);
	start = keep_last_unique(map, canon, seen);
	free(seen);
	map->n_edges -= start;
	ft_memmove(map->edges, map->edges + 2 * start,
		map->n_edges * 2 * sizeof(int));
	return (1);
}
