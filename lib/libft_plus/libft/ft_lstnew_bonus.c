/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:34:37 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:20:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	t_list	*new_node;

	i = 1;
	while (i < ac)
	{
		new_node = ft_lstnew(av[i]);
		if (!new_node)
			return (1);
		printf ("Node Content %d: %s\n", i, (char *)new_node->content);
		free(new_node);
		i++;
	}
	return (0);
}*/
