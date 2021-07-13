/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:19:30 by semin             #+#    #+#             */
/*   Updated: 2021/07/09 17:19:32 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		wdcount(char const *s, char c)
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

static char		**malloc_err(char **ret)
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

static void		my_strlcpy(char *dst, char *src, int size)
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

int		ft_strchr(char *s, char c)
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

int				split_quotes(char *s, char **ret, int *i, char c)
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

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (wdcount(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		s += split_quotes((char *)s, ret, &i, '\'');
		s += split_quotes((char *)s, ret, &i, '\"');
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s != c && *s)
				s++;
			ret[i] = (char *)malloc(s - tmp + 1);
			if (!ret[i])
				return (malloc_err(ret));
			my_strlcpy(ret[i++], tmp, s - tmp + 1);
		}
		if (*s)
			s++;
	}
	ret[i] = 0;
	return (ret);
}
