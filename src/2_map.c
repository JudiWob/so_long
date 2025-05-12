#include "header.h"

void    check_map(t_struct *mlx);
void    is_rectangle(t_struct *mlx);
void    trim_newlines(t_struct *mlx);
void    is_walls(t_struct *mlx);
void    is_valid_characters(t_struct *mlx);
void    is_functional(t_struct *mlx);

void  check_map(t_struct *mlx)
{
    trim_newlines(mlx);
    //is_rectangle(mlx);
    //is_walls(mlx);

}

void  is_rectangle(t_struct *mlx)
{
    int width;
    int temp;
    int i;

    width = -1;
    i = 0;
    while (mlx->map[i])
    {
        temp = ft_strlen(mlx->map[i]);
        if(mlx->map[i][temp - 1] == '\n')
        {
            mlx->map[i][temp - 1] = '\0'; //remove new line
            temp--;
        }
        if(width == -1)
            width = temp;
        if(temp != width)
        {
            printf("Error: Map is not a rectangle");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    mlx->columns = width;
}

void trim_newlines(t_struct *mlx)
{
    int i;
    char *nl;

    i = 0;

    for (int i = 0; mlx->map[i]; i++) {
        printf("Before: %s\n", mlx->map[i]);
    }
    while (mlx->map[i])
    {
        nl = ft_strchr(mlx->map[i], '\n');
                if (nl)
            *nl = '\0';
        i++;
    }
    i = 0;
    while(mlx->map[i])
    {
        printf("%s", mlx->map[i]);
        i++;
    }
    printf("TEST4\n");
    
    // if(mlx->lines < 5 || mlx->columns < 3)
    // {
    //     printf("Error: Map is too small, minimum 3*5 (x*y)");
    //     exit(EXIT_FAILURE);
    // }
    return;
}

// void  is_walls(t_struct *mlx)
// {
//     int token;
//     int j;

//     token = 0;
//     j = 0;
//     while(mlx->map[0][j])
//     {
//         if (mlx->map[0][j] != '1')
//         {
//             printf("Map not fully enclosed by walls");
//             exit(EXIT_FAILURE);
//         }    
//         j++;
//     }
//     j = 0;
//     while(mlx->map[j][1])
//     {
//         if(mlx->map[j][0] != '1' || mlx->map[j][mlx->columns] != 1)
//         {
//             if(token == 0 && mlx->map[j][1] == '\n')
//                 token == 1;
//             if(token == 1 && mlx->map[j][1] == '1')
//             {
//                 printf("Map not fully enclosed by walls");
//                 exit(EXIT_FAILURE);
//             }    
//         }
//         j++;
//     }

//     while(mlx->map[i])
//     {

//     }
// }