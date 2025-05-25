/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_principal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/24 02:19:23 by migarrid         ###   ########.fr       */
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

	printf("3\n");
	if (!is_valid_ext(filename))
		return (ft_putstr_fd(ERR_EXT, STDERR), 0);
	printf("4\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(ERR_OPEN, STDERR), 0);
	printf("5\n");
	if (!calculate_dimensions(fd, map))
		return (0);
	printf("6\n");
	if (!allocate_map_memory(map))
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	printf("7\n");
	/*if (!parse_values(fd, map))
		return (0);*/
	close(fd);
	return (1);
}
