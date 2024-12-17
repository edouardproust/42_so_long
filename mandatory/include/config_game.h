/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:50 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 21:41:18 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_GAME_H
# define CONFIG_GAME_H

# define GAME_NAME "Pognon Knight"

# define BUFFER_SIZE 100

# define CELL_LEN_PX 60

# define TX_FLOOR "mandatory/asset/floor.png"
# define TX_FLOOR_I 0
# define TX_WALL "mandatory/asset/wall.png"
# define TX_WALL_I 1
# define TX_EXIT_CLOSED "mandatory/asset/exit_closed.png"
# define TX_EXIT_CLOSED_I 2
# define TX_EXIT_HALF "mandatory/asset/exit_half.png"
# define TX_EXIT_HALF_I 3
# define TX_EXIT_OPEN "mandatory/asset/exit_open.png"
# define TX_EXIT_OPEN_I 4
# define TX_COLLEC "mandatory/asset/collectible.png"
# define TX_COLLEC_I 5
# define TX_COLLEC_OK "mandatory/asset/collectible_taken.png"
# define TX_COLLEC_OK_I 6
# define TX_PLAYER_FRONT "mandatory/asset/player_front.png"
# define TX_PLAYER_FRONT_I 7
# define TX_PLAYER_RIGHT "mandatory/asset/player_right.png"
# define TX_PLAYER_RIGHT_I 8
# define TX_PLAYER_LEFT "mandatory/asset/player_left.png"
# define TX_PLAYER_LEFT_I 9
# define TX_PLAYER_BACK "mandatory/asset/player_back.png"
# define TX_PLAYER_BACK_I 10
# define TX_END_SCREEN_BG "mandatory/asset/text_bg_op70.png"
# define TX_END_SCREEN_BG_I 11
# define TX_WIN "mandatory/asset/win.png"
# define TX_GAMEOVER "mandatory/asset/fail.png"
# define TX_WIN_GAMEOVER_I 12

# define TX_FLOOR_Z 0
# define TX_WALL_Z 8
# define TX_EXIT_Z 2
# define TX_COLLEC_Z 2
# define TX_PLAYER_Z 4
# define TX_END_SCREEN_Z 10

#endif
