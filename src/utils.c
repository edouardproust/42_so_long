/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:29:27 by eproust           #+#    #+#             */
/*   Updated: 2024/12/06 23:49:18 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg, ...)
{
	va_list	ptrs;
	void	*ptr;

	ft_printf("Error\n%s\n", msg);
	va_start(ptrs, msg);
	while (1)
	{
		ptr = va_arg(ptrs, void *);
		if (!ptr)
			break;
		free(ptr);
	}
	va_end(ptrs);
	exit(EXIT_FAILURE);
}

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

