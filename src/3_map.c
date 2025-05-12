#include "header.h"

void    is_valid_characters(t_struct *mlx);
void    is_character_count(t_struct *mlx);
void    is_functional(t_struct *mlx);

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
                exit_printf("Error: Non valid character\n");
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
        exit_printf("Error: Map must have 1 P, 1 E, and at least 1 C\n");
}

// void    is_functional(t_struct *mlx)
// {

// }

