/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:50 by eproust           #+#    #+#             */
/*   Updated: 2024/12/12 20:30:40 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "MLX42.h"

# define CELL_LEN_PX 60

# define ASSET_DIR "asset/"
# define TX_FLOOR ASSET_DIR "floor.png"
# define TX_WALL ASSET_DIR "wall.png"
# define TX_EXIT_CLOSED ASSET_DIR "exit_closed.png"
# define TX_EXIT_OPEN ASSET_DIR "exit_open.png"
# define TX_COLLEC ASSET_DIR "collectible.png"
# define TX_PLAYER_FRONT ASSET_DIR "player_front.png"
# define TX_PLAYER_BACK ASSET_DIR "player_back.png"

void	display_game(t_map *map, char *game_name);

#endif
