#include "header.h"

void    is_valid_characters(t_struct *mlx);
void    is_character_count(t_struct *mlx);
void    is_functional(t_struct *mlx);
void    free_exit(t_struct *mlx);
void    copy_map(t_struct *mlx);

void    is_valid_characters(t_struct *mlx)
{
    int i;
    int j;

    i = 0;
    while(mlx->map[i])
    {
        j = 0;
        while(mlx->map[i][j])
        {
            if(mlx->map[i][j] == '1' || mlx->map[i][j] == '0' || mlx->map[i][j] == 'C'
                || mlx->map[i][j] == 'P' || mlx->map[i][j] == 'E')
                j++;
            else
                exit_printf(mlx, "Error: Non valid character\n");
        }
        i++;
    }
}

void    is_character_count(t_struct *mlx)
{
    int i;
    int j;
    int c;
    int pe;

    i = -1;
    c = 0;
    pe = 0;
    while(mlx->map[++i])
    {
        j = -1;
        while(mlx->map[i][++j])
        {
            if(mlx->map[i][j] == 'C')
                c++;
            else if (mlx->map[i][j] == 'P' || mlx->map[i][j] == 'E')
                pe++;
        }
    }
    if (pe != 2 || c < 1)
        exit_printf(mlx, "Error: Map must have 1 P, 1 E, and at least 1 C\n");
}

void    is_functional(t_struct *mlx)
{
    copy_map(mlx);
}

void copy_map(t_struct *mlx)
{
    int i;

    mlx->map_cpy = malloc(sizeof(char *) * (mlx->lines + 1));
    if (!mlx->map_cpy)
        free_exit(mlx);
    i = 0;
    while (i < mlx->lines)
    {
        mlx->map_cpy[i] = ft_strdup(mlx->map[i]);
        if (!mlx->map_cpy[i])
            free_exit(mlx); // or free all and exit
        i++;
    }
    mlx->map_cpy[i] = NULL;
    return ;
}
