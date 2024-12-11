NAME = so_long

C_DIR = src/
C_FILES = main.c \
	map_init.c \
	map_init_validate.c \
	map_init_validate_path.c \
	display.c \
	display_events.c \
	display_move.c \
	utils.c \
	utils_exit.c

C_PATHS = $(addprefix $(C_DIR), $(C_FILES))
O_PATHS = $(C_PATHS:.c=.o)

H_DIR = include/
H_FILES = so_long.h \
	exit_status.h \
	map.h \
	display.h
H_PATHS = $(addprefix $(H_DIR), $(H_FILES))

PRINTF_DIR = lib/printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

MLX_DIR = lib/minilibx_linux/
MLX = $(MLX_DIR)libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(MLX_DIR) -I$(H_DIR) -I$(PRINTF_DIR) -I$(PRINTF_DIR)libft/
LIBS = $(PRINTF) $(MLX) -L/usr/lib/X11 -lXext -lX11 -lm -lz

all: make_libft make_mlx $(NAME)

%.o: %.c Makefile $(H_PATHS) $(PRINTF) $(MLX)
	cc $(CFLAGS) -c -o $@ $< $(INCLUDES)

make_libft:
	$(MAKE) -C $(PRINTF_DIR)

make_mlx:
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(O_PATHS) $(PRINTF)
	cc $(CFLAGS) -o $@ $(O_PATHS) $(LIBS)

clean:
	rm -f $(O_PATHS)
	$(MAKE) -C $(PRINTF_DIR) clean
 
fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF)

re:
	$(MAKE) all

.PHONY: all clean fclean re
