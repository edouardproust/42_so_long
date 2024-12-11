/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:37:11 by eproust           #+#    #+#             */
/*   Updated: 2024/12/11 04:40:06 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0); // TODO free map
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\n", keysym); // TODO Debug
	if (keysym == XK_Escape)
		ft_printf("ESC\n");
	return (0);
}
