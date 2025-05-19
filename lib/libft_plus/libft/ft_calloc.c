/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:20:38 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		total_size;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (size != 0 && nmemb * size > __SIZE_MAX__)
		return (NULL);
	total_size = (nmemb * size);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	int		*array;
	size_t	nmemb;
	size_t	size;
	size_t	i;

	if (ac == 3)
	{
		nmemb = (size_t)atoi(av[1]);
		size = (size_t)atoi(av[2]);
		array = (int *)ft_calloc(nmemb, size);
		printf("Array asignado con ft_calloc:\n");
		i = 0;
		while (i < nmemb)
		{
			printf("array[%zu] = %d\n", i, array[i]);
			i++;
		}
		free(array);
		return (0);
	}
	return (0);
}*/
