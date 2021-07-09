/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:02:29 by semin             #+#    #+#             */
/*   Updated: 2021/07/09 17:33:28 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(char *cmd)
{
	char	**ret;
	char	*command[5];
	int		i;

	ret = ft_split(cmd, ' ');
	command[0] = ft_strjoin("/bin/", ret[0]);
	command[1] = ft_strjoin("/usr/bin/", ret[0]);
	command[2] = ft_strjoin("/usr/local/bin/", ret[0]);
	command[3] = ft_strjoin("/usr/sbin/", ret[0]);
	command[4] = ft_strjoin("/sbin/", ret[0]);
	i = 0;
	while (i < 5)
	{
		execve(command[i], ret, 0);
		i++;
	}
	perror("command not found");
}

void	parent(int fd, char *cmd)
{
	dup2(fd, 0);
	close(fd);
	run_cmd(cmd);
}

void	child(int fd, char *cmd)
{
	dup2(fd, 1);
	close(fd);
	run_cmd(cmd);
}

int		main(int ac, char *av[])
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (ac != 5)
		return(0);
	if (pipe(fd) < 0)
	{
		perror("zsh");
		exit(1);
	}
	pid = fork();
	if (pid == 0) //child
	{
		close(fd[0]);
		rd_in(av[1]);
		child(fd[1], av[2]);
	}
	else
	{
		wait(&status);
		close(fd[1]);
		rd_out(av[4]);
		parent(fd[0], av[3]);
	}
	exit(0);
}
