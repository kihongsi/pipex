/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:02:29 by semin             #+#    #+#             */
/*   Updated: 2021/07/07 17:01:22 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent(int fd, char *file, char *cmd)
{
	char	*command;

	command = ft_strjoin("/bin/", cmd);
	rd_in(file, fd);
	execve(command, 0, 0);
	return (0);
}

int child(int fd, char *file, char *cmd)
{
	char	*command;

	command = ft_strjoin("/bin/", cmd);
	rd_out(file, fd);
	execve(command, 0, 0);
	return (0);
}

int	main(int ac, char *av[])
{
	(void)ac;
	int     fd[2];
	pid_t   pid;
	int		status;

	if (pipe(fd) < 0)
	{
		perror("zsh");
		exit(1);
	}
	pid = fork();
	if (pid > 0) //parent
	{
		close(fd[0]);
		parent(fd[1], av[1], av[2]);
		wait(&status);
	}
	else // child
	{
		close(fd[1]);
		child(fd[0], av[4], av[3]);
	}
	exit(0);
}
