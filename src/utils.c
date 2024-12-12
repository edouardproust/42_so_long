/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:27 by eproust           #+#    #+#             */
/*   Updated: 2024/12/12 19:40:52 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	charinset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

void	set_point(t_point **point, size_t x, size_t y, t_map *map)
{
	if (!*point)
	{
		*point = malloc(sizeof(t_point));
		if (!*point)
			error_map(ERR_ALLOC, map);
	}
	(*point)->x = x;
	(*point)->y = y;
}
