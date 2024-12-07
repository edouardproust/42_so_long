/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:15:53 by eproust           #+#    #+#             */
/*   Updated: 2024/12/07 17:30:25 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		check_fileext(char *filepath, char *ext)
{
	int		ext_len;
	char	*dot_ptr;
	int		i;

	dot_ptr = ft_strrchr(filepath, '.');
	if (!dot_ptr)
		return (0);
	ext_len = ft_strlen(ext);
	i = 0;
	while (i <= ext_len)
	{
		if (*(dot_ptr + i) != ext[i])
			return (0);
		i++;
	}
	return (1);
}

static char	*get_map_content(char *filepath)
{
	int		fd;
	ssize_t	br;
	char	buffer[BUFFER_SIZE];
	char	*map;
	char	*new_map;

	if (!check_fileext(filepath, ".ber"))
		error_exit("Incorrect file extension.", NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error_exit("Wrong file path.", NULL);
	map = malloc(1);
	if (!map)
		error_exit("Map allocation failed.", NULL);
	while (1)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
			break;
		new_map = ft_strjoin(map, buffer);
		free(map);
		map = new_map;
	}
	return (map);
}

static void	check_map_chars(char *map) {
    int 	count_c;
	int		count_e;
	int		count_p;
	char	*start;

	count_c = 0;
	count_e = 0;
	count_p = 0;
	start = map;
    while (*map)
	{
		if (!charinset(*map, "10CEP\n"))
			error_exit("The map must contain only chars: 1, 0, C, E, P", start, NULL);
		if (*map == 'C') count_c++;
		if (*map == 'E') count_e++;
		if (*map == 'P') count_p++;
		map++;
    }
    if (count_c < 1)
        error_exit("The map must contain at least one 'C'.", start, NULL);
    if (count_e != 1)
        error_exit("The map must contain exactly one 'E'.", start, NULL);
    if (count_p != 1)
        error_exit("The map must contain exactly one 'P'.", start, NULL);
}

/**
 * Check if the map is surrounded by walls (char '1').
 *
 * @param	r Map's number of rows
 * @param	c Map's number of columns
 */
static void	check_map_walls(char **rows, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if ((i == 0 || i == r - 1 || j == 0 || j == c - 1)
				&& rows[i][j] != '1')
			{
				free_matrix(rows);
				error_exit("Map must be surrounded by walls (char '1')", NULL);
			}
			j++;
		}
		i++;
	}
}

static void	check_map_is_squared(char **rows, size_t *r, size_t *c)
{	
	*c = ft_strlen(rows[0]);
	*r = 0;
	while (rows[*r])
	{
		if (*r > 0 && ft_strlen(rows[*r]) != *c)
		{
			free_matrix(rows);
			error_exit("The map must be squared.", NULL);
		}
		(*r)++;
	}
}

// TODO
static void	check_map_path(char **rows)
{
	if (!rows)
		ft_printf("NO");
}

/**
 * Check the map and terminate the program if the map is invalid.
 *
 * In case of map error, prints `Error\n` in stdout followed by a specific
 * message about the error.
 *
 * Map criterias: 
 * - Map components: walls (1), open spaces (0), collectibles (C), exit (E),
 * player start (P).
 * - Map must be rectangular, surrounded by 1, and contain: at least one C,
 * only one E and only one P.
 * - P and E must be connected by a path of 0s (character moves up, down,
 * left and right, no diagonal).
 *
 * @note	'r' is the map's number of rows and 'c' the number of columns.
 * @return	void
 */
char	**parse_check_map(char *filepath)
{
	char	*map;
	char	**rows;
	size_t	r;
	size_t	c;

	map = get_map_content(filepath);
	check_map_chars(map);
	rows = ft_split(map, '\n');
	if (!rows)
		error_exit("Map parsing failed.", map, NULL);
	free(map);
	check_map_is_squared(rows, &r, &c);
	check_map_walls(rows, r, c);
	check_map_path(rows);
	return (rows);
}
