/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:47:44 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t cpy_size)
{
	size_t	i;

	if (cpy_size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < cpy_size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char	dst[(size_t)atoi(av[2])];

	if (ac != 4)
		return (1);
	printf("Source: %s\n", av[1]);
	printf("Size destination: %s\n", av[2]);
	printf("Size of the buffer: %s\n", av[3]);
	printf("Length of the source: %ld\n",
		ft_strlcpy(dst, av[1], (size_t)atoi(av[3])));
	printf("Destination: %s\n", dst);
	return (0);
}*/
