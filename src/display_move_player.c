/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:13:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/16 03:48:48 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Updates the player's position in the map
static void update_player_position(t_point *dest, t_game *game)
{
	update_gpoint(&game->player, 'x', dest->x);
	update_gpoint(&game->player, 'y', dest->y);
	game->player_map_char = game->map->content[dest->y][dest->x];
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
	t_point dest;

	dest.x = game->player.x + dir_x;
	dest.y = game->player.y + dir_y;
	if (game->map->content[dest.y][dest.x] == '1')
		return ;
	update_collectibles(&dest, game);
	update_player_position(&dest, game);
	update_player_sprite(&dest, dir_x, dir_y, game);
	update_print_moves(game);
	update_is_win(game);
}
