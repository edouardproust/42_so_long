# ===================== EXECUTABLE ========================#


NAME = ../so_long_bonus


# ===================== SRCS / OBJS =======================#


C_FILES = display_events_bonus.c \
	display_init_bonus.c \
	display_init_map_bonus.c \
	display_move_player_bonus.c \
	display_update_data_bonus.c \
	display_utils_bonus.c \
	main_bonus.c \
	map_init_bonus.c \
	map_init_validate_bonus.c \
	map_init_validate_path_bonus.c \
	utils_bonus.c \
	utils_exit_bonus.c

SRCS = $(addprefix src/, $(C_FILES))

OBJS = $(SRCS:.c=.o)


# ===================== HEADERS ===========================#


H_DIR = include

H_FILES = config_exit_bonus.h \
	config_game_bonus.h \
	functions_bonus.h \
	so_long_bonus.h \
	structures_bonus.h

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
