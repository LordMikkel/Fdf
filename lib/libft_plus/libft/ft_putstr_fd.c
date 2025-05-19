/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:13:20 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
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
			ft_putstr_fd(av[1], fd);
			return (0);
		}
	}
	return (1);
}*/
