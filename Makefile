# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 16:57:17 by semin             #+#    #+#              #
#    Updated: 2021/07/07 17:00:51 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c redirection.c util.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY: all clean fclean re
