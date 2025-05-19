/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:13:07 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:23:46 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
/*#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*new_node;
	t_list	*last_node;
	int	i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		new_node = ft_lstnew(av[i]);
		if (!new_node)
			return (1);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	last_node = ft_lstlast(lst);
	printf("Last node: %s\n", (char *) last_node->content);
	return  (0);
}*/
