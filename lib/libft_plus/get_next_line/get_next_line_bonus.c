/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:11:10 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/19 17:53:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static char	*read_into_stash(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (stash == NULL)
		stash = ft_strdup("");
	if (!buffer || !stash)
		return (free(buffer), free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (!stash || !tmp)
			return (free(buffer), NULL);
	}
	if (bytes_read == 0 && *stash == '\0')
		return (free(buffer), free(stash), NULL);
	return (free(buffer), stash);
}

static char	*extract_line(char *stash)
{
	size_t		len;
	char		*newline_ptr;
	char		*line;

	if (!stash || *stash == '\0')
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr)
		len = newline_ptr - stash + 1;
	else
		len = ft_strlen(stash);
	line = ft_substr(stash, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*remain_stash(char *stash)
{
	char	*newline_ptr;
	char	*remaining;

	if (!stash)
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (!newline_ptr)
	{
		free(stash);
		return (NULL);
	}
	remaining = ft_strdup(newline_ptr + 1);
	free(stash);
	if (!remaining)
		return (NULL);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_into_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = remain_stash(stash[fd]);
	return (line);
}
