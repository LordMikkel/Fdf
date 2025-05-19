/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:34:47 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*#include <stdio.h>

static char to_upper_if_even(unsigned int index, char c)
{
	if(index % 2 == 0 && c>= 'a' && c <= 'z')
		return c -'a' + 'A';
	return c;
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = ft_strmapi(av[1], to_upper_if_even);
		printf("Original string: %s\n", av[1]);
		printf("Modified string: %s\n", str);
		free(str);
		return (0);
	}
	return (1);
}*/
