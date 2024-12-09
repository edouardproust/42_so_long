/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validate_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:09:33 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 22:18:21 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_mapvalid {
	char    **content;
	int		exit;
	int		c_count;
}	t_mapvalid;


static char	**map_dup_content(char **content, size_t len)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (content[i])
	{
		cpy[i] = ft_strdup(content[i]);
		if (!cpy[i])
			return (free_matrix(cpy, i), NULL);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

static void	free_mapvalid(t_mapvalid *mapvalid, char *msg, t_map *map)
{
	free_matrix(mapvalid->content, -1);	
	free(mapvalid);
	if (msg && map)
		error_exit(msg, map);
}

/**
 * Validates that there is a path from 'P' to 'E'.
 * 
 * @param c	The current t_point column
 * @param r	The current t_point row
 */
static void	map_dfs(t_mapvalid *mapvalid, int r, int c)
{
	char	ch;	

	ch = mapvalid->content[r][c];
	if (ch == '1')
		return ;
	if (ch == 'E')
		mapvalid->exit = 1;
	if (ch == 'C')
		mapvalid->c_count++;
	mapvalid->content[r][c] = '1';
	map_dfs(mapvalid, r - 1, c);
	map_dfs(mapvalid, r + 1, c);
	map_dfs(mapvalid, r, c - 1);
	map_dfs(mapvalid, r, c + 1);
}

/**
 * Validates that there is a path from 'P' to 'E'.
 * 
 * @param c	The current t_point column
 * @param r	The current t_point row
 */
void	validate_map_path(t_map *map)
{
	t_mapvalid	*mapvalid;

    mapvalid = malloc(sizeof(t_mapvalid));
    if (!mapvalid)
		error_exit(ERR_ALLOC, map);
	mapvalid->content = map_dup_content(map->content, map->rows);
	if (!mapvalid->content)
	{
        free(mapvalid);
		error_exit(ERR_ALLOC, map);
    }	
	mapvalid->exit = 0;
	mapvalid->c_count = 0;
	map_dfs(mapvalid, map->player->y, map->player->x);
	if (mapvalid->exit == 0)
		free_mapvalid(mapvalid, ERR_MAP_PATH_E, map);
	else if (mapvalid->c_count != map->c_count)
		free_mapvalid(mapvalid, ERR_MAP_PATH_C, map);
	free_mapvalid(mapvalid, NULL, NULL);
}
