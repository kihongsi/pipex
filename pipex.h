/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:01:05 by semin             #+#    #+#             */
/*   Updated: 2021/07/09 09:53:21 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

void		parent(int fd, char *cmd);
void		child(int fd, char *cmd);
char		*ft_strjoin(char *dir, char *cmd);
int			rd_in(char *file);
int			rd_out(char *file);
char		**ft_split(char const *s, char c);

#endif
