NAME = so_long

C_DIR = src/
C_FILES = $(shell find ./src -iname "*.c")
O_FILES = $(C_FILES:.c=.o)

H_DIR = include/
H_FILES = $(shell find ./include -iname "*.h")

LIBPRINTF_DIR = lib/printf/
LIBPRINTF = $(LIBPRINTF_DIR)libftprintf.a

LIBMLX_DIR = lib/mlx42/
LIBMLX = $(LIBMLX_DIR)build/libmlx42.a

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBMLX_DIR)include/MLX42 -I$(H_DIR) -I$(LIBPRINTF_DIR) -I$(LIBPRINTF_DIR)libft
LIBS = $(LIBPRINTF) $(LIBMLX) -ldl -lglfw -pthread -lm

all: libprintf libmlx $(NAME)

%.o: %.c Makefile $(H_FILES) $(LIBPRINTF) $(LIBMLX)
	cc $(CFLAGS) -c -o $@ $< $(INCLUDES)

libprintf:
	$(MAKE) -C $(LIBPRINTF_DIR)

libmlx:
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
	make -C $(LIBMLX_DIR)/build -j4

$(NAME): $(O_FILES)
	cc -o $@ $(O_FILES) $(LIBS)

clean:
	rm -f $(O_FILES)
	$(MAKE) -C $(LIBPRINTF_DIR) clean
	rm -rf $(LIBMLX)/build
 
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBPRINTF)

re: fclean all

.PHONY: all libprintf libmlx clean fclean re
