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

void	run_cmd(char *cmd)
{
	char	**ret;
	char	*command;

	ret = ft_split(cmd, ' ');
	command = ft_strjoin("/bin/", ret[0]);
	execve(command, ret, 0);
}

void	parent(int fd, char *file, char *cmd)
{
	rd_in(file);
	dup2(fd, 1);
	close(fd);
	run_cmd(cmd);
}

void	child(int fd, char *file, char *cmd)
{
	rd_out(file);
	dup2(fd, 0);
	close(fd);
	//printf("hihi\n");
	run_cmd(cmd);
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
		waitpid(pid, &status, 0);
		close(fd[0]);
		parent(fd[1], av[1], av[2]);
	}
	else // child
	{
		close(fd[1]);
		child(fd[0], av[4], av[3]);
	}
	exit(0);
}
