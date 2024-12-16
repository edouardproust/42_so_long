/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:36:31 by eproust           #+#    #+#             */
/*   Updated: 2024/12/16 03:49:26 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_t	*open_window(t_game *game)
{
	int		win_width;
	int		win_height;
	mlx_t	*mlx;

	win_width = game->map->cols * CELL_LEN_PX;
	win_height = game->map->rows * CELL_LEN_PX;
	mlx = mlx_init(win_width, win_height, GAME_NAME, true);	
	if (!mlx)
		error_game(ERR_MLX_INIT, game);
	return (mlx);
}

static void	set_images(t_game *game)
{
	game->images_count = 0;
	set_image(TX_FLOOR, TX_FLOOR_I, game);
	set_image(TX_WALL, TX_WALL_I, game);
	set_image(TX_COLLEC, TX_COLLEC_I, game);
	set_image(TX_COLLEC_OK, TX_COLLEC_OK_I, game);
	set_image(TX_EXIT_CLOSED, TX_EXIT_CLOSED_I, game);
	set_image(TX_EXIT_HALF, TX_EXIT_HALF_I, game);
	set_image(TX_EXIT_OPEN, TX_EXIT_OPEN_I, game);
	set_image(TX_PLAYER_FRONT, TX_PLAYER_FRONT_I, game);
	set_image(TX_PLAYER_RIGHT, TX_PLAYER_RIGHT_I, game);
	set_image(TX_PLAYER_LEFT, TX_PLAYER_LEFT_I, game);
	set_image(TX_PLAYER_BACK, TX_PLAYER_BACK_I, game);
	set_image(TX_ENEMY, TX_ENEMY_I, game);
	set_image(TX_MOVES_BG, TX_MOVES_BG_I, game);
}

static t_game *init_game_data(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game)); // TODO alloc error
	if (!game)
		error_game(ERR_MLX_ALLOC, game);
	game->map = map;
	game->mlx = open_window(game);
	game->is_win = 0;
	game->moves = 0;
	game->exit_status = 0;
	game->collectibles_left = map->c_count;
	game->player_map_char = 'P';
	game->player.x = map->player.x;
	game->player.y = map->player.y;
	game->player_img_index = TX_PLAYER_FRONT_I;
	return (game);
}

void	display_game(t_map *map)
{
	t_game	*game;

	game = init_game_data(map);
	set_images(game);
	put_game_map(game);
	mlx_key_hook(game->mlx, &on_key_press, (void*)game);
	mlx_loop(game->mlx);
	ft_printf("FREEING GAME...\n"); // TODO Debug
	free_game(game);
	ft_printf("GAME FREED.\n"); // TODO Debug
}
