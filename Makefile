NAME = so_long

C_DIR = src/
C_FILES = main.c \
	map_init.c \
	map_init_validate.c \
	map_init_validate_path.c \
	utils.c \
	utils_exit.c

C_PATHS = $(addprefix $(C_DIR), $(C_FILES))
O_PATHS = $(C_PATHS:.c=.o)

H_DIR = include/
H_FILES = so_long.h \
	exit_status.h
H_PATHS = $(addprefix $(H_DIR), $(H_FILES))

PRINTF_DIR = lib/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

FLAGS = -Wall -Werror -Wextra -I$(H_DIR) -I$(PRINTF_DIR) -I$(PRINTF_DIR)libft/

all: make_libft $(NAME)

%.o: %.c Makefile $(H_PATHS) $(PRINTF)
	cc $(FLAGS) -c $< -o $@

make_libft:
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(O_PATHS) $(PRINTF)
	cc $(FLAGS) $(O_PATHS) $(PRINTF) -o $@

clean:
	rm -f $(O_PATHS)
	$(MAKE) -C $(PRINTF_DIR) clean
 
fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF)

re:
	$(MAKE) all

.PHONY: all clean fclean re
