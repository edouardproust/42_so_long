/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_exit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:42:36 by eproust           #+#    #+#             */
/*   Updated: 2024/12/16 20:19:29 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_EXIT_H
# define CONFIG_EXIT_H

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

// Map parsing
# define ERR_ALLOC "Memory allocation failure. Exiting program..."
# define ERR_ARGS "Usage: ./so_long <path_to_map>.ber"
# define ERR_FILE_PATH "Invalid file: It doesn't exist."
# define ERR_FILE_EXT "Invalid file: It must have a '.ber' extension."
# define ERR_MAP_CHARS \
	"Invalid map: t contains others chars than '1', 'P', 'E' and 'C'."
# define ERR_MAP_C "Invalid map: It must contain at least one 'C'."
# define ERR_MAP_E "Invalid map: It must contain exactly one 'E'."
# define ERR_MAP_P "Invalid map: It must contain exactly one 'P'."
# define ERR_MAP_B "Invalid map: It must contain maximum one 'B'."
# define ERR_MAP_EMPTY "Invalid map: It is empty."
# define ERR_MAP_RECT "Invalid map: It is not rectangular."
# define ERR_MAP_SIZE \
	"Invalid map: It must be at least of size 3x5, 4x4 or 5x3."
# define ERR_MAP_WALLS "Invalid map: It must be surrounded by walls (char '1')."
# define ERR_MAP_PATH_E \
	"Invalid map: There is no path for player (P) to reach the exit (E)."
# define ERR_MAP_PATH_C \
	"Invalid map: Some collectibles (C) are not accessible by player (P)."

// MLX library
# define ERR_MLX_ALLOC "Failed allocating memory for the game."
# define ERR_MLX_INIT "Failed initializing MLX library."
# define ERR_MLX_TX "Failed loading texture to memory."
# define ERR_MLX_IMG "Failed converting texture into image."
# define ERR_MLX_IMG_REP "Invalid image index to replace."
# define ERR_MLX_IMG_CREATE "Failed to create MLX image."
# define ERR_MLX_STR "Failed converting string into image."
# define ERR_MLX_WIN "Failed printing image in the window."

#endif
