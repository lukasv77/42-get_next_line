/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:59:47 by llinda            #+#    #+#             */
/*   Updated: 2026/07/24 21:02:22 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

t_list	*ft_lstnew_back(t_list **lst, char *content)
{
	t_list	*tmp;
	t_list	*new;

	if (!lst || !content)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (ft_lstclear(lst), free(content), NULL);
	new->content = content;
	new->next = NULL;
	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (*lst);
}

char	*ft_chunkdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	len = i;
	i = 0;
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
	while (p[i])
	{
		if (p[i] == ch)
			return (&p[i]);
		i++;
	}
	return (0);
}

void	ft_mvcontent(t_list *lst, char *ptr)
{
	size_t	i;
	size_t	j;
	t_list	*node;

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
}

char	*ft_lststr(t_list *lst)
{
	size_t	line_len;
	char	*ptr;
	t_list	*node;
	size_t	i;

	if (!lst)
		return (ft_lstclear(&lst), NULL);
	line_len = 0;
	node = lst;
	while (node)
	{
		i = 0;
		while (((char *)node->content)[++i])
			;
		line_len += i;
		node = node->next;
	}
	ptr = malloc(line_len + 1);
	if (!ptr)
		return (ft_lstclear(&lst), NULL);
	ft_mvcontent(lst, ptr);
	return (ptr);
}
