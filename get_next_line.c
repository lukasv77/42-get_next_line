/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:00:46 by llinda            #+#    #+#             */
/*   Updated: 2026/07/15 20:32:14 by llinda           ###   ########.fr       */
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
	static char	buffer[BUFFER_SIZE];
	char		*ptr;
	size_t		bytes_read;
	t_list		*lst;

	bytes_read = 1;
	lst = NULL;
	ptr = strchr(buffer, '\n');
	if (ptr)
	{
		*ptr = ' ';
		ft_lstadd_back(&lst, ft_lstnew(ft_chunkdup(++ptr))); //strdup zmodyfikowane - czyta do \0 lub \n
	}
	while (!strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (ft_lststr(lst));
		buffer[bytes_read] = '\0';
		ft_lstadd_back(&lst, ft_lstnew(ft_chunkdup(buffer)));
	}
	return (ft_lststr(lst));
}
