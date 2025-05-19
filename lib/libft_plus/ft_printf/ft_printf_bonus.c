/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:32:45 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:27:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static int	ft_atoi_advance(const char **str)
{
	int			num;
	const char	*start;

	start = *str;
	num = ft_atoi(start);
	while (ft_isdigit(**str))
		(*str)++;
	return (num);
}

static int	ft_specifiers(char specifier, va_list args, t_format *fmt)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int), fmt));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *), fmt));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, void *), fmt));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_num(va_arg(args, int), fmt));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int), fmt));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex
			(va_arg(args, unsigned int), fmt, specifier == 'X'));
	else if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

static void	process_flags(const char **str, t_format *fmt)
{
	if (**str == '-')
		fmt->left_align = 1;
	else if (**str == '0')
		fmt->zero_pad = 1;
	else if (**str == '#')
		fmt->hash = 1;
	else if (**str == ' ')
		fmt->space = 1;
	else if (**str == '+')
		fmt->plus = 1;
	else if (**str == '.')
	{
		(*str)++;
		fmt->precision = 0;
		if (ft_isdigit(**str))
			fmt->precision = ft_atoi_advance(str);
		return ;
	}
	else if (ft_isdigit(**str))
	{
		fmt->width = ft_atoi_advance(str);
		return ;
	}
	(*str)++;
}

static int	ft_flags(char const **str, va_list args)
{
	t_format	fmt;

	fmt = (t_format){0, -1, 0, 0, 0, 0, 0, 0};
	while (**str && !ft_strchr("cspdiuxX%", **str))
		process_flags(str, &fmt);
	fmt.specifier = **str;
	return (ft_specifiers(fmt.specifier, args, &fmt));
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		result;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			result = ft_flags(&str, args);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count = count + result;
		}
		else
			count = count + write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
