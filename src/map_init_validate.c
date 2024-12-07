/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:33:55 by eproust           #+#    #+#             */
/*   Updated: 2024/12/07 23:31:02 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file_ext(char *filepath, char *ext)
{
	char	*msg;
	int		ext_len;
	char	*dot_ptr;
	int		i;

	msg = "File extension must be '.ber'.";
	dot_ptr = ft_strrchr(filepath, '.');
	if (!dot_ptr)
		error_exit(msg); //TODO
	else
	{
		ext_len = ft_strlen(ext);
		i = 0;
		while (i <= ext_len)
		{
			if (*(dot_ptr + i) != ext[i])
				error_exit(msg); //TODO
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
	int		c_count;
	int		p_count;
	int		e_count;

	c_count = 0;
	p_count = 0;
	e_count = 0;
	set_map_points(map, &c_count, &p_count, &e_count);
	if (c_count < 1)
		error_exit("The map must contain at least one 'C'.");
	if (e_count != 1)
		error_exit("The map must contain exactly one 'E'.");
	if (p_count != 1)
		error_exit("The map must contain exactly one 'P'.");
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
	map->cols = ft_strlen(content[0]);
	r = 0;
	while (content[r])
	{
		if (ft_strlen(content[r]) != map->cols)
			error_exit("The map must be rectangular.");
		r++;
	}
	map->rows = r;
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
				error_exit("Map must be surrounded only by walls.");
			c++;
		}
		r++;
	}
}

/**
 * Validates that there is a path from 'P' to 'E'.
 * 
 * @param c	The current t_point column
 * @param r	The current t_point row
 */
static int	validate_map_path_dfs(t_map *map, int r, int c, char **visited_map)
{
	char	ch;

	ch = map->content[r][c];
	if (r < 0 || r >= map->rows || c < 0 || c >= map->cols
		|| visited_map[r][c] == '1' || !charinset(ch, "0C"))
		return (0);
	if (ch == "E")
		return (1);
	visited_map[r][c] = '1';
	if (validate_map_path_dfs(map, r - 1, c, visited_map)
		|| validate_map_path_dfs(map, r + 1, c, visited_map)
		|| validate_map_path_dfs(map, r, c - 1, visite_map)
		|| validate_map_path_dfs(map, r, c + 1, visited_map))	
		return (1);
}

/**
 * Validates that there is a path from 'P' to 'E'.
 * 
 * @param c	The current t_point column
 * @param r	The current t_point row
 */
void	validate_map_path(t_map *map, int r, int c)
{
	char	**map_cpy;
	char	*row;
	int		i;
	int		result;

	map_cpy = malloc(sizeof(char *) * maps->content);
	//if (!map_cpy) TODO
	i = 0;
	while (maps->content[i])
	{
		map_cpy[i] = ft_strdup(maps->content[i]);
		//if (!map_cpy[i]) TODO
		i++;
	}
	map_cpy[i] = NULL;
	result = validate_map_path_dfs(map, r, c + 1, map_cpy); // move right
	free_matrix(map_cpy);
	return (result);
}
