/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:37:59 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*#include <stdio.h>
#include <stdlib.h>

void	del_content(void *content)
{
	free(content);
}

t_list	*ft_lstnew(void *content);

int	main(void)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	node->content = malloc(10);
	node->next = NULL;
	ft_lstdelone(node, del_content);
	return (0);
}*/
