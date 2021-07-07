/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:01:05 by semin             #+#    #+#             */
/*   Updated: 2021/07/07 16:55:26 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int	        parent(int fd, char *file, char *cmd);
int         child(int fd, char *file, char *cmd);
char		*ft_strjoin(char *dir, char *cmd);
int		    rd_in(char *file, int oldfd);
int		    rd_out(char *file, int oldfd);

#endif
