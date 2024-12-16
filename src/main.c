/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:08:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/16 00:59:28 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define DEBUG 1 //TODO remove

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

	if (ac != 2)
		error_map(ERR_ARGS, NULL);
	map = map_init(av[1]);
	display_game(map);
	return (0);
}
