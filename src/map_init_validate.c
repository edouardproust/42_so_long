/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:33:55 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 20:00:05 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file_ext(char *filepath, char *ext)
{
	int		ext_len;
	char	*dot_ptr;
	int		i;

	dot_ptr = ft_strrchr(filepath, '.');
	if (!dot_ptr)
		error_exit(ERR_FILE_EXT, NULL);
	else
	{
		ext_len = ft_strlen(ext);
		i = 0;
		while (i <= ext_len)
		{
			if (*(dot_ptr + i) != ext[i])
				error_exit(ERR_FILE_EXT, NULL);
			i++;
		}
	}
}

/**
 * Validates the essential elements in the map.
 * Ensures the map contains:
 * - At least one 'C' (collectible).
 * - Exactly one 'P' (player start).
 * - Exactly one 'E' (exit).
 */
void	validate_map_elements(t_map *map)
{
	int		p_count;
	int		e_count;

	p_count = 0;
	e_count = 0;
	set_map_points(map, &p_count, &e_count);
	if (map->c_count < 1)
		error_exit(ERR_MAP_C, map);
	if (e_count != 1)
		error_exit(ERR_MAP_E, map);
	if (p_count != 1)
		error_exit(ERR_MAP_P, map);
}

/**
 * Validates the dimensions of the map.
 * Ensures the map is rectangular.
 */
void	validate_map_size(t_map *map)
{
	char	**content;
	size_t	r;

	content = map->content;
	if (!content[0])
		error_exit(ERR_MAP_EMPTY, map);
	map->cols = ft_strlen(content[0]);
	r = 0;
	while (content[r])
	{
		if (ft_strlen(content[r]) != map->cols)
			error_exit(ERR_MAP_RECT, map);
		r++;
	}
	map->rows = r;
	if (map->rows + map->cols < 8 || map->rows < 3 || map->cols < 3)
		error_exit(ERR_MAP_SIZE, map);
}

/**
 * Validates that the map is surrounded by walls ('1').
 */
void	validate_map_walls(t_map *map)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (map->content[r])
	{
		c = 0;
		while (map->content[r][c])
		{
			if ((r == 0 || r == map->rows - 1 || c == 0 || c == map->cols - 1)
				&& map->content[r][c] != '1')
				error_exit(ERR_MAP_WALLS, map);
			c++;
		}
		r++;
	}
}
