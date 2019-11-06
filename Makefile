# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 11:34:24 by npimenof          #+#    #+#              #
#    Updated: 2019/11/06 16:11:59 by npimenof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs

SRCS1 = srcs/fillit_read.c srcs/fillit_solve.c srcs/fillit_validate.c srcs/main.c

OBJS = fillit_read.o fillit_solve.o fillit_validate.o main.o

# OBJS2 = $(subst srcs//,,$(OBJS))

LIB = -L./libft -lft

INCL = -I ./incl -I ./libft/includes/

all:
	gcc $(FLAGS) -c $(SRCS1) $(INCL)
	gcc $(FLAGS) $(INCL) $(OBJS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all