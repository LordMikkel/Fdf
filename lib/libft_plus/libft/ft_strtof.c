/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:40:12 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/30 23:14:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static float	process_decimal_part(const char *nptr, int *i, float result)
{
	float	decimal;

	decimal = 0.1f;
	(*i)++;
	while (ft_isdigit(nptr[*i]))
	{
		result = result + (nptr[*i] - '0') * decimal;
		decimal = decimal * 0.1f;
		(*i)++;
	}
	return (result);
}

float	ft_strtof(const char *nptr)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0.0f;
	if (!nptr)
		return (0.0f);
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(nptr[i]))
		result = result * 10.0f + (nptr[i++] - '0');
	if (nptr[i] == '.')
		result = process_decimal_part(nptr, &i, result);
	return (result * sign);
}
