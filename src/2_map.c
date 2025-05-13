#include "header.h"

void    check_map(t_struct *mlx);
void    trim_newlines(t_struct *mlx);
void    is_rectangle(t_struct *mlx);
void    is_size(t_struct *mlx);
void    is_walls(t_struct *mlx);

void  check_map(t_struct *mlx)
{
    trim_newlines(mlx);
    is_rectangle(mlx);
    is_size(mlx);
    is_walls(mlx);
    is_valid_characters(mlx);
    is_character_count(mlx);
    //is_functional(mlx);
}

void  is_rectangle(t_struct *mlx)
{
    int width;
    int temp;
    int i;

    width = -1;
    i = 0;
    while (mlx->map[i] && i < mlx->lines)
    {
        temp = ft_strlen(mlx->map[i]);
        if(width == -1)
            width = temp;
        if(temp != width)
            exit_printf(mlx, "Error: Map is not a rectangle\n");
        i++;
    }
    printf("Is rectangle\n");
    mlx->columns = width;
    printf("Rowds after rectangle %i\n", mlx->columns);
}

void trim_newlines(t_struct *mlx)
{
    int i;
    int count;
    char *nl;

    i = 0;
    count = 0;
    while (mlx->map[i])
    {
        nl = ft_strchr(mlx->map[i], '\n');
        if (nl)
            *nl = '\0';
        if (mlx->map[i][0] != '\0')
            count++;
        i++;
    }
    mlx->lines = count;
    printf("Lines after Trim %i\n", mlx->lines);
    return;
}

void  is_size(t_struct *mlx)
{
    if(mlx->lines < 5 || mlx->columns < 3)
        exit_printf(mlx, "Error: Map is too small, minimum 3*5 (x*y)");
    return;
}

void  is_walls(t_struct *mlx)
{
    int j;

    j = 0;
    while(j < mlx->columns)
    {
        if (mlx->map[0][j] != '1' || mlx->map[mlx->lines - 1][j] != '1')
            exit_printf(mlx, "Error: Map not fully enclosed by walls\n"); 
        j++;
    }
    j = 0;
    while(j < mlx->lines)
    {
        if(mlx->map[j][0] != '1' || mlx->map[j][mlx->columns - 1] != '1')
            exit_printf(mlx, "Error: Map not fully enclosed by walls\n"); 
        j++;
    }
    printf("is enclosed\n");
    return;
}









