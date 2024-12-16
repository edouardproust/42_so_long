#include "MLX42.h"

int main(void)
{
    mlx_t* mlx = mlx_init(800, 600, "Test", 1);
    if (!mlx)
		return (1);
    mlx_close_window(mlx);
    mlx_terminate(mlx);

    return (0);
}
