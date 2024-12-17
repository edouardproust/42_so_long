/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:42:46 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 18:51:41 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_image(char *filepath, int index, t_game *game)
{
	mlx_texture_t	*tx;
	mlx_image_t		*img;

	tx = mlx_load_png(filepath);
	if (!tx)
		error_game(ERR_MLX_TX, game);
	img = mlx_texture_to_image(game->mlx, tx);
	mlx_delete_texture(tx);
	if (!img)
		error_game(ERR_MLX_IMG, game);
	game->images[index] = img;
	game->images_count++;
}

mlx_instance_t	*print_image(int img_index, t_point *pt, t_game *game,
	bool show)
{
	int				instance_index;
	mlx_image_t		*img;
	mlx_instance_t	*inst;

	img = game->images[img_index];
	instance_index = mlx_image_to_window(game->mlx, img, pt->x, pt->y);
	if (instance_index < 0)
		error_game(ERR_MLX_WIN, game);
	inst = &img->instances[instance_index];
	mlx_set_instance_depth(inst, pt->z);
	if (!show)
		inst->enabled = false;
	return (inst);
}

mlx_instance_t	*print_image_str(int img_index, char *str, t_point *pt,
	t_game *game)
{
	mlx_image_t		*img;
	mlx_instance_t	*inst;

	img = mlx_put_string(game->mlx, str, pt->x, pt->y);
	if (!img)
		error_game(ERR_MLX_STR, game);
	game->images[img_index] = img;
	game->images_count++;
	inst = &img->instances[0];
	mlx_set_instance_depth(inst, pt->z);
	return (inst);
}

void	replace_image(t_game *game, int old_image_index, int new_image_index,
	int instance_index)
{
	mlx_image_t	*old_image;
	mlx_image_t	*new_image;

	old_image = game->images[old_image_index];
	new_image = game->images[new_image_index];
	if (!old_image || !new_image)
		error_game(ERR_MLX_IMG_REP, game);
	if (instance_index < 0)
		instance_index = 0;
	old_image->instances[instance_index].enabled = false;
	new_image->instances[instance_index].enabled = true;
}

size_t	get_instance_index(mlx_image_t *img, int r, int c)
{
	int		cx;
	int		cy;
	size_t	i;

	cx = c * CELL_LEN_PX;
	cy = r * CELL_LEN_PX;
	i = 0;
	while (i < img->count)
	{
		if (img->instances[i].x == cx
			&& img->instances[i].y == cy)
			return (i);
		i++;
	}
	return (-1);
}
