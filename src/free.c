#include "header.h"

void exit_printf(t_struct *mlx, char *message)
{
    printf("%s", message);
    if(mlx)
        free_exit(mlx);
    exit(EXIT_FAILURE);
}


void free_exit(t_struct *mlx)
{
    int i;

    i = -1;
    if(mlx->map)
    {
        while(mlx->map[++i])
            free(mlx->map[i]);
        free(mlx->map);
    }   
    i = -1;
    if(mlx->map_cpy)
    {
        while(mlx->map_cpy[++i])
            free(mlx->map_cpy[i]);
        free(mlx->map_cpy);
    }
    if (mlx->fd >= 0)
    {
        close(mlx->fd);
        mlx->fd = -1;
    }
}