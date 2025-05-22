/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 03:04:56 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/22 17:16:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	is_valid_ext(char *filename)
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
