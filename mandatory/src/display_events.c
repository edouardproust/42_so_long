/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:46:14 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 02:19:54 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_end_screen(t_game *game, int is_win)
{
	t_point	pt;
	int		win_width;
	int		win_height;
	int		x;
	int		y;

	set_image(TX_END_SCREEN_BG, TX_END_SCREEN_BG_I, game);
	set_gpoint(&pt, 0, 0, TX_END_SCREEN_Z);
	print_image(TX_END_SCREEN_BG_I, &pt, game, true);
	win_width = game->mlx->width;
	win_height = game->mlx->height;
	mlx_resize_image(game->images[TX_END_SCREEN_BG_I], win_width, win_height);
	if (is_win == 1)
		set_image(TX_WIN, TX_WIN_GAMEOVER_I, game);
	else if (is_win == -1)
		set_image(TX_GAMEOVER, TX_WIN_GAMEOVER_I, game);
	x = (win_width / 2) - (game->images[TX_WIN_GAMEOVER_I]->width / 2);
	y = (win_height / 2) - (game->images[TX_WIN_GAMEOVER_I]->height / 2);
	set_gpoint(&pt, x, y, TX_END_SCREEN_Z + 1);
	print_image(TX_WIN_GAMEOVER_I, &pt, game, true);
}

void	on_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		key;

	game = (t_game *)param;
	key = keydata.key;
	if (keydata.action != MLX_PRESS)
		return ;
	if (key == MLX_KEY_ESCAPE || (key == MLX_KEY_ENTER && game->is_win == -2))
		mlx_close_window(game->mlx);
	else if (game->is_win == 0)
	{
		if (key == MLX_KEY_RIGHT || key == MLX_KEY_D)
			move_player(1, 0, game);
		if (key == MLX_KEY_LEFT || key == MLX_KEY_A)
			move_player(-1, 0, game);
		if (key == MLX_KEY_UP || key == MLX_KEY_W)
			move_player(0, -1, game);
		if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
			move_player(0, 1, game);
	}
	if (game->is_win == 1 || game->is_win == -1)
	{
		put_end_screen(game, game->is_win);
		game->is_win = -2;
	}
}
