#include "header.h"

void exit_printf(t_struct *game, char *message)
{
    printf("%s", message);
    if(game)
        free_exit(game);
    exit(EXIT_FAILURE);
}

void free_exit(t_struct *game)
{
    int i;

    i = -1;
    if(game->map)
    {
        while(game->map[++i])
            free(game->map[i]);
        free(game->map);
    }   
    i = -1;
    if(game->map_cpy)
    {
        while(game->map_cpy[++i])
            free(game->map_cpy[i]);
        free(game->map_cpy);
    }
    if (game->fd >= 0)
    {
        close(game->fd);
        game->fd = -1;
    }
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if(game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    free(game);
}