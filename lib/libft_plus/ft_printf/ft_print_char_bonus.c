/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:31:04 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:27:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static void	print_w_pad(char c, int pad_len, char pad_char, int is_left_align)
{
	if (!is_left_align)
	{
		while (pad_len > 0)
		{
			write(1, &pad_char, 1);
			pad_len--;
		}
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		while (pad_len > 0)
		{
			write(1, " ", 1);
			pad_len--;
		}
	}
}

int	ft_print_char(char c, t_format *fmt)
{
	int		len;
	int		pad_len;
	char	pad_char;

	if (fmt->width > 1)
		len = fmt->width;
	else
		len = 1;
	pad_len = len - 1;
	if (fmt->zero_pad && !fmt->left_align)
		pad_char = '0';
	else
		pad_char = ' ';
	print_w_pad(c, pad_len, pad_char, fmt->left_align);
	return (len);
}
