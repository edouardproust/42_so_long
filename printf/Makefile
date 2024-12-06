# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:09:46 by eproust           #+#    #+#              #
#    Updated: 2024/12/06 20:19:36 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

SRCS = 			ft_printf.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_int.c \
				ft_print_uint.c \
				ft_print_hexa.c \
				ft_print_ptr.c
SRCS_DIR =		srcs/
SRCS_C =		$(addprefix $(SRCS_DIR), $(SRCS))
SRCS_O =		$(SRCS_C:.c=.o)

HEADERS_H =		ft_printf.h

LIB_DIR =		libft/
LIB_A =			$(LIB_DIR)libft.a

FLAGS =			-Wall -Werror -Wextra

# Output styling
BOLD :=			\033[1m
BLUE :=			\033[94m
GREEN :=		\033[92m
ORANGE :=		\033[91m
END :=			\033[0m


all:			make_libft $(NAME)

%.o:        	%.c Makefile $(HEADERS_H)
				cc -c $< -o $@ $(FLAGS) -I. -I$(LIB_DIR)

make_libft:
				$(MAKE) -C $(LIB_DIR)

$(NAME):    	$(SRCS_O) $(LIB_A)
				cp $(LIB_A) $@
				ar rcs $@ $^

clean:
				rm -f $(SRCS_O)
				$(MAKE) -C $(LIB_DIR) clean

fclean:     	clean
				rm -f $(NAME)
				rm -f $(LIB_A)
			
re:         	fclean all

.PHONY: all clean fclean re make_libft
