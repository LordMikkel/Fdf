/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_principal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/17 21:38:44 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static int	is_valid_ext(const char *filename)
{
	const char	*dot;

	if (!filename)
		return (0);
	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename || *(dot - 1) == '/')
		return (0);
	if (ft_strcmp(dot, ".fdf") == 0)
		return (1);
	return (0);
}

static int	close_fail(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	parse_map(const char *filename, t_map *map)
{
	int	fd;

	map->type = OBJECT_3D;
	if (!is_valid_ext(filename))
		return (ft_putstr_fd(ERR_EXT, STDERR), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(ERR_OPEN, STDERR), 0);
	if (!calculate_dimensions(fd, map))
		return (close_fail(fd));
	close(fd);
	if (map->height == 0 || map->width == 0)
		return (ft_putstr_fd(ERR_EMPTY, STDERR), 0);
	if (!allocate_points_map_memory(map))
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(ERR_OPEN, STDERR), 0);
	if (!parse_values(fd, map))
		return (close_fail(fd));
	close(fd);
	return (1);
}
