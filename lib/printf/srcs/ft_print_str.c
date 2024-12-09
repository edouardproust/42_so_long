/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:49:43 by eproust           #+#    #+#             */
/*   Updated: 2024/10/06 18:43:13 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Print a string in stdout.
 *
 * Returns the amount of bytes written to the output, a negative int
 * otherwise.
 */
ssize_t	ft_print_str(va_list arg_ptr)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}
