/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:54:37 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%c is alpha? 1 is true, 0 is false: %d\n",
		av[1][0], ft_isdigit(av[1][0]));
		return (0);
	}
	return (1);
}*/
