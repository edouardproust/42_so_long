/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:57:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 02:24:57 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define TILE_WIDTH 60
# define TILE_HEIGHT 60

# define TX_DIR "asset/grass/"
# define TX_FLOOR TX_DIR "floor.xpm"
# define TX_WALL TX_DIR "wall.xpm"
# define TX_PLAYER TX_DIR "player.xpm"
# define TX_PLAYER_BACK TX_DIR "player_back.xpm"
# define TX_COLLEC TX_DIR "collectible.xpm"
# define TX_EXIT TX_DIR "exit.xpm"
# define TX_EXIT_OPEN TX_DIR "exit_open.xpm"

int	show_window(t_map *map);

#endif
