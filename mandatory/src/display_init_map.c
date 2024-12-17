/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:41:58 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 21:38:31 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_cell_fixed_elements(t_point *cell_pt, char cell_char,
	t_game *game)
{
	update_gpoint(cell_pt, 'z', TX_FLOOR_Z);
	print_image(TX_FLOOR_I, cell_pt, game, true);
	if (cell_char == '1')
	{
		update_gpoint(cell_pt, 'z', TX_WALL_Z);
		print_image(TX_WALL_I, cell_pt, game, true);
	}
}

static void	put_cell_goal_elements(t_point *cell_pt, char cell_char,
	t_game *game)
{
	if (cell_char == 'C')
	{
		update_gpoint(cell_pt, 'z', TX_COLLEC_Z);
		print_image(TX_COLLEC_I, cell_pt, game, true);
		print_image(TX_COLLEC_OK_I, cell_pt, game, false);
	}
	if (cell_char == 'E')
	{
		update_gpoint(cell_pt, 'z', TX_EXIT_Z);
		print_image(TX_EXIT_CLOSED_I, cell_pt, game, true);
		print_image(TX_EXIT_OPEN_I, cell_pt, game, false);
		print_image(TX_EXIT_HALF_I, cell_pt, game, false);
	}
}

static void	put_cell_characters(t_point *cell_pt, char cell_char,
	t_game *game)
{
	if (cell_char == 'P')
	{
		update_gpoint(cell_pt, 'z', TX_PLAYER_Z);
		print_image(TX_PLAYER_FRONT_I, cell_pt, game, true);
		print_image(TX_PLAYER_RIGHT_I, cell_pt, game, false);
		print_image(TX_PLAYER_LEFT_I, cell_pt, game, false);
		print_image(TX_PLAYER_BACK_I, cell_pt, game, false);
	}
}

// Display game first screen (initial state before any moves)
void	put_game_map(t_game *game)
{
	size_t	r;
	size_t	c;
	char	cell_char;
	t_point	cell_pt;

	r = 0;
	while (r < game->map->rows)
	{
		c = 0;
		while (c < game->map->cols)
		{
			cell_char = game->map->content[r][c];
			set_gpoint(&cell_pt, c * CELL_LEN_PX, r * CELL_LEN_PX, 0);
			put_cell_fixed_elements(&cell_pt, cell_char, game);
			put_cell_goal_elements(&cell_pt, cell_char, game);
			put_cell_characters(&cell_pt, cell_char, game);
			c++;
		}
		r++;
	}
}
