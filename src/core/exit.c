/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:32:33 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/12 22:06:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	error_exit(t_fdf *data)
{
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

int	close_exit(t_fdf *data)
{
	if (data)
		free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}
