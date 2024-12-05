/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:08:45 by eproust           #+#    #+#             */
/*   Updated: 2024/12/05 20:20:17 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void show_window()
{
	return ;
}

/**
 * `so_long` is a 2D game where a character collects items in a map, then reaches an
 * exit point.
 *
 * @note	- Required files: Makefile, *.h, *.c, maps, textures. 
 *			- Authorized functions: open, close, read, write, malloc, free, 
 *       	perror, strerror, exit, math functions (with -lm flag), miniLibX, 
 *       	ft_printf and libft.
 *			- Arguments: a `.ber` file containing the map description.
 */

#include "math.h"

int	main(int ac, char **av)
{
	if (ac !== 2)
		error_exit("Usage: ./so_long <path_to_map>.ber");
	check_map(av[1]);
	ft_printf("MAP OK!\n"); //TODO
	return (0);
}