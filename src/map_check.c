/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:15:53 by eproust           #+#    #+#             */
/*   Updated: 2024/12/05 20:50:02 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		check_extension(filepath, ext)
{
	int		ext_len;
	char	*dot_ptr;
	int		i;

	dot_ptr = ft_strrch(filepath, '.');
	if (!dot_ptr)
		return (0);
	ext_len = ft_strlen(ext);
	i = 0;
	while (i <= ext_len)
	{
		if (*(dot_ptr + i) != ext[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_filepath(char *filepath)
{
	if (!filepath)
		error_exit("Incorrect filepath.");
}

/**
 * Check the map and terminate the program if the map is invalid.
 *
 * In case of map error, prints `Error\n` in stdout followed by a specific
 * message about the error.
 *
 * @brief	Map criterias: 
 *			- Map components: walls (1), open spaces (0), collectibles (C),
 *			exit (E), player start (P).
 *			- Map must be rectangular, surrounded by 1, and contain: at least
 *			one C, only one E and only one P.
 *			- P and E must be connected by a path of 0s (character moves up,
 *			down, left and right, no diagonal)
 *
 * @return	void
 */
void	check_map(char *filepath)
{
	check_filepath(filepath);
}

