/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:52:32 by eproust           #+#    #+#             */
/*   Updated: 2024/12/15 01:58:37 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_point	*player;
	t_point	*exit;
	int		c_count;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*images[20];
	size_t		images_count;
	int			moves;
	int			player_img_index;
	int			exit_status;
	int			collectibles_left;
}	t_game;
