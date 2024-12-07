#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define BUFFER_SIZE 100

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	char	**content;
	size_t	rows;
	size_t	cols;
	t_point	start;
	t_point	exit;
}	t_map;

// map_init.c
t_map	*map_init(char *filepath);
void	set_map_points(t_map *map, int *c_count, int *p_count,
	int *e_count);

// map_init_validate.c
void	validate_file_ext(char *filepath, char *ext);
void	validate_map_elements(t_map *map);
void	validate_map_size(t_map *map);
void	validate_map_walls(t_map *map);
void	validate_map_path(t_map *map);

// utils.c
void	error_exit(char *msg);
int		charinset(char c, char *set);
void	free_matrix(char **arr);
void	set_point(t_point *point, size_t x, size_t y);

#endif
