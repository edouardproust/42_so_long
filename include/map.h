/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:56:19 by eproust           #+#    #+#             */
/*   Updated: 2024/12/15 23:29:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 100

// map_init.c
t_map	*map_init(char *filepath);
void	set_map_points(t_map *map);
// map_init_validate.c
void	validate_file_ext(char *filepath, char *ext);
void	validate_map_elements(t_map *map);
void	validate_map_size(t_map *map);
void	validate_map_walls(t_map *map);
// map_init_validate_path.c
void	validate_map_path(t_map *map);

// utils.c
int		charinset(char c, char *set);
void	set_point(t_point *point, size_t x, size_t y, t_map *map);

#endif
