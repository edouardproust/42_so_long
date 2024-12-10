/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:04:52 by eproust           #+#    #+#             */
/*   Updated: 2024/12/10 03:05:48 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_square(t_img *img)
{
	int y = WIN_HEIGHT / 2 - 100;
	while (y <= WIN_HEIGHT / 2 + 100)
	{
		int x = WIN_WIDTH / 3 - 100;
		while (x <= WIN_WIDTH / 3 + 100)
		{
			my_mlx_pixel_put(img, x, y, 0xFFCD00);
			x++;
		}
		y++;
	}
}

void	put_circle(t_img *img)
{
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
        {
            int dx = x - WIN_WIDTH * 2 / 3;
            int dy = y - WIN_HEIGHT / 2;
            int distance_squared = dx * dx + dy * dy;
            if (distance_squared <= 100 * 100)
               my_mlx_pixel_put(img, x, y, 0x00BCD9);
        }
    }
}

void	show_window(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);

	put_square(&img); //TODO delete
	put_circle(&img); //TODO delete

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

