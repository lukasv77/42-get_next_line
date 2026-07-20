/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:00:46 by llinda            #+#    #+#             */
/*   Updated: 2026/07/20 14:28:24 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 3
#endif

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*ptr;
	int			bytes_read;
	t_list		*lst;

	bytes_read = 0;
	lst = NULL;
	if (!ptr || *ptr == 0)
		ptr = buffer;
	if (ptr != buffer)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_chunkdup(ptr)));
		if (strchr(ptr, '\n'))
			ptr = strchr(ptr, '\n') + 1;
		else
			ptr = buffer;
	}
	while (ptr == buffer)
	{
		if (*ptr == 0 || ptr == buffer)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer[bytes_read] = 0;
		}
		if (bytes_read < 0)
			return (NULL);
		if (!bytes_read)
			return (ft_lststr(lst));
//		if (!(*buffer))
//			return (NULL);
		ft_lstadd_back(&lst, ft_lstnew(ft_chunkdup(ptr)));
		if (strchr(ptr, '\n'))
			ptr = strchr(ptr, '\n') + 1;
	}
	return (ft_lststr(lst));
}
