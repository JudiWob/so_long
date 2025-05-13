#include "header.h"

void    take_input(int argc, char *argv1, t_struct **mlx);
void    init_struct(t_struct *mlx);
void    check_arg(int argc, char *argv1);
int     count_lines(char *argv1, t_struct *mlx);
void    read_map(char *argv1, t_struct *mlx);


void take_input(int argc, char *argv1, t_struct **mlx)
{
    check_arg(argc, argv1);
    *mlx = malloc(sizeof(t_struct));
    if (!*mlx)
        exit(EXIT_FAILURE);
    init_struct(*mlx);
    read_map(argv1, *mlx);
    check_map(*mlx);
}

void init_struct(t_struct *mlx)
{
    mlx->map = NULL;
    mlx->map_cpy = NULL;
    mlx->fd = -1;
    mlx->lines = 0;
    mlx->columns = 0;
}

void    check_arg(int argc, char *argv1)
{

    int len;

    if(argc != 2)
        exit_printf(NULL, "Error: Usage: \"./so_long\" \"mapname.ber\"\n");
    len = ft_strlen(argv1);
    if (len < 4 || ft_strcmp(argv1 + len - 4, ".ber") != 0)
        exit_printf(NULL, "Error: Wrong Fileformat, expected .ber for map\n");
    return;
}

int count_lines(char *argv1, t_struct *mlx)
{
    int count;
    char *line;

    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
        exit_printf(mlx, "Error opening map file\n");
    count = 0;
    while ((line = get_next_line(mlx->fd)))
    {
        free(line);
        count++;
    }
    mlx->lines = count;
    close(mlx->fd);
    mlx->fd = -1;
    return count;
}

void read_map(char *argv1, t_struct *mlx)
{
    char *line;
    int i;
    
    count_lines(argv1, mlx);
    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
        exit_printf(mlx, "Error opening map file\n");
    mlx->map = malloc(sizeof(char *) * (mlx->lines + 1));
    if (!mlx->map)
        exit(EXIT_FAILURE);
    i = 0;
    while ((line = get_next_line(mlx->fd)))
    {
        mlx->map[i++] = line;
    }
    mlx->map[i] = NULL;
    close(mlx->fd);
    mlx->fd = -1;
    return;
}
