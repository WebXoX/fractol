# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 12:01:22 by jperinch          #+#    #+#              #
#    Updated: 2023/07/12 12:55:27 by jperinch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC = 	  additionalmlx.c         fractol.c               ft_atoi.c                string_function.c\
			events.c                freed.c                 ft_strncmp.c            main.c                  push_swap.h             wordcheck.c

OBJ	= $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 
CC = gcc

MLX_PATH	= ../mlx/
MLX_NAME	= libmlx.dylib
MLX			= $(MLX_PATH)$(MLX_NAME)

PRINTF_PATH	= FT_PRINTF/
PRINTF_NAME	= libftprintf.a
PRINTF		= $(PRINTF_PATH)$(PRINTF_NAME)



all: $(PRINTF) $(MLX) $(NAME)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)
	
$(PRINTF):
	@echo "Making PRINTF..."
	@make -sC $(PRINTF_PATH)

	


$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(PRINTF) $(MLX) *.c -o $(NAME)

clean:
	rm -rf *.o 
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(PRINTF_PATH)


fclean:
	rm -f $(NAME) *.o 
	@make clean -sC $(MLX_PATH)
	@make fclean -sC $(PRINTF_PATH)


re:     fclean all