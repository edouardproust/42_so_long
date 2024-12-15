/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:36:31 by eproust           #+#    #+#             */
/*   Updated: 2024/12/15 03:33:55 by eproust          ###   ########.fr       */
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
	set_image(TX_MOVES_BG, TX_MOVES_BG_I, game);
	game->player_img_index = TX_PLAYER_FRONT_I;
}

static void	print_cell_forground_sprite(t_point *cell_pt, char cell_char,
	t_game *game)
{
	if (cell_char == 'C')
	{
		update_gpoint(cell_pt, 'z', 1);
		print_image(TX_COLLEC_I, cell_pt, game, true);
		print_image(TX_COLLEC_OK_I, cell_pt, game, false);
	}
	if (cell_char == 'E')
	{
		update_gpoint(cell_pt, 'z', 1);
		print_image(TX_EXIT_CLOSED_I, cell_pt, game, true);
		print_image(TX_EXIT_OPEN_I, cell_pt, game, false);
		print_image(TX_EXIT_HALF_I, cell_pt, game, false);
	}
	if (cell_char == 'P')
	{
		update_gpoint(cell_pt, 'z', 2);
		print_image(TX_PLAYER_FRONT_I, cell_pt, game, true);
		print_image(TX_PLAYER_RIGHT_I, cell_pt, game, false);
		print_image(TX_PLAYER_LEFT_I, cell_pt, game, false);
		print_image(TX_PLAYER_BACK_I, cell_pt, game, false);
	}
	if (cell_char == '1')
	{
		update_gpoint(cell_pt, 'z', 3);
		print_image(TX_WALL_I, cell_pt, game, true);
	}
}

static void	display_moves_initial_state(t_game *game)
{
	t_point	pt;
	size_t	label_len;

	label_len = ft_strlen(TX_MOVES_LABEL);
	set_gpoint(&pt, MOVES_BG_X, MOVES_BG_Y, MOVES_BG_Z);
	print_image(TX_MOVES_BG_I, &pt, game, true);
	mlx_resize_image(game->images[TX_MOVES_BG_I], MOVES_BG_WIDTH,
		MOVES_BG_HEIGHT);
	set_gpoint(&pt, MOVES_LABEL_X, MOVES_LABEL_Y, MOVES_BG_Z + 1);
	print_image_str(TX_MOVES_LABEL_I, TX_MOVES_LABEL, &pt, game);
	set_gpoint(&pt, label_len * 22, MOVES_LABEL_Y, MOVES_BG_Z + 2);
	print_image_str(TX_MOVES_COUNT_I, "0", &pt, game);
}

static void	display_game_initial_state(t_game *game)
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
			print_image(TX_FLOOR_I, &cell_pt, game, true);	
			print_cell_forground_sprite(&cell_pt, cell_char, game);	
			c++;
		}
		r++;
	}
	display_moves_initial_state(game);
}

void	display_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game)); // TODO alloc error
	if (!game)
		error_game(ERR_MLX_ALLOC, game);
	game->map = map;
	game->mlx = open_window(game);
	game->moves = 0;
	game->exit_status = 0;
	game->collectibles_left = map->c_count;
	set_images(game);
	display_game_initial_state(game);	
	mlx_key_hook(game->mlx, &on_key_press, (void*)game);
	mlx_loop(game->mlx);
	ft_printf("TERMINATE NOW...\n"); // TODO Debug
	free_game(game);
}
