/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:52:32 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 19:55:25 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	char	**content;
	size_t	rows;
	size_t	cols;
	t_point	player;
	t_point	exit;
	int		c_count;
	int		e_count;
	int		p_count;
}	t_map;

typedef struct s_mapvalid
{
	char	**content;
	int		exit;
	int		c_count;
}	t_mapvalid;

typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	int			is_win;
	mlx_image_t	*images[18];
	size_t		images_count;
	int			exit_status;
	int			moves;
	int			collectibles_left;
	t_point		player;
	int			player_img_index;
	char		player_map_char;
	int			enemy_img_index;
	int			timeout;
}	t_game;

#endif
