/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:34:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/07 21:38:34 by eproust          ###   ########.fr       */
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
		error_exit("Invalid file path.");
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
		error_exit("Map allocation failed.");
	map[0] = '\0';
	while (1)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
			break ;
		buffer[br] = '\0';
		new_map = ft_strjoin(map, buffer);
		free(map);
		map = new_map;
	}
	return (map);
}

/**
 * Splits the file content into a 2D array.
 */
static void	set_map_content(char *filepath, t_map *map)
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
		error_exit("Map parsing failed.");
	map->content = content;
}

/**
 * Counts the essential elements in the map: 'C', 'P', 'E'.
 */
void	set_map_points(t_map *map, int *c_count, int *p_count,
	int *e_count)
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
				error_exit("Invalid map character.");
			if (map->content[r][c] == 'C')
				(*c_count)++;
			else if (map->content[r][c] == 'P')
			{
				set_point(&map->start, c, r);
				(*p_count)++;
			}
			else if (map->content[r][c] == 'E')
			{
				set_point(&map->exit, c, r);
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

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	set_map_content(filepath, map);
	validate_map_size(map);
	validate_map_elements(map);
	validate_map_walls(map);
	validate_map_path(map);
	return (map);
}
