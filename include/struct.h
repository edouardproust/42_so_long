/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:52:32 by eproust           #+#    #+#             */
/*   Updated: 2024/12/12 20:56:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_game {
	char	*name;
	mlx_t	*mlx;
	t_map	*map;
	mlx_image_t	*images[10];
}	t_game;

