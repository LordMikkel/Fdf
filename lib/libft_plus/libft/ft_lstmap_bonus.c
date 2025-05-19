/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:18:45 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	new_node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	print_content(void *content)
{
	printf("%s\n", (char *) content);
}

void	del(void *content)
{
	free(content);
}

void *duplicate_content(void *content)
{
	char *original = (char *)content;
	char *copy = malloc(strlen(original) + 1);
	if (!copy)
		return (NULL);
	strcpy (copy, original);
	return (copy);
}

int	main(void)
{
	t_list	*new_list;

	t_list	node3 = {"Node 3", NULL};
	t_list	node2 = {"Node 2", &node3};
	t_list	node1 = {"Node 1", &node2};

	new_list = ft_lstmap(&node1, duplicate_content, del);

	printf("Original list content:\n");
	ft_lstiter(&node1, print_content);

	printf("\nNew list content:\n");
	ft_lstiter(new_list, print_content);

	ft_lstclear(&new_list, del);

	return (0);
}*/
