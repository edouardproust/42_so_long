/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:34:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 17:33:17 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * Verifies the file extension and opens the file.
 */
static int	open_map_file(char *filepath)
{
	int	fd;

	validate_file_ext(filepath, ".ber");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error_map(ERR_FILE_PATH, NULL);
	return (fd);
}

/**
 * Reads the file content and concatenates it into a single string.
 */
static char	*read_file_content(int fd)
{
	ssize_t	br;
	char	buffer[BUFFER_SIZE];
	char	*map;
	char	*new_map;

	map = malloc(1);
	if (!map)
		error_map(ERR_ALLOC, NULL);
	map[0] = '\0';
	while (1)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
			break ;
		buffer[br] = '\0';
		new_map = ft_strjoin(map, buffer);
		free(map);
		if (!new_map)
			error_map(ERR_ALLOC, NULL);
		map = new_map;
	}
	return (map);
}

/**
 * Splits the file content into a 2D array.
 */
static void	set_map_content(char *filepath, t_map **map)
{
	int		fd;
	char	*file_data;
	char	**content;

	fd = open_map_file(filepath);
	file_data = read_file_content(fd);
	close(fd);
	content = ft_split(file_data, '\n');
	free(file_data);
	if (!content)
		error_map(ERR_ALLOC, NULL);
	*map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free_matrix(content, -1);
		error_map(ERR_ALLOC, NULL);
	}
	(*map)->content = content;
	(*map)->c_count = 0;
	(*map)->e_count = 0;
	(*map)->p_count = 0;
}

/**
 * Counts the essential elements in the map: 'C', 'P', 'E' and 'B'.
 */
void	set_map_points(t_map *map)
{
	size_t	r;
	size_t	c;

	r = -1;
	while (map->content[++r])
	{
		c = -1;
		while (map->content[r][++c])
		{
			if (!charinset(map->content[r][c], "10CEPX"))
				error_map(ERR_MAP_CHARS, map);
			if (map->content[r][c] == 'C')
				map->c_count++;
			else if (map->content[r][c] == 'P')
			{
				set_point(&map->player, c, r, map);
				map->p_count++;
			}
			else if (map->content[r][c] == 'E')
			{
				set_point(&map->exit, c, r, map);
				map->e_count++;
			}
		}
	}
}

/**
 * Initializes and validates the map.
 * 
 * - Reads the map file and converts it into a 2D array.
 * - Validates the map's dimensions, structure, and required elements.
 * 
 * @param filepath  Path to the map file.
 * @return          Pointer to the initialized map structure.
 */
t_map	*map_init(char *filepath)
{
	t_map	*map;

	set_map_content(filepath, &map);
	validate_map_size(map);
	validate_map_elements(map);
	validate_map_walls(map);
	validate_map_path(map);
	return (map);
}
