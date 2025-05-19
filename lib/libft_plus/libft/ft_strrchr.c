/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 01:55:37 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("String: %s\nCaracter: %c\nPointer: %p\nCaracter: %c\n",
			av[1], av[2][0],
				ft_strrchr(av[1],av[2][0]), *(ft_strrchr)(av[1], av[2][0]));
		return (0);
	}
}*/
