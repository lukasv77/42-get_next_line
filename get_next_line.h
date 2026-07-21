/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:59:58 by llinda            #+#    #+#             */
/*   Updated: 2026/07/21 10:43:20 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_chunklen(const char *);
t_list	*ft_lstnew_back(t_list **, char *content);
t_list	*ft_lstlast(t_list *);
t_list	*ft_lstnew(void *);
char	*ft_chunkdup(const char *);
char	*ft_strchr(const char *, int);
char	*ft_lststr(t_list *);