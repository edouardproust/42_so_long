/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:08:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/07 21:12:29 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_window(void)
{
	return ;
}

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
		error_exit("Usage: ./so_long <path_to_map>.ber");
	map = map_init(av[1]);
	r = 0;
	while (map->content[r])
		ft_printf("%s\n", map->content[r++]);
	// free map //TODO
	return (0);
}
