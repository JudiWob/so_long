#include "header.h"

void    is_valid_characters(t_struct *game);
void    is_character_count(t_struct *game);
void    free_exit(t_struct *game);
void    copy_map(t_struct *game);
void    find_player(t_struct *game);
void    flood_fill(t_struct *game, int x, int y);

void    is_valid_characters(t_struct *game)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == '1' || game->map[i][j] == '0' || game->map[i][j] == 'C'
                || game->map[i][j] == 'P' || game->map[i][j] == 'E')
                j++; 
            else
                exit_printf(game, "Error: Non valid character\n");
        }
        i++;
    }
}

void    is_character_count(t_struct *game)
{
    int i;
    int j;
    int pe;

    i = -1;
    pe = 0;
    while(game->map[++i])
    {
        j = -1;
        while(game->map[i][++j])
        {
            if(game->map[i][j] == 'C')
                game->collectibles++;
            else if (game->map[i][j] == 'P' || game->map[i][j] == 'E')
                pe++;
        }
    }
    if (pe != 2 || game->collectibles < 1)
        exit_printf(game, "Error: Map must have 1 P, 1 E, and at least 1 C\n");
}


void copy_map(t_struct *game)
{
    int i;

    game->map_cpy = malloc(sizeof(char *) * (game->lines + 1));
    if (!game->map_cpy)
        free_exit(game);
    i = 0;
    while (i < game->lines)
    {
        game->map_cpy[i] = ft_strdup(game->map[i]);
        if (!game->map_cpy[i])
            free_exit(game); // or free all and exit
        i++;
    }
    game->map_cpy[i] = NULL;
    return ;
}

void find_player(t_struct *game)
{
    int y = 0;
    int x = 0;
    
    while (game->map_cpy[y]) 
    {
        x = 0;
        while (game->map_cpy[y][x])
        {
            if (game->map_cpy[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                // printf("x : %i\n", x);
                // printf("y : %i\n", y);
                return;
            }
            x++;
        }
        y++;
    }
}

void flood_fill(t_struct *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->columns|| y >= game->lines)
        return;
    if (game->map_cpy[y][x] == '1' || game->map_cpy[y][x] == 'V') // wall or visited
        return;

    game->map_cpy[y][x] = 'V'; // mark as visited

    flood_fill(game, x + 1, y); // right
    flood_fill(game, x - 1, y); // left
    flood_fill(game, x, y + 1); // down
    flood_fill(game, x, y - 1); // up
}

void check_fill(t_struct *game)
{
    int i;
    int j;

    i = 0;
    while(game->map_cpy[i])
    {
        j = 0;
        while(game->map_cpy[i][j])
        {
            if(game->map_cpy[i][j] == 'C')
                exit_printf(game, "Error: not all C are reachable\n");
            if(game->map_cpy[i][j] == 'E')
                exit_printf(game, "Error: E not reachable\n");
            j++;
        }
        i++;
    }
}