/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:57:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 20:39:47 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# include <X11/X.h>

# define CELL_LEN_PX 60

# define SPRITES_DIR "asset/grass/"
# define SPRITE_FLOOR SPRITES_DIR "floor.xpm"
# define SPRITE_WALL SPRITES_DIR "wall.xpm"
# define SPRITE_PLAYER SPRITES_DIR "player.xpm"
# define SPRITE_PLAYER_BACK SPRITES_DIR "player_back.xpm"
# define SPRITE_COLLEC SPRITES_DIR "collectible.xpm"
# define SPRITE_EXIT SPRITES_DIR "exit.xpm"
# define SPRITE_EXIT_OPEN SPRITES_DIR "exit_open.xpm"

# define XK_ESC 0xFF1B 
# define XK_W 0x0077
# define XK_A 0x0061
# define XK_S 0x0073
# define XK_D 0x0064
# define XK_UP 0xFF52
# define XK_DOWN 0xFF54
# define XK_LEFT 0xFF51
# define XK_RIGHT 0xFF53

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*sprites[81];
	t_map	*map;
	int		cell_w;
	int		cell_h;
	int		moves;
	int		exit_open;
} t_data;

// display_game.c
void	display_game(t_map *map, char *game_name);
void	display_sprites(t_data *data);

// display_move.c
int		move_player(t_data *data, int dir_x, int dir_y);
void	update_moves_print(t_data *data);

// mlx_events
int		on_destroy(t_data *data);
int		on_loop(t_data *data);
int		on_keypress(int keysym, t_data *data);

#endif
