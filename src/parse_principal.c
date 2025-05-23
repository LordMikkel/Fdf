/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_principal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 00:15:44 by migarrid         ###   ########.fr       */
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

	printf("entra\n");
	if (!is_valid_ext(filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!calculate_dimensions(fd, map))
		return (0);
	if (!allocate_map_memory(map))
		return (0);
/*	if (!parse_values(fd, map))
		return (0);*/
	close(fd);
	return (1);
}
