#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int fd[2];
	pid_t pid;

	pipe(fd);
	pid = fork();
	execve("/bin/ls", NULL, NULL);
}
