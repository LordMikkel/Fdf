/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:43:41 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:28:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	calculate_udigit_count(unsigned long n, int base_length, int count)
{
	if (n == 0)
	{
		if (count == 0)
			return (1);
		return (count);
	}
	return (calculate_udigit_count(n / base_length, base_length, count + 1));
}

static void	fill_ustr(char *str, unsigned long n, char *base, int index)
{
	unsigned int	base_length;

	if (index < 0)
		return ;
	base_length = ft_strlen(base);
	str[index] = base[n % base_length];
	fill_ustr(str, n / base_length, base, index - 1);
}

char	*ft_utoa_base(unsigned long n)
{
	int		base_length;
	int		digit_count;
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	base_length = ft_strlen(base);
	digit_count = calculate_udigit_count(n, base_length, 0);
	str = malloc(digit_count + 1);
	if (!str)
		return (NULL);
	str[digit_count] = '\0';
	fill_ustr(str, n, base, digit_count - 1);
	return (str);
}
