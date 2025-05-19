/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:09 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:09 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	buffer[1024];
	size_t	i;

	if (ac == 4)
	{
		strlcpy(buffer, av[1], sizeof(buffer));
		printf("Souce: %s\n", buffer);
		printf("Caracther to be filled: %c\n", av[2][0]);
		printf("How many times: %s", av[3]);
		ft_memset(buffer, av[2][0], (size_t)atoi(av[3]));
		i = 0;
		printf("After ft_bmemset: ");
		while (i < strlen(av[1]))
		{
			printf("%c", buffer[i]);
			i++;
		}
		printf("\n");
		return (0);
	}
	return (1);
}*/
