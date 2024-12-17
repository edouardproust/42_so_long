/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:36:31 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 20:52:12 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->mlx = mlx;
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
	set_image(TX_ENEMY2, TX_ENEMY2_I, game);
}

static t_game	*init_game_struct(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		error_map(ERR_MLX_ALLOC, map);
	game->map = map;
	game->mlx = NULL;
	game->is_win = 0;
	game->images_count = 0;
	game->exit_status = 0;
	game->moves = 0;
	game->collectibles_left = map->c_count;
	game->player.x = map->player.x;
	game->player.y = map->player.y;
	game->player_img_index = TX_PLAYER_FRONT_I;
	game->player_map_char = 'P';
	game->enemy_img_index = TX_ENEMY_I;
	game->timeout = ANIM_TIMEOUT;
	return (game);
}

void	display_game(t_map *map)
{
	t_game	*game;

	game = init_game_struct(map);
	open_window(game);
	set_images(game);
	put_game_map(game);
	mlx_key_hook(game->mlx, &on_key_press, (void *)game);
	mlx_loop_hook(game->mlx, &on_animation, (void *)game);
	mlx_loop(game->mlx);
	free_game(game);
}
