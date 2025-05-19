/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:46:23 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	if (!nptr)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		result = (result * 10) + (nptr[i++] - '0');
	return (result * sign);
}
/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Number: %d\n", ft_atoi(av[1]));
		return (0);
	}
	return (0);
}*/
