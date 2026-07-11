/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:00:46 by llinda            #+#    #+#             */
/*   Updated: 2026/07/11 21:10:50 by llinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*ptr;

	read(fd, buffer, BUFFER_SIZE);
	ptr = malloc(BUFFER_SIZE);
}