/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:16:43 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/25 18:16:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	handle_key(int key, t_fdf *data)
{
	printf("key: %d\n", key);
	if (key == ESC_KEY)
		close_exit(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	printf("button: %d\n", button);
	printf("pos x: %d\n", x);
	printf("pos y: %d\n", y);
	(void)data;
	return (0);
}
