# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 16:09:44 by eproust           #+#    #+#              #
#    Updated: 2024/12/05 20:54:41 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

C_FILES = main.c \
	map_check.c \
	utils.c
C_PATHS = $(addprefix src/, $(C_FILES))
O_PATHS = $(C_PATHS:.c=.o)

H_FILES = so_long.h
H_PATHS = $(addprefix include/, $(H_FILES))

PRINTF_DIR = lib/libftprintf/
A_PRINTF = $(LIB_DIR)libftprintf.a
LIBFT_DIR = $(LIB_DIR)libft/

FLAGS = -Wall -Werror -Wextra -lm -I $(PRINTF_DIR) -I $(LIBFT_DIR)

all: make_lib $(NAME)

%.c: %.o Makefile $(H_PATHS) $(A_PRINTF)
	cc $(FLAGS) -c $< -o $@

make_lib:
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(O_PATHS)
	cc $(FLAGS) $(O_PATHS) $(A_PRINTF) -o $@

clean:
	rm -f $(O_PATHS)
	$(MAKE) -C $(PRINTF_DIR) clean
 
fclean: clean
	rm -f $(NAME)
	rm -f $(A_PRINTF)

re:
	$(MAKE) all

.PHONY: all clean fclean re
