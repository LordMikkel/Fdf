/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:28:08 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:26:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static void	handle_zero_precision(char **str)
{
	if ((*str)[0] == '0')
	{
		free(*str);
		*str = ft_strdup("");
	}
}

static void	apply_logic(char **str, t_format *fmt, int len, int is_neg)
{
	char	*new_str;

	new_str = ft_calloc(fmt->precision + is_neg + 1, sizeof(char));
	if (!new_str)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	if (is_neg)
		new_str[0] = '-';
	ft_memset(new_str + is_neg, '0', fmt->precision - (len - is_neg));
	ft_strlcpy(new_str + is_neg + (fmt->precision - (len - is_neg)),
		*str + is_neg, len - is_neg + 1);
	free(*str);
	*str = new_str;
}

void	ft_apply_precision(char **str, t_format *fmt)
{
	int		len;
	int		is_neg;

	if (fmt->precision < 0 || ft_strncmp(*str, "(nil)", 5) == 0)
		return ;
	len = ft_strlen(*str);
	is_neg = 0;
	if ((*str)[0] == '-')
		is_neg = 1;
	if (fmt->precision == 0)
	{
		handle_zero_precision(str);
		return ;
	}
	if (fmt->precision > len - is_neg)
		apply_logic(str, fmt, len, is_neg);
}
