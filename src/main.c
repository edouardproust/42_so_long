/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:08:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 04:33:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * `so_long` is a 2D game where a character collects items in a map, then
 * reaches an exit point.
 *
 * - Required files: Makefile, *.h, *.c, maps, textures. 
 * - Authorized functions: open, close, read, write, malloc, free, perror,
 *   strerror, exit, math functions (with -lm flag), miniLibX, ft_printf and
 *   libft.
 * - Arguments: a `.ber` file containing the map description.
 */
int	main(int ac, char **av)
{
	t_map	*map;
	int		r;

	if (ac != 2)
		error_exit(ERR_ARGS, NULL);
	map = map_init(av[1]);
	// TODO DEBUG START
	ft_printf("rows: %d\ncols: %d\n", map->rows, map->cols);
	ft_printf("points: P[%d, %d], E[%d, %d]\n", map->player->x, map->player->y,
		map->exit->x, map->exit->y);
	ft_printf("collectibles: %d\n", map->c_count);
	ft_printf("map:\n");
	r = 0;
	while (map->content[r])
		ft_printf("%s\n", map->content[r++]);
	// TODO DEBUG END
	display_game(map, "Pognon Knight");
	free_map(map);
	return (0);
}
