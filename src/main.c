/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:08:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/07 17:28:06 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void show_window()
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
	char	**map;
	int		i;

	if (ac != 2)
		error_exit("Usage: ./so_long <path_to_map>.ber", NULL);
	map = parse_check_map(av[1]);
	i = 0;
	// TODO BEGIN
	while (map[i])
		ft_printf("%s\n", map[i++]);
	free_matrix(map);
	// TODO END
	return (0);
}
