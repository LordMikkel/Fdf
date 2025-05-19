/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:29:12 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*new_node;
	t_list	*tmp;
	t_list	*current;
	int		i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		new_node = ft_lstnew(av[i]);
		if (!new_node)
			return (1);
		ft_lstadd_front(&lst, new_node);
		i++;
	}
	current = lst;
	i = 1;
	while (current)
	{
		printf("Node Content %d: %s\n", i, (char *)current->content);
		current = current->next;
		i++;
	}
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}*/
