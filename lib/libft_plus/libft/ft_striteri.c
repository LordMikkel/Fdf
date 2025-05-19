/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:18:14 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:34 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>

static void to_upper_if_even(unsigned int index, char *c)
{
	if(index % 2 == 0 && *c>= 'a' && *c <= 'z')
	*c = *c - 'a' + 'A';
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		printf("Original string: %s\n", str);
		ft_striteri(str, to_upper_if_even);
		printf("Modified string: %s\n", str);
		return (0);
	}
	return (1);
}*/
