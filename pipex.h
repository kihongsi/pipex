/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:01:05 by semin             #+#    #+#             */
/*   Updated: 2021/07/14 19:30:50 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

char		*ft_strjoin(char *dir, char *cmd);
int			rd_in(char *file);
int			rd_out(char *file);
char		**ft_split(char const *s, char c);

void	my_strlcpy(char *dst, char *src, int size);
char	**malloc_err(char **ret);
int	split_quotes(char *s, char **ret, int *i, char c);
int	split_space(char *s, char **ret, int *i, char c);

#endif
