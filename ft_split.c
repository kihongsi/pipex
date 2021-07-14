/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:19:30 by semin             #+#    #+#             */
/*   Updated: 2021/07/14 20:03:33 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wdcount(char const *s, char c)
{
	int	wd;

	wd = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			wd++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (wd);
}

char	**malloc_err(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (0);
}

void	my_strlcpy(char *dst, char *src, int size)
{
	int		i;

	i = 0;
	while (i + 1 < size && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
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
		if (*s)
			s++;
	}
	ret[i] = 0;
	return (ret);
}
