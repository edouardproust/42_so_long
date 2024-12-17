# ===================== NAME ==============================#

NAME = so_long

NAME_BONUS = so_long_bonus

# ===================== DIR ===============================#

MANDATORY_DIR = mandatory

BONUS_DIR = bonus

# ===================== LIBRARIES =========================#

PRINTF_DIR = lib/printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = lib/mlx42

MLX = $(MLX_DIR)/build/libmlx42.a


# ===================== RULES =============================#


all: libprintf libmlx
	$(MAKE) -C $(MANDATORY_DIR)

bonus: libprintf libmlx
	$(MAKE) -C $(BONUS_DIR)

libprintf:
	$(MAKE) -C $(PRINTF_DIR)

libmlx:
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	$(MAKE) -C $(MLX_DIR)/build -j4

clean:
	$(MAKE) -C $(MANDATORY_DIR) clean
	$(MAKE) -C $(BONUS_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(MLX)/build
 
fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all


# ===================== PHONY =============================#

.PHONY: all bonus libprintf libmlx clean fclean re
