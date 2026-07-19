/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:59:47 by llinda            #+#    #+#             */
/*   Updated: 2026/07/19 16:37:00 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_chunklen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++; 
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

char	*ft_chunkdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	if (*s == 0)
		return (NULL);
	i = 0;
	len = ft_chunklen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (len--)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	size_t	i;
	char	ch;

	p = (char *)s;
	ch = (char) c;
	i = 0;
	if (ch == 0)
		return (&p[ft_chunklen(p)]);
	while (p[i])
	{
		if (p[i] == ch)
			return (&p[i]);
		i++;
	}
	return (0);
}

char	*ft_lststr(t_list *lst)
{
	size_t	line_len;
	char	*ptr;
	t_list	*node;
	size_t	i;
	size_t	j;

	if (!lst)
		return (NULL);
	line_len = 0;
	node = lst;
	while (node)
	{
		line_len += ft_chunklen(node->content);
		node = node->next;
	}
	ptr = malloc(line_len + 1);
	if(!ptr)
		return (NULL);
	i = 0;
	node = lst;
	while (node)
	{
		j = 0;
		while (((char *)(node->content))[j])
			ptr[i++] = ((char *)(node->content))[j++];
		node = node->next;
		free(lst->content);
		free(lst);
		lst = node;
	}
	ptr[i] = 0;
	return (ptr);
}