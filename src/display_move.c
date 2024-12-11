/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:20:01 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 20:39:37 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_data *data, int dir_x, int dir_y)
{
	t_map	*map;
	char	dst_ch;
	int		p_row;
	int		p_col;

	map = data->map;
	p_row = map->player->y;
	p_col = map->player->x;
	dst_ch = map->content[p_row + dir_y][p_col + dir_x];
	if (dst_ch == '1')
		return (0);
	if (dst_ch == 'C')
		map->c_count--;	
	map->content[p_row][p_col] = '0';
	map->content[p_row + dir_y][p_col + dir_x] = 'P';
	map->player->x += dir_x;
	map->player->y += dir_y;
	return (1);
}

// TODO Check the format for printing the moves in subject
void	update_moves_print(t_data *data)
{
	data->moves++;	
	ft_printf("Moves: %d\n", data->moves);
}
