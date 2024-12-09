/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:42:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/09 20:02:08 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STATUS_H
# define EXIT_STATUS_H

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

# define ERR_ALLOC "Memory allocation failure. Exiting program..."
# define ERR_ARGS "Usage: ./so_long <path_to_map>.ber"

# define ERR_FILE "Invalid file: "
# define ERR_FILE_PATH ERR_FILE "It doesn't exist."
# define ERR_FILE_EXT ERR_FILE "It must have a '.ber' extension."

# define ERR_MAP "Invalid map: "
# define ERR_MAP_CHARS ERR_MAP \
	"It contains others chars than '1', 'P', 'E' and 'C'."
# define ERR_MAP_C ERR_MAP "It must contain at least one 'C'."
# define ERR_MAP_E ERR_MAP "It must contain exactly one 'E'."
# define ERR_MAP_P ERR_MAP "It must contain exactly one 'P'."
# define ERR_MAP_EMPTY ERR_MAP "It is empty."
# define ERR_MAP_RECT ERR_MAP "It is not rectangular."
# define ERR_MAP_SIZE ERR_MAP "It must be at least of size 3x5, 4x4 or 5x3."
# define ERR_MAP_WALLS ERR_MAP "It must be surrounded by walls (char '1')."
# define ERR_MAP_PATH_E ERR_MAP \
	"There is no path for player (P) to reach the exit (E)."
# define ERR_MAP_PATH_C ERR_MAP \
	"Some collectibles (C) are not accessible by player (P)."

#endif
