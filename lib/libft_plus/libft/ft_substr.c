/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:15:40 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:23:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("String: %s\n", av[1]);
		printf("index: %s\n", av[2]);
		printf("len: %s\n", av[3]);
		printf("substrig: %s\n", ft_substr(av[1],
			(unsigned int)atoi(av[2]), (size_t) atoi(av[3])));
		return (0);
	}
	return (1);
}*/
