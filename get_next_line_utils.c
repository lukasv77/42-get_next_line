/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:59:47 by llinda            #+#    #+#             */
/*   Updated: 2026/07/12 18:18:46 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_chunklen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
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

	i = 0;
	len = ft_chunklen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] && s[i] != '\n')
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

char	*lststr(t_list **lst)
{
	return (0);
}