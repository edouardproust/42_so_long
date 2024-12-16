/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:50 by eproust           #+#    #+#             */
/*   Updated: 2024/12/16 03:48:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "MLX42.h"

# define GAME_NAME "Pognon Knight"

# define CELL_LEN_PX 60
# define MOVE_TIMEOUT 3

# define TX_FLOOR "asset/floor.png"
# define TX_FLOOR_I 0
# define TX_WALL "asset/wall.png"
# define TX_WALL_I 1
# define TX_EXIT_CLOSED "asset/exit_closed.png"
# define TX_EXIT_CLOSED_I 2
# define TX_EXIT_HALF "asset/exit_half.png"
# define TX_EXIT_HALF_I 3
# define TX_EXIT_OPEN "asset/exit_open.png"
# define TX_EXIT_OPEN_I 4
# define TX_COLLEC "asset/collectible.png"
# define TX_COLLEC_I 5
# define TX_COLLEC_OK "asset/collectible_taken.png"
# define TX_COLLEC_OK_I 6
# define TX_PLAYER_FRONT "asset/player_front.png"
# define TX_PLAYER_FRONT_I 7
# define TX_PLAYER_RIGHT "asset/player_right.png"
# define TX_PLAYER_RIGHT_I 8
# define TX_PLAYER_LEFT "asset/player_left.png"
# define TX_PLAYER_LEFT_I 9
# define TX_PLAYER_BACK "asset/player_back.png"
# define TX_PLAYER_BACK_I 10
# define TX_ENEMY "asset/enemy.png"
# define TX_ENEMY_I 11
# define TX_MOVES_BG "asset/ribbon.png"
# define TX_MOVES_BG_I 12
# define TX_MOVES_LABEL "Moves:"
# define TX_MOVES_LABEL_I 13
# define TX_MOVES_COUNT	"0"
# define TX_MOVES_COUNT_I 14
# define TX_END_SCREEN_BG "asset/text_bg_op70.png"
# define TX_END_SCREEN_BG_I 15
# define TX_WIN "asset/win.png"
# define TX_GAMEOVER "asset/fail.png"
# define TX_WIN_GAMEOVER_I 16

# define TX_FLOOR_Z 0
# define TX_WALL_Z 8
# define TX_EXIT_Z 2
# define TX_COLLEC_Z 2
# define TX_PLAYER_Z 4
# define TX_ENEMY_Z 5
# define MOVES_COUNTER_Z 10
# define TX_END_SCREEN_Z 20

# define MOVES_BG_X 10
# define MOVES_BG_Y 10
# define MOVES_BG_WIDTH 200
# define MOVES_BG_HEIGHT 44
# define MOVES_LABEL_X 60
# define MOVES_LABEL_Y 16

// display_init.c
void	display_game(t_map *map);

// display_init_map.c
void put_game_map(t_game *game);

// display_events.c
void	on_key_press(mlx_key_data_t keydata, void *param);

// display_move_player.c
void move_player(int dir_x, int dir_y, t_game *game);

// display_update_data.c
void	update_collectibles(t_point *dest, t_game *game);
void	update_is_win(t_game *game);
void	update_print_moves(t_game *game);

// display_utils.c
void	set_image(char *filepath, int index, t_game *game);
size_t  get_instance_index(mlx_image_t *img, int r, int c);
void	replace_image(t_game *game, int old_image_index, int new_image_index, int instance_index);
mlx_instance_t	*print_image(int img_index, t_point *pt, t_game *game, bool show);
mlx_instance_t	*print_image_str(int img_index, char *str, t_point *pt, t_game *game);

// utils.c
t_point *set_gpoint(t_point *pt, int x, int y, int z);
t_point *update_gpoint(t_point *pt, char xyz, int val);

// utils_exit.c
void	free_game(t_game *game);

#endif
