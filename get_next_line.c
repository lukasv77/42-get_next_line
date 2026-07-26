/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:00:46 by llinda            #+#    #+#             */
/*   Updated: 2026/07/26 15:04:46 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = next;
	}
}

static void	ft_addchunk(char **ptr, char *buffer, t_list **lst)
{
	char	*chunk;

	chunk = ft_chunkdup(*ptr);
	if (!chunk)
	{
		ft_lstclear(lst);
		return ;
	}
	if (!ft_lstnew_back(lst, chunk))
		return ;
	if (ft_strchr(*ptr, '\n'))
		*ptr = ft_strchr(*ptr, '\n') + 1;
	else
		*ptr = buffer;
}

char	*get_next_line(int fd)
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
		ft_addchunk(&ptr, buffer, &lst);
	while (ptr == buffer)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_lstclear(&lst), NULL);
		buffer[bytes_read] = 0;
		if (!bytes_read)
			return (ft_lststr(lst));
		ft_addchunk(&ptr, buffer, &lst);
	}
	return (ft_lststr(lst));
}
