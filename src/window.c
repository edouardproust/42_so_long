/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:43:23 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 02:26:10 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
} t_data;

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0); // TODO free map
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\n", keysym); // TODO Debug
	if (keysym == XK_Escape)
		ft_printf("ESC\n");
	return (0);
}

int show_window(t_map *map)
{
	t_data	data;
	int		tile_w;
	int		tile_h;
	size_t	win_width;
	size_t	win_height;
	size_t	r;
	size_t	c;
	int		ch;

	// window init
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	win_width = TILE_WIDTH * map->cols;
	win_height = TILE_HEIGHT * map->rows;
	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	// Load textures
	data.textures['0'] = mlx_xpm_file_to_image(data.mlx_ptr, TX_FLOOR, &tile_w, &tile_h);
	data.textures['1'] = mlx_xpm_file_to_image(data.mlx_ptr, TX_WALL, &tile_w, &tile_h);
	data.textures['P'] = mlx_xpm_file_to_image(data.mlx_ptr, TX_PLAYER, &tile_w, &tile_h);
	data.textures['C'] = mlx_xpm_file_to_image(data.mlx_ptr, TX_COLLEC, &tile_w, &tile_h);
	data.textures['E'] = mlx_xpm_file_to_image(data.mlx_ptr, TX_EXIT, &tile_w, &tile_h);
	if (!data.textures['0'] || !data.textures['1'] || !data.textures['P'] || !data.textures['C'] || !data.textures['E'])
		error_exit("Incorrect image.", NULL); // TODO
	ft_printf("tile: %dx%d\n", tile_w, tile_h);
	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures['0'], c * tile_w, r * tile_h);	
			ch = map->content[r][c];
			if (ch != '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[ch], c * tile_w, r * tile_h);
			c++;
		}
		r++;
	}
	// Key + mouse events
	mlx_key_hook(data.win_ptr, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
