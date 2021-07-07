/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:21:50 by semin             #+#    #+#             */
/*   Updated: 2021/07/07 16:55:17 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		rd_in(char *file, int oldfd)
{
	int	newfd;

	newfd = open(file, O_RDONLY);
	if (newfd < 0)
	{
		perror("zsh");
		return (-1);
	}
	dup2(newfd, oldfd);
	close(newfd);
	return (0);
} //newfd -> oldfd

int		rd_out(char *file, int oldfd)
{
	int newfd;

	newfd = open(file, O_RDWR | O_CREAT, 0644);
	if (newfd < 0)
	{
		perror("zsh");
		return (-1);
	}
	dup2(newfd, oldfd);
	close(newfd);
	return (0);
} //oldfd -> newfd
