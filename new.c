#include "pipex.h"


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
