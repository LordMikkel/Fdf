/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:32:06 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/30 23:14:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	calculate_base_zero(const char *nptr, int base, int *i)
{
	if (base == 0)
	{
		if (nptr[*i] == '0' && (nptr[*i + 1] == 'x' || nptr[*i + 1] == 'X'))
		{
			base = 16;
			*i += 2;
		}
		else if (nptr[*i] == '0')
		{
			base = 8;
			*i += 1;
		}
		else
			base = 10;
	}
	else if (base == 16 && nptr[*i] == '0' && (nptr[*i + 1] == 'x'
			|| nptr[*i + 1] == 'X'))
		*i += 2;
	return (base);
}

static int	ft_isdigit_base(char c, int base)
{
	int	digit_value;

	if (c >= '0' && c <= '9')
		digit_value = c - '0';
	else if (c >= 'a' && c <= 'f')
		digit_value = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		digit_value = c - 'A' + 10;
	else
		return (0);
	return (digit_value < base);
}

static int	ft_digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

long	ft_strtol(const char *nptr, int base)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr || base < 0 || base == 1 || base > 36)
		return (0);
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	base = calculate_base_zero(nptr, base, &i);
	while (ft_isdigit_base(nptr[i], base))
		result = result * base + ft_digit_value(nptr[i++]);
	return (result * sign);
}
