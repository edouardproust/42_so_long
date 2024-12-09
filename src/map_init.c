/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:34:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 01:55:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Verifies the file extension and opens the file.
 */
static int	open_map_file(char *filepath)
{
	int	fd;

	validate_file_ext(filepath, ".ber");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid file path.", NULL);
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
		error_alloc(NULL);
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
			error_exit("Map allocation failed.", NULL);
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
		error_alloc(NULL);
	*map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free_matrix(content);
		error_alloc(NULL);
	}
	(*map)->content = content;
	(*map)->start = NULL;
	(*map)->exit = NULL;
	(*map)->c_count = 0;
}

/**
 * Counts the essential elements in the map: 'C', 'P', 'E'.
 */
void	set_map_points(t_map *map, int *p_count, int *e_count)
{
	size_t	r;
	size_t	c;

	r = -1;
	while (map->content[++r])
	{
		c = -1;
		while (map->content[r][++c])
		{
			if (!charinset(map->content[r][c], "10CEP"))
				error_exit("Invalid map character.", map);
			if (map->content[r][c] == 'C')
				map->c_count++;
			else if (map->content[r][c] == 'P')
			{
				set_point(&map->start, c, r, map);
				(*p_count)++;
			}
			else if (map->content[r][c] == 'E')
			{
				set_point(&map->exit, c, r, map);
				(*e_count)++;
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
