/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_game_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:50 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 20:15:27 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_GAME_BONUS_H
# define CONFIG_GAME_BONUS_H

# define GAME_NAME "Pognon Knight"

# define BUFFER_SIZE 100

# define CELL_LEN_PX 60
# define ANIM_TIMEOUT 30

# define TX_FLOOR "bonus/asset/floor.png"
# define TX_FLOOR_I 0
# define TX_WALL "bonus/asset/wall.png"
# define TX_WALL_I 1
# define TX_EXIT_CLOSED "bonus/asset/exit_closed.png"
# define TX_EXIT_CLOSED_I 2
# define TX_EXIT_HALF "bonus/asset/exit_half.png"
# define TX_EXIT_HALF_I 3
# define TX_EXIT_OPEN "bonus/asset/exit_open.png"
# define TX_EXIT_OPEN_I 4
# define TX_COLLEC "bonus/asset/collectible.png"
# define TX_COLLEC_I 5
# define TX_COLLEC_OK "bonus/asset/collectible_taken.png"
# define TX_COLLEC_OK_I 6
# define TX_PLAYER_FRONT "bonus/asset/player_front.png"
# define TX_PLAYER_FRONT_I 7
# define TX_PLAYER_RIGHT "bonus/asset/player_right.png"
# define TX_PLAYER_RIGHT_I 8
# define TX_PLAYER_LEFT "bonus/asset/player_left.png"
# define TX_PLAYER_LEFT_I 9
# define TX_PLAYER_BACK "bonus/asset/player_back.png"
# define TX_PLAYER_BACK_I 10
# define TX_ENEMY "bonus/asset/enemy.png"
# define TX_ENEMY_I 11
# define TX_ENEMY2 "bonus/asset/enemy2.png"
# define TX_ENEMY2_I 12
# define TX_MOVES_BG "bonus/asset/ribbon.png"
# define TX_MOVES_BG_I 13
# define TX_MOVES_LABEL "Moves:"
# define TX_MOVES_LABEL_I 14
# define TX_MOVES_COUNT	"0"
# define TX_MOVES_COUNT_I 15
# define TX_END_SCREEN_BG "bonus/asset/text_bg_op70.png"
# define TX_END_SCREEN_BG_I 16
# define TX_WIN "bonus/asset/win.png"
# define TX_GAMEOVER "bonus/asset/fail.png"
# define TX_WIN_GAMEOVER_I 17

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

#endif
