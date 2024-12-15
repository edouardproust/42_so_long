/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:13:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/15 02:49:50 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Updates the player's position in the map
static void update_player_position(t_point *dest, t_game *game)
{
	t_point *pt;

	pt = game->map->player;
	game->map->content[pt->y][pt->x] = '0';
	update_gpoint(pt, 'x', dest->x);
	update_gpoint(pt, 'y', dest->y);
	game->map->content[dest->y][dest->x] = 'P';
}

static void update_player_sprite(t_point *dest, int dir_x, int dir_y, t_game *game)
{
	int	old_sprite_index;
	int	new_sprite_index;
	mlx_instance_t *sprite;

	old_sprite_index = game->player_img_index;
	if (dir_y == -1 && old_sprite_index != TX_PLAYER_BACK_I)
		new_sprite_index = TX_PLAYER_BACK_I;
	else if (dir_y == 1 && old_sprite_index != TX_PLAYER_FRONT_I)
		new_sprite_index = TX_PLAYER_FRONT_I;
	else if (dir_x == 1 && old_sprite_index != TX_PLAYER_RIGHT_I)
		new_sprite_index = TX_PLAYER_RIGHT_I;
	else if (dir_x == -1 && old_sprite_index != TX_PLAYER_LEFT_I)
		new_sprite_index = TX_PLAYER_LEFT_I;
	else
		new_sprite_index = old_sprite_index;
	if (new_sprite_index != old_sprite_index)
	{
		replace_image(game, old_sprite_index, new_sprite_index, 0);
		game->player_img_index = new_sprite_index;
	}
	sprite = &game->images[new_sprite_index]->instances[0];
	sprite->x = dest->x * CELL_LEN_PX;
	sprite->y = dest->y * CELL_LEN_PX;
}

// Moves the player in the given direction
void move_player(int dir_x, int dir_y, t_game *game)
{
	t_point *origin;
	t_point dest;

	origin = game->map->player;
	check_victory(origin, game);
	dest.x = origin->x + dir_x;
	dest.y = origin->y + dir_y;
	if (game->map->content[dest.y][dest.x] == '1')
		return ;
	update_collectibles(&dest, game);
	update_player_position(&dest, game);
	update_player_sprite(&dest, dir_x, dir_y, game);
	if (!check_victory(&dest, game))
		update_print_moves(game);
}
