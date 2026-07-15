/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:59:58 by llinda            #+#    #+#             */
/*   Updated: 2026/07/15 11:46:11 by llinda           ###   ########.fr       */
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
void	ft_lstadd_back(t_list **, t_list * new);
t_list	*ft_lstlast(t_list *);
t_list	*ft_lstnew(void *);
char	*ft_chunkdup(const char *);
char	*ft_strchr(const char *, int);
char	*ft_lststr(t_list *);