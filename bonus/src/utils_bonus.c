/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:27 by eproust           #+#    #+#             */
/*   Updated: 2024/12/17 17:34:10 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	set_point(t_point *point, size_t x, size_t y, t_map *map)
{
	if (!point)
	{
		point = malloc(sizeof(t_point));
		if (!point)
			error_map(ERR_ALLOC, map);
	}
	point->x = x;
	point->y = y;
}

t_point	*set_gpoint(t_point *pt, int x, int y, int z)
{
	if (!pt)
		return (NULL);
	pt->x = x;
	pt->y = y;
	pt->z = z;
	return (pt);
}

t_point	*update_gpoint(t_point *pt, char xyz, int val)
{
	if (!pt)
		return (NULL);
	if (xyz == 'x')
		pt->x = val;
	else if (xyz == 'y')
		pt->y = val;
	else if (xyz == 'z')
		pt->z = val;
	return (pt);
}
