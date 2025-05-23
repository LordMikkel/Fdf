/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:51:41 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 03:00:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2 || !init_data(&data) || !parse_map(av[1], data->map))
		error_exit(data);
	free_data(data);

	return (0);
}
