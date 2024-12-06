/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:51:01 by eproust           #+#    #+#             */
/*   Updated: 2024/10/06 20:06:35 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

ssize_t	ft_printf(const char *format, ...);

int	main(void)
{
	char *format = "\" c: '%c' | s: '%s' | p: '%p' | i: '%i' | d: '%d' | u: '%u' | x: '%x' | X: '%X' | '%%' \"";
	
	char			c 	= 'A';
	char			*s 	= "Hello";
	unsigned long	p	= ULONG_MAX;
	unsigned long	i	= 0;
	unsigned long	d	= INT_MIN;
	unsigned long	u	= UINT_MAX;
	unsigned long	x	= INT_MAX;
	unsigned long	X	= -ULONG_MAX;	

	printf("printf:\n");
	int out = printf(format, c, s, p, i, d, u, x, X);
	printf("\n(return: %i)\n\n", out);

	printf("ft_printf:\n");
	int out1 = ft_printf(format, c, s, p, i, d, u, x, X);
	printf("\n(return: %i)\n\n", out1);
}
