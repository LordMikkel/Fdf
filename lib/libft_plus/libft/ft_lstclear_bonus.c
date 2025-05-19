/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:55:46 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:57:04 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*#include <stdio.h>
#include <string.h>

void	del_content(void *content)
{
	free(content);
}

t_list	*ft_lstnew(void *content);

void  print_list(t_list *lst)
{
	while(lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*node1 = ft_lstnew(strdup("Node 1"));
	t_list	*node2 = ft_lstnew(strdup("Node 2"));
	t_list	*node3 = ft_lstnew(strdup("Node 3"));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("List before clear:\n");
	print_list(node1);

	ft_lstclear(&node1, del_content);

	if (!node1)
		printf("List cleared successfully!\n");
	return (0);
}*/
