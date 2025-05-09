#include "header.h"

void    take_input(int argc, char *argv1, t_struct *mlx);
void    check_input(int argc, char *argv1);
int     count_lines(int fd);
void    read_map(char *argv1, t_struct *mlx);


void take_input(int argc, char *argv1, t_struct *mlx)
{
    mlx = malloc(sizeof(t_struct));
    if(!mlx)
        exit(EXIT_FAILURE);
    
    check_input(argc, argv1);
    read_map(argv1, mlx);
    check_map(mlx);


}

void    check_input(int argc, char *argv1)
{

    int len;

    if(argc != 2)
    {
        printf("Usage: \"./so_long\" \"mapname.ber\"\n");
        exit(EXIT_FAILURE);
    }
    len = ft_strlen(argv1);
    if (len < 4 || ft_strcmp(argv1 + len - 4, ".ber") != 0)
    {
        printf("Wrong Fileformat, expected .ber for map\n");
        exit(EXIT_FAILURE);
    }
}


int count_lines(int fd)
{
    int count;
    char *line;

    count = 0;
    while ((line = get_next_line(fd)))
    {
        free(line);
        count++;
    }
    return(count);
}

void read_map(char *argv1, t_struct *mlx)
{
    int lines;
    char **map;
    char *line;
    int i;
    
    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
    {
        printf("Error opening map file");
        exit(EXIT_FAILURE);
    }
    lines = count_lines(mlx->fd);
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        exit(EXIT_FAILURE);
    i = 0;
    while ((line = get_next_line(mlx->fd)))
        map[i++] = line;
    map[i] = NULL;
    mlx->map = map;
    close(mlx->fd);
    return ;
}


