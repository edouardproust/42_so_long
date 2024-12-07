#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define BUFFER_SIZE 100

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	char	**content;
	t_point	player;
	t_point	exit;
}	t_map;

// check_map.c
char	**parse_check_map(char *filepath);

// utils.c
void	error_exit(char *msg, ...);
int		charinset(char c, char *set);
void	free_matrix(char **arr);

#endif
