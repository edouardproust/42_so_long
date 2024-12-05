/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:30:53 by eproust           #+#    #+#             */
/*   Updated: 2024/12/05 20:20:43 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include <stdlib.h>

// check_map.c
void	check_map(char *filepath);
void	check_filepath(char *filepath);

// utils.c
void error_exit(char *msg);

#endif
