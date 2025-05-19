/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:32:31 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/01 20:44:39 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*#include <stdio.h>

int main(void)
{
	printf("Compare 'abc' y 'abc': %d\n", ft_strcmp("abc", "abc")); // 0
	printf("Comparando 'abc' y 'abd': %d\n", ft_strcmp("abc", "abd")); //-
	printf("Comparando 'abd' y 'abc': %d\n", ft_strcmp("abd", "abc")); //+
}*/
