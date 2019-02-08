# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdrai <gdrai@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:32:56 by glavigno          #+#    #+#              #
#    Updated: 2019/02/06 20:32:01 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_atol.c \
			ft_atoll.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strjoinfree.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_print_int_tab.c \
			ft_print_str_tab.c \
			ft_swap.c \
			ft_create_elem.c \
			ft_list_push_back.c \
			ft_list_push_front.c \
			ft_list_size.c \
			ft_list_last.c \
			ft_list_push_params.c \
			ft_list_clear.c \
			ft_list_foreach.c \
			ft_list_at.c \
			ft_list_merge.c \
			ft_sort_integer_table.c \
			ft_factorial.c \
			ft_power.c \
			ft_sqrt.c \
			ft_is_prime.c \
			ft_tablen.c \
			ft_sort_wordtab.c \
			ft_strcapitalize.c \
			ft_strrev.c \
			ft_ismaj.c \
			ft_ismin.c \
			ft_freeturn.c \
			ft_strlower.c \
			ft_strndup.c \
			ft_cisin.c \
			ft_strjoin_free.c \
			get_next_line.c \

OBJ = $(SRC:.c=.o)

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[0;32m$@ created ✓\033[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31mlibft.a deleted ✗\033[0m"

re: fclean all

.PHONY: all clean fclean re
