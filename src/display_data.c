/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:33:20 by eproust           #+#    #+#             */
/*   Updated: 2024/12/15 03:29:05 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Updates the remaining collectibles count
void update_collectibles(t_point *dest, t_game *game)
{
	mlx_image_t	*img;
	size_t		inst_index;

	if (game->map->content[dest->y][dest->x] != 'C')
        return ;
	game->collectibles_left--;
	img = game->images[TX_COLLEC_I];
	inst_index = get_instance_index(img, dest->y, dest->x);
	replace_image(game, TX_COLLEC_I, TX_COLLEC_OK_I, inst_index);
	if (game->collectibles_left <= game->map->c_count / 2 && game->exit_status == 0)
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
int	check_victory(t_point *dest, t_game *game)
{
	t_point *exit;

	exit = game->map->exit;
	if (game->exit_status == 2 && exit->y == dest->y && exit->x == dest->x)
	{
		ft_printf("YOU WON!\n");
		mlx_close_window(game->mlx);
		return (1);
	}
	return (0);
}

void	update_print_moves(t_game *game)
{
	t_point	pt;
	char	*nb;

	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	mlx_delete_image(game->mlx, game->images[TX_MOVES_COUNT_I]);
	nb = ft_itoa(game->moves);
	if (!nb)
		error_game(ERR_ALLOC, game);
	set_gpoint(&pt, ft_strlen(TX_MOVES_LABEL) * 22, MOVES_LABEL_Y,
		MOVES_BG_Z + 2);
	print_image_str(TX_MOVES_COUNT_I, nb, &pt, game);
}