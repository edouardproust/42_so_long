/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:56:19 by eproust           #+#    #+#             */
/*   Updated: 2024/12/10 01:57:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 100

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	char	**content;
	size_t	rows;
	size_t	cols;
	t_point	*player;
	t_point	*exit;
	int		c_count;
}	t_map;

// map_init.c
t_map	*map_init(char *filepath);
void	set_map_points(t_map *map, int *p_count, int *e_count);
// map_init_validate.c
void	validate_file_ext(char *filepath, char *ext);
void	validate_map_elements(t_map *map);
void	validate_map_size(t_map *map);
void	validate_map_walls(t_map *map);
// map_init_validate_path.c
void	validate_map_path(t_map *map);

// utils.c
int		charinset(char c, char *set);
void	set_point(t_point **point, size_t x, size_t y, t_map *map);
// utils_exit.c
void	free_map(t_map *map);
void	free_matrix(char **arr, int	max_index);
void	error_exit(char *msg, t_map *map);
void	error_alloc(t_map *map);

#endif
