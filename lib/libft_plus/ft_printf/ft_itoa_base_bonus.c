/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:31:08 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/03 20:02:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base == NULL)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
		{
			return (0);
		}
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

static int	calculate_digit_count(long n, int base_length, int count)
{
	if (n == 0)
	{
		if (count == 0)
			return (1);
		return (count);
	}
	return (calculate_digit_count(n / base_length, base_length, count + 1));
}

static void	fill_str(char *str, long n, char *base, int index)
{
	int		base_length;

	if (index < 0)
		return ;
	base_length = ft_strlen(base);
	str[index] = base[n % base_length];
	fill_str(str, n / base_length, base, index - 1);
}

char	*ft_itoa_base(long n, char *base)
{
	int		base_length;
	int		digit_count;
	int		total_length;
	int		sign;
	char	*str;

	if (!is_valid_base(base))
		return (NULL);
	base_length = ft_strlen(base);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	digit_count = calculate_digit_count(n, base_length, 0);
	total_length = digit_count + sign;
	str = malloc(total_length + 1);
	if (!str)
		return (NULL);
	str[total_length] = '\0';
	fill_str(str, n, base, total_length - 1);
	if (sign)
		str[0] = '-';
	return (str);
}
