/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_zero_pad_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:38:31 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:26:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	get_sign_offset(char *str)
{
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		return (1);
	return (0);
}

static char	*create_padding(int width, int len)
{
	char	*padding;

	padding = ft_calloc(width - len + 1, sizeof(char));
	if (!padding)
		return (NULL);
	ft_memset(padding, '0', width - len);
	return (padding);
}

static char	*apply_padding(char *str, char *padding, int sign_offset)
{
	char	*tmp;
	char	*result;
	char	*sign;

	tmp = ft_strjoin(padding, str + sign_offset);
	free(padding);
	if (!tmp)
		return (NULL);
	if (sign_offset)
	{
		sign = ft_substr(str, 0, 1);
		if (!sign)
		{
			free(tmp);
			return (NULL);
		}
		result = ft_strjoin(sign, tmp);
		free(sign);
		free(tmp);
		return (result);
	}
	return (tmp);
}

static void	handle_zero_padding(char **str, int len, int sign_offset, int width)
{
	char	*padding;
	char	*new_str;

	padding = create_padding(width, len);
	if (!padding)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new_str = apply_padding(*str, padding, sign_offset);
	if (!new_str)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	free(*str);
	*str = new_str;
}

void	ft_apply_zero_pad(char **str, t_format *fmt)
{
	int		len;
	int		sign_offset;

	if (fmt->width <= 0 || !fmt->zero_pad
		|| (fmt->precision >= 0 && ft_strchr("diuxX", fmt->specifier)))
		return ;
	len = ft_strlen (*str);
	sign_offset = get_sign_offset(*str);
	if (fmt->width > len)
		handle_zero_padding(str, len, sign_offset, fmt->width);
}
