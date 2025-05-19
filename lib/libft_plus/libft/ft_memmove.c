/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 00:54:29 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if ((!dest && !src) && n > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s > d)
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	dest[1024];
	char	src[1024];

	if (ac == 4)
	{
		strlcpy(dest, av[1], sizeof(dest));
		strlcpy(src, av[2], sizeof(src));
		printf("Before: dest->%s, src->%s\n", dest, src);
		ft_memmove(dest, src,(size_t)atoi(av[3]));
		printf("After: dest->%s, src->%s\n", dest, src);
		return (0);
	}
	return (1);

}*/
