/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:33 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 02:06:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (ch == 'E')
		return (1);
	if (visited_map[r][c] == '1')
		return (0);
	else
		visited_map[r][c] = '1';
	if (
		validate_map_path_dfs(map, r - 1, c, visited_map)
		|| validate_map_path_dfs(map, r + 1, c, visited_map)
		|| validate_map_path_dfs(map, r, c - 1, visited_map)
		|| validate_map_path_dfs(map, r, c + 1, visited_map)
	)
		return (1);
	return (0);
}

/**
 * Validates that there is a path from 'P' to 'E'.
 * 
 * @param c	The current t_point column
 * @param r	The current t_point row
 */
void	validate_map_path(t_map *map)
{
	char	**map_cpy;
	size_t	i;
	int		result;

	map_cpy = malloc(sizeof(char *) * (map->rows + 1));
	if (!map_cpy)
		error_alloc(map);
	i = 0;
	while (i < map->rows)
	{
		map_cpy[i] = ft_strdup(map->content[i]);
		if (!map_cpy[i])
			error_alloc(map);
		i++;
	}
	map_cpy[i] = NULL;
	result = validate_map_path_dfs(map, map->start->y, map->start->x,
			map_cpy);
	free_matrix(map_cpy);
	if (!result)
		error_exit("No valid path between start (P) and exit (E).", map);
}
