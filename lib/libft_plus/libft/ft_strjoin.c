/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:49:43 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = (char *)malloc(len1 + len2 + 1);
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, len1 + 1);
	ft_strlcat(strjoin, s2, len1 + len2 + 1);
	return (strjoin);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("S1: %s\n", av[1]);
		printf("S2: %s\n", av[2]);
		printf("Strjoin duplicated: %s\n", ft_strjoin(av[1], av[2]));
		return (0);
	}
	return (1);
}*/
