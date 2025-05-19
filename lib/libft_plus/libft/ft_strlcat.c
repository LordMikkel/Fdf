/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:56:11 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t cat_size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (cat_size <= dst_len)
		return (cat_size + src_len);
	i = 0;
	while (dst_len + i < cat_size - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t cpy_size);

int	main(int ac, char **av)
{
	size_t	dst_size;

	if (ac != 5)
		return (1);
	dst_size = (size_t)atoi(av[2]);
	char	dst[dst_size];
	ft_strlcpy(dst, av[1], dst_size);
	printf("Initial destination %s\n", av[1]);
	printf("Size destination: %s\n", av[2]);
	printf("Source: %s\n", av[3]);
	printf("Size of the buffer: %s\n", av[4]);
	printf("leng of the concatenation: %ld\n",
		ft_strlcat(dst, av[3], (size_t)atoi(av[4])));
	printf("Concatenation: %s\n", dst);
	return (0);
}*/
