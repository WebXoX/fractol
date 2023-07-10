# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:04:44 by jperinch          #+#    #+#              #
#    Updated: 2022/08/09 12:01:22 by jperinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c     ft_putchar.c    ft_putnbr.c     ft_putstr.c	


CFLAG = -Wall -Wextra -Werror
CC = gcc
OBJ = $(SRC:.c=.o)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	

all: $(NAME)


clean:
	rm -rf *.o 

fclean:
	rm -f $(NAME) *.o 

re:     fclean all