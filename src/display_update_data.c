/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:33:20 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 02:01:06 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Updates the remaining collectibles count
void	update_collectibles(t_point *dest, t_game *game)
{
	mlx_image_t	*img;
	size_t		inst_index;

	if (game->map->content[dest->y][dest->x] != 'C')
		return ;
	game->collectibles_left--;
	img = game->images[TX_COLLEC_I];
	inst_index = get_instance_index(img, dest->y, dest->x);
	replace_image(game, TX_COLLEC_I, TX_COLLEC_OK_I, inst_index);
	if (game->collectibles_left <= game->map->c_count / 2
		&& game->exit_status == 0)
	{
		game->exit_status = 1;
		replace_image(game, TX_EXIT_CLOSED_I, TX_EXIT_HALF_I, 0);
	}
	if (game->collectibles_left == 0 && game->exit_status == 1)
	{
		game->exit_status = 2;
		replace_image(game, TX_EXIT_HALF_I, TX_EXIT_OPEN_I, 0);
	}
}

// Checks if the player has won
void	update_is_win(t_game *game)
{
	if (game->exit_status == 2 && game->player_map_char == 'E')
		game->is_win = 1;
	else if (game->player_map_char == 'X')
		game->is_win = -1;
	else
		game->is_win = 0;
}

// Update the number of moves and print it in window
void	update_print_moves(t_game *game)
{
	t_point	pt;
	char	*nb;

	game->moves++;
	mlx_delete_image(game->mlx, game->images[TX_MOVES_COUNT_I]);
	nb = ft_itoa(game->moves);
	if (!nb)
		error_game(ERR_ALLOC, game);
	set_gpoint(&pt, ft_strlen(TX_MOVES_LABEL) * 22, MOVES_LABEL_Y,
		MOVES_COUNTER_Z + 2);
	print_image_str(TX_MOVES_COUNT_I, nb, &pt, game);
	free(nb);
}
