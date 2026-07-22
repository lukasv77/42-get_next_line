/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:59:58 by llinda            #+#    #+#             */
/*   Updated: 2026/07/22 21:21:25 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_lstnew_back(t_list **lst, char *content);
char	*ft_chunkdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_mvcontent(t_list *lst, char *ptr);
char	*ft_lststr(t_list *lst);