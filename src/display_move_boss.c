/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_boss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:17:54 by eproust           #+#    #+#             */
/*   Updated: 2024/12/15 23:57:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_boss_sprite(int dir_x, int dir_y, t_game *game)
{
	int old_sprite_index;
	int new_sprite_index;
	mlx_instance_t *sprite;

	old_sprite_index = game->boss_img_index;
	if (dir_y == -1 && old_sprite_index != TX_BOSS_BACK_I)
		new_sprite_index = TX_BOSS_BACK_I;
	else if (dir_y == 1 && old_sprite_index != TX_BOSS_FRONT_I)
		new_sprite_index = TX_BOSS_FRONT_I;
	else if (dir_x == 1 && old_sprite_index != TX_BOSS_RIGHT_I)
		new_sprite_index = TX_BOSS_RIGHT_I;
	else if (dir_x == -1 && old_sprite_index != TX_BOSS_LEFT_I)
 		new_sprite_index = TX_BOSS_LEFT_I;
	else
		new_sprite_index = old_sprite_index;
	if (new_sprite_index != old_sprite_index)
	{
		replace_image(game, old_sprite_index, new_sprite_index, 0);
		game->boss_img_index = new_sprite_index;
	}
	sprite = &game->images[new_sprite_index]->instances[0];
	sprite->x = (game->boss.x + dir_x) * CELL_LEN_PX;
	sprite->y = (game->boss.y + dir_y) * CELL_LEN_PX;
}

void update_boss_position(t_game *game)
{
	int dir_x = 0;
	int dir_y = 0;

	if (game->boss.x > game->player.x)
		dir_x = -1;
    else if (game->boss.x < game->player.x)
		dir_x = 1;
	if (game->boss.y > game->player.y)
		dir_y = -1;
	else if (game->boss.y < game->player.y)
		dir_y = 1;
	int new_x = game->boss.x + dir_x;
	int new_y = game->boss.y + dir_y;
	if (dir_x != 0 && game->map->content[game->boss.y][new_x] != '1')
	{
		update_boss_sprite(dir_x, 0, game);
		update_gpoint(&game->boss, 'x', new_x);
    }
	else if (dir_y != 0 && game->map->content[new_y][game->boss.x] != '1')
	{
		update_boss_sprite(0, dir_y, game);
		update_gpoint(&game->boss, 'y', new_y);
    }
}
