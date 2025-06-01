/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:51:41 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/01 18:48:03 by migarrid         ###   ########.fr       */
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
	if (!parse_map(av[1], &data.map))
		error_exit(&data);
	render_fdf(&data, &data.map, &data.cam);
	mlx_setup(&data);
	return (0);
}
