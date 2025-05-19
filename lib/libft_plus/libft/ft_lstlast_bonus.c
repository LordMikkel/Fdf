/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:42:47 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:20:33 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	main(void)
{
	t_list	*node1 = ft_lstnew("Hey, ");
	t_list	*node2 = ft_lstnew("World");
	t_list	*node3 = ft_lstnew("!");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	t_list *last_node = ft_lstlast(node1);
	printf("Last node: %s\n", (char *)last_node->content);
	return (0);
}*/
