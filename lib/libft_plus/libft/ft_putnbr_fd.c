/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:26:36 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:02 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + '0', fd);
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
			ft_putnbr_fd(atoi(av[1]), fd);
			ft_putchar_fd('\n', fd);
			return (0);
		}
	}
	return (1);
}*/
