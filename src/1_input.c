#include "header.h"

void    take_input(int argc, char *argv1, t_struct *mlx);
void    check_input(int argc, char *argv1);
int     count_lines(char *argv1, t_struct *mlx);
void    read_map(char *argv1, t_struct *mlx);


void take_input(int argc, char *argv1, t_struct *mlx)
{
    mlx = malloc(sizeof(t_struct));
    if(!mlx)
        exit(EXIT_FAILURE);
//    printf("TEST1\n");
    check_input(argc, argv1);
//    printf("TEST2\n");
    read_map(argv1, mlx);
//    printf("TEST3\n");
    check_map(mlx);


}

void    check_input(int argc, char *argv1)
{

    int len;

    if(argc != 2)
        exit_printf("Error: Usage: \"./so_long\" \"mapname.ber\"\n");
    len = ft_strlen(argv1);
    if (len < 4 || ft_strcmp(argv1 + len - 4, ".ber") != 0)
        exit_printf("Error: Wrong Fileformat, expected .ber for map\n");
    return;
}

int count_lines(char *argv1, t_struct *mlx)
{
    int count;
    char *line;

    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
        exit_printf("Error opening map file\n");
    count = 0;
    while ((line = get_next_line(mlx->fd)))
    {
        free(line);
        count++;
    }
    mlx->lines = count;

    close(mlx->fd);
    return count;
}

void read_map(char *argv1, t_struct *mlx)
{
    int lines;
    char **map;
    char *line;
    int i;
    
    // Open the file
    // Get the number of lines in the file
    lines = count_lines(argv1, mlx);
    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
        exit_printf("Error opening map file\n");
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        exit(EXIT_FAILURE);
    i = 0;
    while ((line = get_next_line(mlx->fd)))
        map[i++] = line;

    map[i] = NULL;
    mlx->map = map;
    close(mlx->fd);
    return;
}
