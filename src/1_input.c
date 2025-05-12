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
    printf("TEST1\n");
    check_input(argc, argv1);
    printf("TEST2\n");
    read_map(argv1, mlx);
    printf("TEST3\n");
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

int count_lines(char *argv1, t_struct *mlx)
{
    int count;
    char *line;

    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
    {
        printf("Error opening map file\n");
        exit(EXIT_FAILURE);
    }
    
    count = 0;
    while ((line = get_next_line(mlx->fd)))
    {
        printf("Line read inside count function: %s\n", line);
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
    printf("Total lines: %d\n", lines);  // Debugging: print the number of lines
    mlx->fd = open(argv1, O_RDONLY);
    if (mlx->fd < 0)
    {
        printf("Error opening map file\n");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully\n");  // Debugging: file opened successfully
    printf("FD %i\n", mlx->fd);

    // Allocate memory for the map
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        exit(EXIT_FAILURE);
    // Read the lines into the map
    i = 0;
    while ((line = get_next_line(mlx->fd)))
        map[i++] = line;

    map[i] = NULL;  // Null-terminate the map
    mlx->map = map;

    // Print the map after reading
    for (int i = 0; mlx->map[i]; i++) {
        printf("Before: %s\n", mlx->map[i]);
    }

    close(mlx->fd);  // Close the file descriptor
    return;
}

// void read_map(char *argv1, t_struct *mlx)
// {
//     int lines;
//     char **map;
//     char *line;
//     int i;
    
//     mlx->fd = open(argv1, O_RDONLY);
//     if (mlx->fd < 0)
//     {
//         printf("Error opening map file");
//         exit(EXIT_FAILURE);
//     }
//     lines = count_lines(mlx);
//     map = malloc(sizeof(char *) * (lines + 1));
//     if (!map)
//         exit(EXIT_FAILURE);
//     i = 0;

//     while ((line = get_next_line(mlx->fd)))
//     {
//         printf("Line read: %s\n", line);  // Debugging: print each line read
//         map[i++] = line;
//     }
        
//     map[i] = NULL;
//     mlx->map = map;
//     for (int i = 0; mlx->map[i]; i++) {
//         printf("Before: %s\n", mlx->map[i]);
//     }
//     close(mlx->fd);
//     return ;
// }


