/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:57:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 04:40:43 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define CELL_LEN_PX 60

# define SPRITES_DIR "asset/grass/"
# define SPRITE_FLOOR SPRITES_DIR "floor.xpm"
# define SPRITE_WALL SPRITES_DIR "wall.xpm"
# define SPRITE_PLAYER SPRITES_DIR "player.xpm"
# define SPRITE_PLAYER_BACK SPRITES_DIR "player_back.xpm"
# define SPRITE_COLLEC SPRITES_DIR "collectible.xpm"
# define SPRITE_EXIT SPRITES_DIR "exit.xpm"
# define SPRITE_EXIT_OPEN SPRITES_DIR "exit_open.xpm"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	
} t_data;

// display_game.c
void	display_game(t_map *map, char *game_name);

// mlx_events
int	on_destroy(t_data *data);
int	on_keypress(int keysym, t_data *data);

#endif
