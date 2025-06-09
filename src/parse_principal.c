/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_principal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 20:08:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	is_valid_ext(const char *filename)
{
	const char	*dot;

	if (!filename)
		return (0);
	dot = ft_strchr(filename, '.');
	if (!dot)
		return (0);
	if (ft_strcmp(dot, ".fdf") == 0)
		return (1);
	return (0);
}

int	parse_map(const char *filename, t_map *map)
{
	int	fd;

	map->type = OBJECT_3D;
	if (!is_valid_ext(filename))
		return (ft_putstr_fd(ERR_EXT, STDERR), 0);
	printf("Valiid Ext file\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(ERR_OPEN, STDERR), 0);
	if (!calculate_dimensions(fd, map))
		return (0);
	printf("Calculated dimanesions\n");
	close(fd);
	if (!allocate_points_map_memory(map))
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	printf("Allocated Memory\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(ERR_OPEN, STDERR), 0);
	if (!parse_values(fd, map))
		return (0);
	printf("Parsed values\n");
	close(fd);
	return (1);
}
