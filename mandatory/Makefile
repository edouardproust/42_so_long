# ===================== EXECUTABLE ========================#


NAME = ../so_long


# ===================== SRCS / OBJS =======================#


C_FILES = display_events.c \
	display_init.c \
	display_init_map.c \
	display_move_player.c \
	display_update_data.c \
	display_utils.c \
	main.c \
	map_init.c \
	map_init_validate.c \
	map_init_validate_path.c \
	utils.c \
	utils_exit.c

SRCS = $(addprefix src/, $(C_FILES))

OBJS = $(SRCS:.c=.o)


# ===================== HEADERS ===========================#


H_DIR = include

H_FILES = config_exit.h \
	config_game.h \
	functions.h \
	so_long.h \
	structures.h

HEADERS = $(addprefix include/, $(H_FILES))


# ===================== FLAGS =============================#


CFLAGS = -Wall -Wextra -Werror


# ===================== LIBRARIES =========================#


PRINTF_DIR = ../lib/printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = ../lib/mlx42

MLX = $(MLX_DIR)/build/libmlx42.a

LIBS = $(PRINTF) $(MLX) -ldl -lglfw -pthread -lm


# ===================== INCLUDES ==========================#


INCLUDES = -I$(H_DIR) -I$(MLX_DIR)/include/MLX42 -I$(PRINTF_DIR) -I$(PRINTF_DIR)/libft


# ===================== RULES =============================#


all: $(NAME)

%.o: %.c Makefile $(HEADERS) $(PRINTF) $(MLX)
	cc $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	cc -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)

re: fclean all


# ===================== PHONY =============================#


.PHONY: all clean fclean re
