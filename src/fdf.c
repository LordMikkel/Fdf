/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:51:41 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/22 20:27:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2 || !is_valid_ext(av[1]))
		error_exit(NULL);
	init_data(&data);
	data.map = get_map(av[1]);
	if (!data.map)
		error_exit(&data);
	free_data(&data);
	return (0);
}
