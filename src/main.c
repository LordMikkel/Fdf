/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:40:08 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 23:24:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2)
		return (ft_putstr_fd(ERR_ARGS, STDERR), EXIT_FAILURE);
	printf("Corrrect Number of Arguments\n");
	if (!init_data(&data))
		error_exit(&data);
	if (check_4d_mode(av[1], &data.map))
	{
		if (!init_4d(av[1], &data.map))
			error_exit(&data);
	}
	else if (!parse_map(av[1], &data.map))
		error_exit(&data);
	init_cam(&data.cam, &data.map);
	render_fdf(&data, &data.map);
	mlx_setup(&data);
	return (0);
}
