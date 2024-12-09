/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:48:14 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 18:45:59 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->content != NULL)
			free_matrix(map->content, -1);
		if (map->player != NULL)
			free(map->player);
		if (map->exit != NULL)
			free(map->exit);
		free(map);
	}
}

/**
 * Frees a dynamically allocated 2D array of strings.
 *
 * If max_index is -1, it frees up to the first NULL entry. If max_index
 * is non-negative, it frees all rows up to, but not including, max_index.
 */
void	free_matrix(char **arr, int	max_index)
{
	int	i;

	i = 0;
	while ((max_index == -1 || i < max_index) && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	error_exit(char *msg, t_map *map)
{
	ft_printf("Error\n%s\n", msg);
	free_map(map);
	exit(EXIT_FAILURE);
}
