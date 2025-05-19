/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:36:04 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:12 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*#include <stdlib.h>

int main(int ac, char **av)
{
	int	fd;

	if (ac == 3)
	{
		if (atoi(av[2]) == 1 || atoi(av[2]) == 2)
		{
			fd = atoi(av[2]);
			ft_putchar_fd(av[1][0], fd);
			return (0);
		}
	}
	return (1);
}*/
