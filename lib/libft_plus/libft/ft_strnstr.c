/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:51:44 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack [i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("Haystack: %s\n", av[1]);
		printf("Needle: %s\n", av[2]);
		printf("Found: %s\n", ft_strnstr(av[1], av[2], (size_t)atoi(av[3])));
		return (0);
	}
	return (1);
}*/
