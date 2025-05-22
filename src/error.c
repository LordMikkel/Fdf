/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:32:33 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/22 17:25:25 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error_exit(t_fdf *data)
{
	if (data)
		free_data(data);
	perror("Error\n");
	exit(EXIT_FAILURE);
}
