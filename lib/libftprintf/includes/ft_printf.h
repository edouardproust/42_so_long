/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:48:03 by eproust           #+#    #+#             */
/*   Updated: 2024/10/05 18:16:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

ssize_t	ft_printf(const char *format, ...);

// Printers
ssize_t	ft_print_char(va_list arg_ptr);
ssize_t	ft_print_str(va_list arg_ptr);
ssize_t	ft_print_int(va_list arg_ptr);
ssize_t	ft_print_uint(va_list arg_ptr);
ssize_t	ft_print_hexa(va_list arg_ptr, char specifier);
ssize_t	ft_print_ptr(va_list arg_ptr);

#endif
