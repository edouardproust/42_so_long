# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:09:46 by eproust           #+#    #+#              #
#    Updated: 2024/10/19 19:08:05 by eproust          ###   ########.fr        #
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

HEADERS =		ft_printf.h
HEADERS_DIR =	includes/
HEADERS_H =		$(addprefix $(HEADERS_DIR), $(HEADERS))

LIB_DIR =		libft/
LIB_A =			$(LIB_DIR)libft.a

FLAGS =			-Wall -Werror -Wextra

# Output styling
BOLD :=			\033[1m
BLUE :=			\033[94m
GREEN :=		\033[92m
ORANGE :=		\033[91m
END :=			\033[0m


all:			$(NAME)

%.o:        	%.c Makefile $(HEADERS_H)
				@echo "\nCompiling $(BLUE)$<$(END):"
				cc -c $< -o $@ $(FLAGS) -I $(HEADERS_DIR) -I $(LIB_DIR)

$(NAME):    	$(LIB_A) $(SRCS_O)
				@echo "\n$(BOLD)$(BLUE)Creating $(NAME)$(END)"
				cp $(LIB_A) $@
				ar rcs $@ $^

$(LIB_A):
				@echo "\nCreating $(BLUE)$(LIB_A)$(END)"
				$(MAKE) -C $(LIB_DIR)

clean:
				@echo "\n$(BOLD)$(BLUE)Removing all .o files$(END)"
				rm -f $(SRCS_O)
				@echo "\n$(BOLD)$(BLUE)Removing all library .o files$(END)"
				$(MAKE) -C $(LIB_DIR) clean

fclean:     	clean
				@echo "\n$(BOLD)$(BLUE)Removing target file$(END)"
				rm -f $(NAME)
				@echo "\n$(BOLD)$(BLUE)Removing library target file$(END)"
				rm -f $(LIB_A)
			
re:         	fclean all

.PHONY: all clean fclean re
