#include <unistd.h>
#include <stdio.h>
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

int main(int ac, char *av[])
{
	int fd[2];
	pid_t pid;

	rd_in(av[1]);
	run_cmd(av[2]);
}
