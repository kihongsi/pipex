/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:36:14 by semin             #+#    #+#             */
/*   Updated: 2021/07/07 16:53:33 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *s)
{
	int ret;

	ret = 0;
	while (*s)
	{
		ret++;
		s++;
	}
	return (ret);
}

char		*ft_strjoin(char *dir, char *cmd)
{
	char    *ret;
	int     len;
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
