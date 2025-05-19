/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:04:45 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:26:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static char	*precision_str(char *str, t_format *fmt)
{
	char	*new_str;

	if (ft_strncmp(str, "(null)", 6) == 0
		&& fmt->precision < 6 && fmt->precision >= 0)
	{
		free(str);
		return (ft_strdup(""));
	}
	else if (fmt->specifier == 's' && fmt->precision >= 0)
	{
		new_str = ft_substr(str, 0, fmt->precision);
		if (!new_str)
			return (NULL);
		free(str);
		return (new_str);
	}
	return (str);
}

static int	apply_flags(char **str, t_format *fmt)
{
	ft_apply_precision(str, fmt);
	if (!*str)
		return (0);
	ft_apply_hash(str, fmt);
	if (!*str)
		return (0);
	ft_apply_plus(str, fmt);
	if (!*str)
		return (0);
	ft_apply_space(str, fmt);
	if (!*str)
		return (0);
	ft_apply_zero_pad(str, fmt);
	if (!*str)
		return (0);
	ft_apply_min_width(str, fmt);
	if (!*str)
		return (0);
	ft_apply_left_align(str, fmt);
	if (!*str)
		return (0);
	return (1);
}

void	ft_apply_flags(char **str, t_format *fmt)
{
	char	*original;

	original = *str;
	if (fmt->specifier == 's')
	{
		*str = precision_str(*str, fmt);
		if (!*str)
		{
			free(original);
			return ;
		}
		ft_apply_min_width(str, fmt);
		if (!*str)
		{
			free(original);
			return ;
		}
	}
	else if (!apply_flags(str, fmt))
	{
		free(original);
		return ;
	}
}
