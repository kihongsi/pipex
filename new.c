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

char			**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	//char	*tmp;
	int		s_ret;

	ret = (char **)malloc(sizeof(char *) * (wdcount(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		s += split_quotes((char *)s, ret, &i, '\'');
		s += split_quotes((char *)s, ret, &i, '\"');
		s_ret = split_space((char *)s, ret, &i, ' ');
		if (s_ret < 0)
			return (0);
		s += s_ret;
		/*if (*s != c)
		{
			tmp = (char *)s;
			while (*s != c && *s)
				s++;
			ret[i] = (char *)malloc(s - tmp + 1);
			if (!ret[i])
				return (malloc_err(ret));
			my_strlcpy(ret[i++], tmp, s - tmp + 1);
		}*/
		if (*s)
			s++;
	}
	ret[i] = 0;
	return (ret);
}
