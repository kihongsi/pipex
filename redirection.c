/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:21:50 by semin             #+#    #+#             */
/*   Updated: 2021/07/14 19:26:24 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	rd_in(char *file)
{
	int	newfd;

	newfd = open(file, O_RDONLY);
	if (newfd < 0)
	{
		perror("zsh");
		return (-1);
	}
	dup2(newfd, 0);
	close(newfd);
	return (0);
}

int	rd_out(char *file)
{
	int	newfd;

	newfd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (newfd < 0)
	{
		perror("zsh");
		return (-1);
	}
	dup2(newfd, 1);
	close(newfd);
	return (0);
}
