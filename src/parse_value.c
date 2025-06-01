/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:05:03 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/30 23:16:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	fill_values(char **splitted, t_map *map, int row, int col)
{
	if (!ft_atoi_range(splitted[0]))
		return (0);
	map->points[row][col].x = col;
	map->points[row][col].y = row;
	map->points[row][col].z = ft_strtof(splitted[0]);
	if (splitted[1])
		map->points[row][col].color = ft_strtol(splitted[1], 16);
	else
		map->points[row][col].color = DEFAULT_COLOR;
	return (1);
}

static int	process_tokens(char *token, t_map *map, int row, int column)
{
	char	**splitted;
	char	*trimmed;

	trimmed = ft_strtrim(token, "\n");
	if (!trimmed)
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	splitted = ft_split(trimmed, ',');
	if (!splitted)
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	if (!fill_values(splitted, map, row, column))
		return (ft_putstr_fd(ERR_PARSE, STDERR), 0);
	ft_free_str_array(splitted);
	free(trimmed);
	return (1);
}

static int	process_line(char *line, t_map *map, int row)
{
	char	**tokens;
	int		columns;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	columns = 0;
	while (tokens[columns])
	{
		if (!process_tokens(tokens[columns], map, row, columns))
		{
			ft_free_str_array(tokens);
			return (0);
		}
		columns++;
	}
	ft_free_str_array(tokens);
	return (1);
}

int	parse_values(int fd, t_map *map)
{
	char	*line;
	int		row;

	row = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!process_line(line, map, row))
		{
			free(line);
			return (0);
		}
		row++;
		free(line);
	}
	return (1);
}
