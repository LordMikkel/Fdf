/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:00:37 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*#include <stdio.h>

void	print_content(void *content)
{
	printf("%s\n", (char *) content);
}
int	main(void)
{
	t_list	node3 = {"Node 3", NULL};
	t_list	node2 = {"Node 2", &node3};
	t_list	node1 = {"Node 1", &node2};

	t_list	*head = &node1;

	ft_lstiter(head, print_content);
	return (0);
}*/
