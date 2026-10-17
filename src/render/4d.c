/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:58:39 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/17 21:37:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

int	check_4d_mode(const char *av, t_map *map)
{
	if (ft_strcmp(av, "pentachoron") == 0)
	{
		printf("4d mode activated\n");
		map->object = PENTACHORON;
		return (1);
	}
	else if (ft_strcmp(av, "tesseract") == 0)
	{
		printf("4d mode activated\n");
		map->object = TESSERACT;
		return (1);
	}
	else if (ft_strcmp(av, "hexacosicoron") == 0)
	{
		printf("4d mode activated\n");
		map->object = HEXACOSICORON;
		return (1);
	}
	return (0);
}

int	init_4d(t_map *map)
{
	map->type = OBJECT_4D;
	if (map->object == PENTACHORON)
	{
		if (!init_pentachoron(map))
			return (ft_putstr_fd(ERR_MEM, STDERR), 0);
		printf("Success init pentachoron\n");
	}
	else if (map->object == TESSERACT)
	{
		if (!init_tesseract(map))
			return (ft_putstr_fd(ERR_MEM, STDERR), 0);
		printf("Success init tesseract\n");
	}
	else if (map->object == HEXACOSICORON)
	{
		if (!init_hexacosicoron(map) || !build_hexa_edges(map))
			return (ft_putstr_fd(ERR_MEM, STDERR), 0);
		printf("Success init hexacosicoron\n");
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
	map->points[0][0] = (t_point){1, 1, 1, -1, DARK_ORANGE};
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

int	init_hexacosicoron(t_map *map)
{
	double	phi = 1.618033988749895;
	double	inv_phi = 0.618033988749895;
	int		idx;
	int		i;
	int		s1, s2, s3, s4;
	int		signs[4];
	double	coords[4];
	int		perms[24][4] = {
		{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1},
		{0, 3, 1, 2}, {0, 3, 2, 1}, {1, 0, 2, 3}, {1, 0, 3, 2},
		{1, 2, 0, 3}, {1, 2, 3, 0}, {1, 3, 0, 2}, {1, 3, 2, 0},
		{2, 0, 1, 3}, {2, 0, 3, 1}, {2, 1, 0, 3}, {2, 1, 3, 0},
		{2, 3, 0, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 0, 2, 1},
		{3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0}
	};

	map->height = 1;
	map->width = 600;
	map->points = ft_calloc(1, sizeof(t_point *));
	if (!map->points)
		return (0);
	map->points[0] = ft_calloc(600, sizeof(t_point));
	if (!map->points[0])
		return (0);
	idx = 0;

	// Grupo 1: (±1, ±1, ±1, ±1) - 16 puntos
	s1 = 0;
	while (s1 < 2)
	{
		s2 = 0;
		while (s2 < 2)
		{
			s3 = 0;
			while (s3 < 2)
			{
				s4 = 0;
				while (s4 < 2)
				{
					signs[0] = (s1 == 0) ? -1 : 1;
					signs[1] = (s2 == 0) ? -1 : 1;
					signs[2] = (s3 == 0) ? -1 : 1;
					signs[3] = (s4 == 0) ? -1 : 1;
					map->points[0][idx] = (t_point){
						signs[0] * 1.0,
						signs[1] * 1.0,
						signs[2] * 1.0,
						signs[3] * 1.0,
						PURPLE
					};
					idx++;
					s4++;
				}
				s3++;
			}
			s2++;
		}
		s1++;
	}

	// Grupo 2: (0, ±1/φ, ±1, ±φ) y permutaciones - 96 puntos
	coords[0] = 0.0; coords[1] = inv_phi; coords[2] = 1.0; coords[3] = phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GREEN
		};
		idx++;
		i++;
	}
	coords[0] = 0.0; coords[1] = inv_phi; coords[2] = 1.0; coords[3] = -phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GREEN
		};
		idx++;
		i++;
	}
	coords[0] = 0.0; coords[1] = inv_phi; coords[2] = -1.0; coords[3] = phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GREEN
		};
		idx++;
		i++;
	}
	coords[0] = 0.0; coords[1] = inv_phi; coords[2] = -1.0; coords[3] = -phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GREEN
		};
		idx++;
		i++;
	}

	// Grupo 3: (±1/φ, 0, ±φ, ±1) y permutaciones - 96 puntos
	coords[0] = inv_phi; coords[1] = 0.0; coords[2] = phi; coords[3] = 1.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], MINT
		};
		idx++;
		i++;
	}
	coords[0] = inv_phi; coords[1] = 0.0; coords[2] = phi; coords[3] = -1.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], MINT
		};
		idx++;
		i++;
	}
	coords[0] = inv_phi; coords[1] = 0.0; coords[2] = -phi; coords[3] = 1.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], MINT
		};
		idx++;
		i++;
	}
	coords[0] = inv_phi; coords[1] = 0.0; coords[2] = -phi; coords[3] = -1.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], MINT
		};
		idx++;
		i++;
	}

	// Grupo 4: (±1, ±φ, 0, ±1/φ) y permutaciones - 96 puntos
	coords[0] = 1.0; coords[1] = phi; coords[2] = 0.0; coords[3] = inv_phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], AZURE
		};
		idx++;
		i++;
	}
	coords[0] = 1.0; coords[1] = phi; coords[2] = 0.0; coords[3] = -inv_phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], AZURE
		};
		idx++;
		i++;
	}
	coords[0] = 1.0; coords[1] = -phi; coords[2] = 0.0; coords[3] = inv_phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], AZURE
		};
		idx++;
		i++;
	}
	coords[0] = 1.0; coords[1] = -phi; coords[2] = 0.0; coords[3] = -inv_phi;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], AZURE
		};
		idx++;
		i++;
	}

	// Grupo 5: (±φ, ±1, ±1/φ, 0) y permutaciones - 96 puntos
	coords[0] = phi; coords[1] = 1.0; coords[2] = inv_phi; coords[3] = 0.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GOLD
		};
		idx++;
		i++;
	}
	coords[0] = phi; coords[1] = 1.0; coords[2] = -inv_phi; coords[3] = 0.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GOLD
		};
		idx++;
		i++;
	}
	coords[0] = phi; coords[1] = -1.0; coords[2] = inv_phi; coords[3] = 0.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GOLD
		};
		idx++;
		i++;
	}
	coords[0] = phi; coords[1] = -1.0; coords[2] = -inv_phi; coords[3] = 0.0;
	i = 0;
	while (i < 24)
	{
		map->points[0][idx] = (t_point){
			coords[perms[i][0]], coords[perms[i][1]],
			coords[perms[i][2]], coords[perms[i][3]], GOLD
		};
		idx++;
		i++;
	}

	// Grupo 6: (±1/φ, ±1/φ, ±1/φ, ±φ) - 32 puntos
	s1 = 0;
	while (s1 < 2)
	{
		s2 = 0;
		while (s2 < 2)
		{
			s3 = 0;
			while (s3 < 2)
			{
				s4 = 0;
				while (s4 < 2)
				{
					signs[0] = (s1 == 0) ? -1 : 1;
					signs[1] = (s2 == 0) ? -1 : 1;
					signs[2] = (s3 == 0) ? -1 : 1;
					signs[3] = (s4 == 0) ? -1 : 1;
					map->points[0][idx] = (t_point){
						signs[0] * inv_phi,
						signs[1] * inv_phi,
						signs[2] * inv_phi,
						signs[3] * phi,
						TOMATO
					};
					idx++;
					map->points[0][idx] = (t_point){
						signs[3] * phi,
						signs[2] * inv_phi,
						signs[1] * inv_phi,
						signs[0] * inv_phi,
						TOMATO
					};
					idx++;
					s4++;
				}
				s3++;
			}
			s2++;
		}
		s1++;
	}

	// Grupo 7: (±1/φ, ±1/φ, ±φ, ±1/φ) - 32 puntos
	s1 = 0;
	while (s1 < 2)
	{
		s2 = 0;
		while (s2 < 2)
		{
			s3 = 0;
			while (s3 < 2)
			{
				s4 = 0;
				while (s4 < 2)
				{
					signs[0] = (s1 == 0) ? -1 : 1;
					signs[1] = (s2 == 0) ? -1 : 1;
					signs[2] = (s3 == 0) ? -1 : 1;
					signs[3] = (s4 == 0) ? -1 : 1;
					map->points[0][idx] = (t_point){
						signs[0] * inv_phi,
						signs[1] * inv_phi,
						signs[2] * phi,
						signs[3] * inv_phi,
						COLOR_HIGH
					};
					idx++;
					map->points[0][idx] = (t_point){
						signs[2] * phi,
						signs[3] * inv_phi,
						signs[0] * inv_phi,
						signs[1] * inv_phi,
						COLOR_HIGH
					};
					idx++;
					s4++;
				}
				s3++;
			}
			s2++;
		}
		s1++;
	}

	// Grupo 8: (±1/φ, ±φ, ±1/φ, ±1/φ) - 32 puntos
	s1 = 0;
	while (s1 < 2)
	{
		s2 = 0;
		while (s2 < 2)
		{
			s3 = 0;
			while (s3 < 2)
			{
				s4 = 0;
				while (s4 < 2)
				{
					signs[0] = (s1 == 0) ? -1 : 1;
					signs[1] = (s2 == 0) ? -1 : 1;
					signs[2] = (s3 == 0) ? -1 : 1;
					signs[3] = (s4 == 0) ? -1 : 1;
					map->points[0][idx] = (t_point){
						signs[0] * inv_phi,
						signs[1] * phi,
						signs[2] * inv_phi,
						signs[3] * inv_phi,
						CYAN
					};
					idx++;
					map->points[0][idx] = (t_point){
						signs[1] * phi,
						signs[0] * inv_phi,
						signs[3] * inv_phi,
						signs[2] * inv_phi,
						CYAN
					};
					idx++;
					s4++;
				}
				s3++;
			}
			s2++;
		}
		s1++;
	}

	// Grupo 9: (±φ, ±1/φ, ±1/φ, ±1/φ) - 32 puntos
	s1 = 0;
	while (s1 < 2)
	{
		s2 = 0;
		while (s2 < 2)
		{
			s3 = 0;
			while (s3 < 2)
			{
				s4 = 0;
				while (s4 < 2)
				{
					signs[0] = (s1 == 0) ? -1 : 1;
					signs[1] = (s2 == 0) ? -1 : 1;
					signs[2] = (s3 == 0) ? -1 : 1;
					signs[3] = (s4 == 0) ? -1 : 1;
					map->points[0][idx] = (t_point){
						signs[0] * phi,
						signs[1] * inv_phi,
						signs[2] * inv_phi,
						signs[3] * inv_phi,
						COLOR_LOW
					};
					idx++;
					map->points[0][idx] = (t_point){
						signs[0] * phi,
						signs[2] * inv_phi,
						signs[3] * inv_phi,
						signs[1] * inv_phi,
						COLOR_LOW
					};
					idx++;
					s4++;
				}
				s3++;
			}
			s2++;
		}
		s1++;
	}

	return (1);
}
