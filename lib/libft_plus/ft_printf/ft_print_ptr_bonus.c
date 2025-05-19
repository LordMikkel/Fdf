/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:30:53 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:27:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ptr_nill(t_format *fmt)
{
	int		len;
	char	*str;

	str = ft_strdup("(nil)");
	if (!str)
		return (-1);
	ft_apply_flags(&str, fmt);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_print_ptr(void *ptr, t_format *fmt)
{
	int		len;
	char	*str;
	char	*tmp;

	if (!ptr)
		return (ptr_nill(fmt));
	tmp = ft_utoa_base((uintptr_t)ptr);
	if (!tmp)
		return (-1);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	if (!str)
		return (-1);
	ft_apply_flags(&str, fmt);
	if (!str)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
