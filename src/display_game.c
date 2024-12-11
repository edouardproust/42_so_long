/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:43:23 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 04:41:01 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_sprites(t_data *data, int *cell_width, int *cell_height)
{
	data->textures['0'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_FLOOR,
		cell_width, cell_height);
	data->textures['1'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_WALL,
		cell_width, cell_height);
	data->textures['P'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_PLAYER,
		cell_width, cell_height);
	data->textures['C'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_COLLEC,
		cell_width, cell_height);
	data->textures['E'] = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_EXIT,
		cell_width, cell_height);
	if (!data->textures['0'] || !data->textures['1'] || !data->textures['P']
		|| !data->textures['C'] || !data->textures['E'])
		error_exit("Incorrect image.", NULL); // TODO
}

static void	display_sprites(t_data *data, t_map *map, int cell_w, int cell_h)
{
	size_t	r;
	size_t	c;
	int		ch;

	r = -1;
	while (++r < map->rows)
	{
		c = -1;
		while (++c < map->cols)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures['0'], c * cell_w, r * cell_h);
			ch = map->content[r][c];
			if (ch != '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures[ch], c * cell_w, r * cell_h);
		}
	}	
}

static void	create_window(char *win_name, t_map *map, t_data *data)
{	
	size_t	win_width;
	size_t	win_height;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_exit(ERR_MLX, map); // TODO
	win_width = CELL_LEN_PX * map->cols;
	win_height = CELL_LEN_PX * map->rows;
	data->win_ptr = mlx_new_window(data->mlx_ptr, win_width, win_height,
		win_name);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		error_exit(ERR_MLX, map); // TODO
	}
}

void	display_game(t_map *map, char *game_name)
{
	t_data	data;
	int		cell_width;
	int		cell_height;

	create_window(game_name, map, &data);
	load_sprites(&data, &cell_width, &cell_height);
	display_sprites(&data, map, cell_width, cell_height);
	mlx_key_hook(data.win_ptr, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
}
