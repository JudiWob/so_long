#include "header.h"

void    check_map(t_struct *mlx);
void    is_rectangle(t_struct *mlx);
void    trim_newlines(t_struct *mlx);
void    is_walls(t_struct *mlx);
void    is_valid_characters(t_struct *mlx);
void    is_character_count(t_struct *mlx);
void    is_functional(t_struct *mlx);
void    is_size(t_struct *mlx);

void  check_map(t_struct *mlx)
{
    trim_newlines(mlx);
    is_rectangle(mlx);
    is_size(mlx);
    is_walls(mlx);
    is_valid_characters(mlx);
    is_character_count(mlx);

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
            exit_printf("Error: Map is not a rectangle\n");
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
        exit_printf("Error: Map is too small, minimum 3*5 (x*y)");
    return;
}

void  is_walls(t_struct *mlx)
{
    int j;

    j = 0;
    while(j < mlx->columns)
    {
        if (mlx->map[0][j] != '1' || mlx->map[mlx->lines - 1][j] != '1')
            exit_printf("Error: Map not fully enclosed by walls\n"); 
        j++;
    }
    j = 0;
    while(j < mlx->lines)
    {
        if(mlx->map[j][0] != '1' || mlx->map[j][mlx->columns - 1] != '1')
            exit_printf("Error: Map not fully enclosed by walls\n"); 
        j++;
    }
    printf("is enclosed\n");
    return;
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








