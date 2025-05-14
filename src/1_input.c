#include "header.h"

void    take_input(int argc, char *argv1, t_struct **game);
void    init_struct(t_struct **game);
void    check_arg(int argc, char *argv1, t_struct *game);
int     count_lines(char *argv1, t_struct *game);
void    read_map(char *argv1, t_struct *game);

void take_input(int argc, char *argv1, t_struct **game)
{
    init_struct(game);
    check_arg(argc, argv1, *game);
    read_map(argv1, *game);
    check_map(*game);
}

void init_struct(t_struct **game)
{
    *game = malloc(sizeof(t_struct));
    if (!*game)
        exit(EXIT_FAILURE);
    (*game)->map = NULL;
    (*game)->map_cpy = NULL;
    (*game)->fd = -1;
    (*game)->lines = 0;
    (*game)->columns = 0;
    (*game)->collectibles = 0;
    (*game)->collected = 0;
    (*game)->mlx = NULL;
    (*game)->win = NULL;
    (*game)->img_player = NULL;
    (*game)->img_wall = NULL;
    (*game)->img_floor = NULL;
    (*game)->img_exit = NULL;
    (*game)->img_collectible = NULL;
}

void    check_arg(int argc, char *argv1, t_struct *game)
{
    int len;

    if(argc != 2)
        exit_printf(game, "Error: Usage: \"./so_long\" \"mapname.ber\"\n");
    len = ft_strlen(argv1);
    if (len < 4 || ft_strcmp(argv1 + len - 4, ".ber") != 0)
        exit_printf(game, "Error: Wrong Fileformat, expected .ber for map\n");
    return;
}

int count_lines(char *argv1, t_struct *game)
{
    int count;
    char *line;

    game->fd = open(argv1, O_RDONLY);
    if (game->fd < 0)
        exit_printf(game, "Error opening map file\n");
    count = 0;
    while ((line = get_next_line(game->fd)))
    {
        free(line);
        count++;
    }
    game->lines = count;
    close(game->fd);
    game->fd = -1;
    return count;
}

void read_map(char *argv1, t_struct *game)
{
    char *line;
    int i;
    
    count_lines(argv1, game);
    game->fd = open(argv1, O_RDONLY);
    if (game->fd < 0)
        exit_printf(game, "Error opening map file\n");
    game->map = malloc(sizeof(char *) * (game->lines + 1));
    if (!game->map)
        exit(EXIT_FAILURE);
    i = 0;
    while ((line = get_next_line(game->fd)))
    {
        game->map[i++] = line;
    }
    game->map[i] = NULL;
    close(game->fd);
    game->fd = -1;
    return;
}
