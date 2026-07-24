/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:59:58 by llinda            #+#    #+#             */
/*   Updated: 2026/07/24 20:19:06 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew_back(t_list **lst, char *content);
char	*ft_chunkdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_mvcontent(t_list *lst, char *ptr);
char	*ft_lststr(t_list *lst);

#endif