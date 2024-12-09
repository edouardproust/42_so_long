/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:48:14 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 01:19:59 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->content != NULL)
			free_matrix(map->content);
		if (map->start != NULL)
			free(map->start);
		if (map->exit != NULL)
			free(map->exit);
		free(map);
	}
}

void	free_matrix(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
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

void	error_alloc(t_map *map)
{
	error_exit("Memory allocation failure. Exiting program.", map);
}
