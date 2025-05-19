/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:33:01 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("String: %s\nCaracter: %c\nPointer: %p\nCaracter: %c\n",
		av[1], av[2][0],
			ft_strchr(av[1],av[2][0]), *(ft_strchr)(av[1], av[2][0]));
		return (0);
	}
	return (1);
}*/
