/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:18:04 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:20:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	uc = (unsigned char)c;
	ptr = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	void	*result;

	if (ac == 4)
	{
		result = ft_memchr(av[1], av[2][0], (size_t)atoi(av[3]));
		printf("String: %s\nCaracter: %c\nBuffer: %d\n",
			av[1], av[2][0], atoi(av[3]));
		printf("Pointer: %p\nCaracter: %c\n", result, *(char *)result);
		return (0);
	}
	return (1);
}*/
