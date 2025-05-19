/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:53:27 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:19:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_isprint(int c)
{
	if (c > 0x1F && c < 0x7F)
		return (1);
	return (0);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%c is printable? 1 is true, 0 is false: %d\n",
			av[1][0], ft_isprint(av[1][0]));
		return (0);
	}
	return (1);
}*/
