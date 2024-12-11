/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:43:23 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 20:39:43 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_sprites(t_data *data)
{
	data->sprites['0'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_FLOOR,
		&data->cell_w, &data->cell_h);
	data->sprites['1'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_WALL,
		&data->cell_w, &data->cell_h);
	data->sprites['P'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_PLAYER,
		&data->cell_w, &data->cell_h);
	data->sprites['C'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_COLLEC,
		&data->cell_w, &data->cell_h);
	data->sprites['E'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_EXIT,
		&data->cell_w, &data->cell_h);
	if (!data->sprites['0'] || !data->sprites['1'] || !data->sprites['P']
		|| !data->sprites['C'] || !data->sprites['E'])
		return (0);
	return (1);
}

void	display_sprites(t_data *data)
{
	size_t	r;
	size_t	c;
	int		ch;

	r = -1;
	while (++r < data->map->rows)
	{
		c = -1;
		while (++c < data->map->cols)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites['0'], c * data->cell_w, r * data->cell_h);
			ch = data->map->content[r][c];
			if (ch != '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites[ch], c * data->cell_w, r * data->cell_h);
		}
	}	
}

static void	create_window(char *win_name, t_data *data)
{	
	size_t	win_width;
	size_t	win_height;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_exit(ERR_MLX, data->map); // TODO
	win_width = CELL_LEN_PX * data->map->cols;
	win_height = CELL_LEN_PX * data->map->rows;
	data->win_ptr = mlx_new_window(data->mlx_ptr, win_width, win_height,
		win_name);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		error_exit(ERR_MLX, data->map); // TODO
	}
}

void	display_game(t_map *map, char *game_name)
{
	t_data	data;

	data.map = map;
	data.moves = 0;
	data.exit_open = 0;
	// Create window + load sprites in memory (in struct);
	create_window(game_name, &data);
	if (!load_sprites(&data))
		error_exit(ERR_SPRITE, map); // TODO
	// Update map content based on input + display it
	display_sprites(&data);
	mlx_key_hook(data.win_ptr, &on_keypress, &data);
	// Repeat the previous point until window is closed or player wins
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop_hook(data.mlx_ptr, &on_loop, &data);
	mlx_loop(data.mlx_ptr);
	ft_printf("YOU WON!\n");
}
