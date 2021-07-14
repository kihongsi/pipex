/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:36:14 by semin             #+#    #+#             */
/*   Updated: 2021/07/15 00:48:49 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		ret++;
		s++;
	}
	return (ret);
}

char	*ft_strjoin(char *dir, char *cmd)
{
	char	*ret;
	int		len;
	int		i1;
	int		i2;

	len = ft_strlen(dir) + ft_strlen(cmd) + 1;
	ret = (char *)malloc(len);
	if (!ret)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (dir[i1])
		ret[i2++] = dir[i1++];
	i1 = 0;
	while (cmd[i1])
		ret[i2++] = cmd[i1++];
	ret[i2] = '\0';
	return (ret);
}

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (1);
}

int	split_quotes(char *s, char **ret, int *i, char c)
{
	char	*tmp;

	if (*s == c && *s)
	{
		s++;
		tmp = (char *)s;
		while (*s != c)
			s++;
		ret[*i] = (char *)malloc(s - tmp + 1);
		my_strlcpy(ret[*i], tmp, s - tmp + 1);
		(*i)++;
		return (s - tmp + 2);
	}
	return (0);
}

int	split_space(char *s, char **ret, int *i, char c)
{
	char	*tmp;

	if (*s != c)
	{
		tmp = s;
		while (*s != c && *s)
			s++;
		ret[*i] = (char *)malloc(s - tmp + 1);
		if (!ret[*i])
		{
			malloc_err(ret);
			return (-1);
		}
		my_strlcpy(ret[*i], tmp, s - tmp + 1);
		(*i)++;
		return (s - tmp);
	}
	return (0);
}
