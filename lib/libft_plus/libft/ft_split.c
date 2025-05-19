/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:26:17 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static size_t	count_substrings(const char *s, char c)
{
	size_t	counter;
	int		delimiter;

	counter = 0;
	delimiter = 1;
	while (*s)
	{
		if (*s == c)
			delimiter = 1;
		else if (delimiter)
		{
			counter++;
			delimiter = 0;
		}
		s++;
	}
	return (counter);
}

static int	substring(char **array, size_t *i, const char *start, size_t len)
{
	array[*i] = (char *)malloc(len + 1);
	if (!array[*i])
	{
		while (*i > 0)
			free(array[--(*i)]);
		return (0);
	}
	ft_memcpy(array[*i], start, len);
	array[(*i)++][len] = '\0';
	return (1);
}

static char	**fill_array(char **array, const char *s, char c)
{
	size_t		i;
	size_t		len;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			start = s;
			while (*s && *s != c)
				s++;
			len = s - start;
			if (!substring(array, &i, start, len))
				return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	counter;

	if (!s)
		return (NULL);
	counter = count_substrings(s, c);
	array = (char **)malloc((counter + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	char	**result;
	int		i;

	if (ac == 3)
	{
		printf("Matrix String: %s\n", av[1]);
		printf("Split Carcater: %s\n", av[2]);
		result = ft_split(av[1], av[2][0]);
		if (!result)
		{
			printf("Error: couldn't divede the string.\n");
			return (1);
		}
		i = 0;
		while (result[i])
		{
			printf("Substrings %d: %s\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
		return (0);
	}
	return (1);
}*/
