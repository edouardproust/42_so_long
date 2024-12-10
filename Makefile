NAME = so_long

C_DIR = src/
C_FILES = main.c \
	map_init.c \
	map_init_validate.c \
	map_init_validate_path.c \
	window.c \
	utils.c \
	utils_exit.c

C_PATHS = $(addprefix $(C_DIR), $(C_FILES))
O_PATHS = $(C_PATHS:.c=.o)

H_DIR = include/
H_FILES = so_long.h \
	exit_status.h \
	map.h \
	window.h
H_PATHS = $(addprefix $(H_DIR), $(H_FILES))

PRINTF_DIR = lib/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

MLX_DIR = lib/minilibx_linux/

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(MLX_DIR) -I$(H_DIR) -I$(PRINTF_DIR) -I$(PRINTF_DIR)libft/
LIBS = $(PRINTF) $(MLX_DIR)libmlx.a -lXext -lX11 -lm -lz

all: make_libft $(NAME)

%.o: %.c Makefile $(H_PATHS) $(PRINTF)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

make_libft:
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(O_PATHS) $(PRINTF)
	cc $(CFLAGS) $(O_PATHS) $(LIBS) -o $@

clean:
	rm -f $(O_PATHS)
	$(MAKE) -C $(PRINTF_DIR) clean
 
fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF)

re:
	$(MAKE) all

.PHONY: all clean fclean re
