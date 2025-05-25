/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:13 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/24 00:47:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	is_valid_number(char c)
{
	if (!ft_isdigit(c) && ft_issign(c) && ft_ishex(c))
		return (0);
	return (1);
}

static int	validate_dimensions(const char *line, t_map *map)
{
	char	**tokens;
	int		columns;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	columns = 0;
	while (tokens[columns])
	{
		if (!is_valid_number(tokens[columns][0]))
		{
			ft_free_str_array(tokens);
			return (ft_putstr_fd(ERR_PARSE, STDERR), 0);
		}
		columns++;
	}
	if (columns != map->width && map->width != 0)
		return (ft_putstr_fd(ERR_LINE, STDERR), 0);
	map->width = columns;
	ft_free_str_array(tokens);
	return (1);
}

int	calculate_dimensions(int fd, t_map *map)
{
	char	*line;

	map->height = 0;
	map->width = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_dimensions(line, map))
		{
			free(line);
			return (0);
		}
		map->height++;
		free(line);
	}
	return (1);
}
