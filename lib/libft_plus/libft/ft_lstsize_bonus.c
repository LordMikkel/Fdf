/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:45:15 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:33 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*#include <stdio.h>

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*new_node;
	t_list	*tmp;
	int		i;
	int		size;

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
	size = ft_lstsize(lst);
	printf("Size list: %d\n", size);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}*/
