/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:46:36 by eproust           #+#    #+#             */
/*   Updated: 2024/10/06 20:03:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Print a pointer in stdout. Output format: 0x1000
 * 
 * Returns the amount of bytes written to the output, a negative int
 * otherwise.
 *
 * Uses a buffer to insure that either the whole pointer address is 
 * written or nothing (in case of a `write` fn failure).
 * Buffer size: "0x" + 16 chars (max for a ulong) + '\0' = 19 bytes
 */
ssize_t	ft_print_ptr(va_list arg_ptr)
{
	void			*ptr;
	unsigned long	nb;
	char			buffer[19];
	char			*hex;

	ptr = va_arg(arg_ptr, void *);
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	nb = (unsigned long)ptr;
	hex = ft_lutoa_base(nb, "0123456789abcdef");
	ft_strlcpy(buffer, "0x", sizeof(buffer));
	ft_strlcat(buffer, hex, sizeof(buffer));
	free(hex);
	return (ft_putstr_fd(buffer, 1));
}
