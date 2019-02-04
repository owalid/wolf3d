# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/31 17:22:25 by oel-ayad          #+#    #+#              #
#    Updated: 2019/02/04 15:26:07 by gdrai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
CPPFLAGS = -I./includes/

SRC_NAME = main.c \
			hook.c \
			wolf_calc.c \
			wolf_err.c \
			wolf_init.c \
			wolf_windows.c \
			wolf_parsing.c \
			wolf_move.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LDFLAGS = -L./libft/
LFT = -lft

CC = gcc $(CFLAGS) -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

MLX = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	make -C./libft/
	make -C./minilibx_macos/
	$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft/
	make clean -C ./minilibx_macos/
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
