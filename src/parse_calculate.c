/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:13 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 02:44:31 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_dimensions(const char *line, t_map *map)
{
	char	**tokens;
	int		columns;

	if (!line)
		return (0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	columns = 0;
	while (tokens[columns])
	{
		if (!is_valid_number(tokens[columns]))
		{
			ft_free_array(tokens);
			return (0);
		}
		columns++;
	}
	if (columns > 0)
		map->width = columns;
	map->tokens = tokens;
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
