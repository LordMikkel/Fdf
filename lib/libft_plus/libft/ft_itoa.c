/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:35:10 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:20:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;
	int		sign;

	len = num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	i = len - 1;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i--] = sign * (n % 10) + '0';
		n = n / 10;
	}
	str[len] = '\0';
	return (str);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Integer number: %s\n", av[1]);
		printf("Character number: %s\n", ft_itoa(atoi(av[1])));
		return (0);
	}
	return (1);
}*/
