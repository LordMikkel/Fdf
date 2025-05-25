/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:32:33 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 23:32:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error_exit(t_fdf *data)
{
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

__attribute__((noreturn))int		close_exit(t_fdf *data)
{
	if (data)
		free_data(data);
	exit(EXIT_SUCCESS);
}
