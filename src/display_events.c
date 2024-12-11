/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:37:11 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 20:37:28 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_exit_if(t_data *data)
{
	if (data->map->c_count != 0 || data->exit_open == 1)
		return ;
	data->exit_open = 1;
	data->sprites['E'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_EXIT_OPEN,
		&data->cell_w, &data->cell_h);
	if (!data->sprites['E'])
		error_exit(ERR_SPRITE, data->map); // TODO check leaks
	display_sprites(data);
}

static void exit_win_if(t_data *data)
{
	t_point *player;
	t_point *exit;
 
	player = data->map->player;
	exit = data->map->exit;
	if (data->exit_open)
	{
		if (player->x == exit->x && player->y == exit->y)
			mlx_loop_end(data->mlx_ptr);
	}
}

int	on_loop(t_data *data)
{
	open_exit_if(data);
	exit_win_if(data);
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map);
	exit(0); // TODO check leaks
	return (0);
}

int on_keypress(int key, t_data *data)
{
	int	moved;

	moved = 0; 
	if (key == XK_ESC)
		on_destroy(data);
	else if (key == XK_UP || key == XK_W)
		moved = move_player(data, 0, -1);
	else if (key == XK_DOWN || key == XK_S)
		moved = move_player(data, 0, 1);
	else if (key == XK_LEFT || key == XK_A)
		moved = move_player(data, -1, 0);
	else if (key == XK_RIGHT || key == XK_D)
		moved = move_player(data, 1, 0);
	if (moved)
	{
		display_sprites(data);
		update_moves_print(data);
	}
	return (0);
}
