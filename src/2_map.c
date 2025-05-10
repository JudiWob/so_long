#include "header.h"

void  check_map(t_struct *mlx);
void  is_rectangle(t_struct *mlx);
void  is_valid_design(t_struct *mlx);

void  check_map(t_struct *mlx)
{
    is_rectangle(mlx);
    is_size(mlx);
    is_valid_design(mlx);

}

void  is_rectangle(t_struct *mlx)
{
    int width;
    int temp;
    char *line;

    width = -1;
    while (line = get_next_line(mlx->fd))
    {
        temp = ft_strlen(line);
        if(line[temp] == '\n')
            temp--;
        if(width == -1)
            width = temp;
        free(line);
        if(temp != width)
        {
            printf("Error: Map is not a rectangle");
            exit(EXIT_FAILURE);
        }
    }
    mlx->columns = width;
}

void is_size(t_struct *mlx)
{
    if(mlx->lines < 5 || mlx->columns < 3)
    {
        printf("Error: Map is too small, minimum 3*5 (x*y)");
        exit(EXIT_FAILURE);
    }
    return;
}