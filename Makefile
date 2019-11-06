# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 11:34:24 by npimenof          #+#    #+#              #
#    Updated: 2019/11/06 13:30:39 by npimenof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS1 = srcs/fillit_read.c srcs/fillit_solve.c srcs/fillit_validate.c srcs/main.c

OBJS = $(SRCS1:.c=.o)

LIB = -L./libft -lft

INCL = -I ./incl -I ./libft/includes/

all:
	gcc $(FLAGS) -c $(SRCS1) $(INCL)
	gcc $(FLAGS) -o $(NAME) $(INCL) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all