/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:15:13 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/16 15:38:31 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static int	is_hex_digit(char c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

static int	token_is_number(const char *s)
{
	int	i;

	i = 0;
	if (ft_issign(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '\0')
		return (1);
	if (s[i] != ',' || s[i + 1] != '0' || (s[i + 2] != 'x' && s[i + 2] != 'X'))
		return (0);
	i += 3;
	if (!is_hex_digit(s[i]))
		return (0);
	while (is_hex_digit(s[i]))
		i++;
	return (s[i] == '\0');
}

static int	count_columns(char **tokens)
{
	int	columns;

	columns = 0;
	while (tokens[columns])
	{
		if (!token_is_number(tokens[columns]))
			return (-1);
		columns++;
	}
	return (columns);
}

static int	validate_dimensions(const char *line, t_map *map)
{
	char	**tokens;
	char	*trimmed;
	int		columns;

	trimmed = ft_strtrim(line, " \n");
	if (!trimmed)
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	tokens = ft_split(trimmed, ' ');
	free(trimmed);
	if (!tokens)
		return (ft_putstr_fd(ERR_MEM, STDERR), 0);
	columns = count_columns(tokens);
	ft_free_str_array(tokens);
	if (columns == -1)
		return (ft_putstr_fd(ERR_PARSE, STDERR), 0);
	if (map->height == 0)
		map->width = columns;
	else if (columns != map->width)
		return (ft_putstr_fd(ERR_SHAPE, STDERR), 0);
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
