/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:53:28 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 02:19:27 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// map_init.c
t_map			*map_init(char *filepath);
void			set_map_points(t_map *map);
// map_init_validate.c
void			validate_file_ext(char *filepath, char *ext);
void			validate_map_elements(t_map *map);
void			validate_map_size(t_map *map);
void			validate_map_walls(t_map *map);
// map_init_validate_path.c
void			validate_map_path(t_map *map);

// display_init.c
void			display_game(t_map *map);
// display_init_map.c
void			put_game_map(t_game *game);
// display_events.c
void			on_key_press(mlx_key_data_t keydata, void *param);
// display_move_player.c
void			move_player(int dir_x, int dir_y, t_game *game);
// display_update_data.c
void			update_collectibles(t_point *dest, t_game *game);
void			update_is_win(t_game *game);
void			update_print_moves(t_game *game);
// display_utils.c
void			set_image(char *filepath, int index, t_game *game);
size_t			get_instance_index(mlx_image_t *img, int r, int c);
void			replace_image(t_game *game, int old_image_index,
					int new_image_index, int instance_index);
mlx_instance_t	*print_image(int img_index, t_point *pt, t_game *game,
					bool show);
mlx_instance_t	*print_image_str(int img_index, char *str, t_point *pt,
					t_game *game);

// utils.c
int				charinset(char c, char *set);
void			set_point(t_point *point, size_t x, size_t y, t_map *map);
t_point			*set_gpoint(t_point *pt, int x, int y, int z);
t_point			*update_gpoint(t_point *pt, char xyz, int val);
// utils_exit.c
void			free_matrix(char **arr, int max_index);
void			free_map(t_map *map);
void			free_game(t_game *game);
void			error_map(char *msg, t_map *map);
void			error_game(char *msg, t_game *game);

#endif
