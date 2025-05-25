/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:51:41 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 23:35:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2)
		return (ft_putstr_fd(ERR_ARGS, STDERR), EXIT_FAILURE);
	init_data(&data);
	if (!parse_map(av[1], &data.map))
		error_exit(&data);
	mlx_hook(data.win, CLOSE_EVENT, 0, close_exit, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
