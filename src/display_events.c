/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:46:14 by eproust           #+#    #+#             */
/*   Updated: 2024/12/14 21:54:48 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void on_key_press(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		move_player(1, 0, game);
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		move_player(-1, 0, game);
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		move_player(0, -1, game);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		move_player(0, 1, game);
}

