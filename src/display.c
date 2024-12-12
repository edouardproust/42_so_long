/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:36:31 by eproust           #+#    #+#             */
/*   Updated: 2024/12/12 21:01:07 by eproust          ###   ########.fr       */
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
	mlx = mlx_init(win_width, win_height, game->name, true);	
	if (!mlx)
		error_game("Error initializing MLX library.", game);
	return (mlx);
}

static void	set_image(t_game *game, int index, char *filepath)
{
	mlx_texture_t	*tx;
	mlx_image_t		*img;

	tx = mlx_load_png(filepath);
	if (!tx)
		error_game("Error loading texture to memory.", game);
	img = mlx_texture_to_image(game->mlx, tx);
	mlx_delete_texture(tx);
	if (!img)
		error_game("Error converting texture to image.", game);
	game->images[index] = img;
}

static void	set_images(t_game *game)
{
	set_image(game, 0, TX_FLOOR);
	set_image(game, 1, TX_WALL);
	set_image(game, 2, TX_COLLEC);
	set_image(game, 3, TX_EXIT_CLOSED);
	set_image(game, 4, TX_EXIT_OPEN);
	set_image(game, 5, TX_PLAYER_FRONT);
	set_image(game, 6, TX_PLAYER_BACK);
}

static void	print_image(int img_index, size_t r, size_t c, t_game *game)
{
	int	pos_x;
	int	pos_y;
	int res;

	pos_x = CELL_LEN_PX * c;
	pos_y = CELL_LEN_PX * r;
	res = mlx_image_to_window(game->mlx, game->images[img_index],
		pos_x, pos_y);
	if (res < 0)
		error_game("Failed to print image in the window.", game);
}

void	put_map_base(t_game *game)
{
	size_t	r;
	size_t	c;
	char	ch;

	r = 0;
	while (r < game->map->rows)
	{
		c = 0;
		while (c < game->map->cols)
		{
			print_image(0, r, c, game);
			ch = game->map->content[r][c];
			if (ch == '1')
				print_image(1, r, c, game);
			else if (ch == 'C')
				print_image(2, r, c, game);
			else if (ch == 'E')
				print_image(3, r, c, game);	
			else if (ch == 'P')
				print_image(5, r, c, game);	
			c++;
		}
		r++;
	}
}

void	display_game(t_map *map, char *game_name)
{
	t_game	*game;

	game = malloc(sizeof(t_game)); // TODO alloc error
	if (!game)
		error_game("Error allocating the game.", game);
	game->name = game_name;
	game->map = map;
	game->mlx = open_window(game);
	set_images(game);
	put_map_base(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
