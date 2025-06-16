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

static int	token_is_number(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[i])
		return (0);
	if (ft_issign(s[i]))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_ishex(s[i]) && s[i] != '\n' && s[i] != ',')
			return (0);
		i++;
	}
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
		if (!token_is_number(tokens[columns]))
		{
			ft_free_str_array(tokens);
			return (ft_putstr_fd(ERR_PARSE, STDERR), 0);
		}
		columns++;
	}
	if (columns != map->width && map->width != 0)
		map->error += TRUE;
	if (columns > map->width)
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
