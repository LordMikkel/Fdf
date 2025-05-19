/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:06:32 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%c is ascii? 1 is true, 0 is false: %d\n",
			av[1][0], ft_isascii(av[1][0]));
		return (0);
	}
	return (1);
}*/
