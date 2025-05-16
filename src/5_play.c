#include "header.h"

void    play_game(t_struct *game);
int     handle_mouse_close(t_struct *game);
int     keyboard_input(int keycode, t_struct *game);
void	move_player(t_struct *game, int x, int y);
void    refresh_map(int new_x, int new_y, t_struct *game);

void play_game(t_struct *game)
{
    mlx_hook(game->win, 17, 0, handle_mouse_close, game);
    mlx_expose_hook(game->win, render_map, game);
    mlx_hook(game->win, 2, 1L << 0, keyboard_input, game);
    mlx_loop(game->mlx);
    free_exit(game);
}


int handle_mouse_close(t_struct *game)
{
    mlx_loop_end(game->mlx); 
    return (0);
}

int keyboard_input(int keycode, t_struct *game)
{
    if (keycode == KEY_ESC)
        free_exit(game); // handle window closing
    else if (keycode == KEY_W)
        move_player(game, 0, -1); // up
    else if (keycode == KEY_S)
        move_player(game, 0, 1); // down
    else if (keycode == KEY_A)
        move_player(game, -1, 0); // left
    else if (keycode == KEY_D)
        move_player(game, 1, 0); // right
    return (0);
}

void	move_player(t_struct *game, int x, int y)
{
	int     new_x;
	int     new_y;
	char	next_position;
    
    new_x = game->player_x + x;
    new_y = game->player_y + y;
    next_position = game->map[new_y][new_x];
	if (next_position == '1')
    {
        return;
    }
	if (next_position == 'C')
    {
        game->collectibles--;
    }
	if (next_position == 'E')
    {
        if(game->collectibles == 0)
		    exit_printf(game, "💎💎💎🌺 You win! 🌺💎💎💎\n");
    }
    refresh_map(new_x, new_y, game);
}

void refresh_map(int new_x, int new_y, t_struct *game)
{
    if (game->map[game->player_y][game->player_x] == 'S')
    {
        game->map[game->player_y][game->player_x] = 'E'; // leave exit visible
    }	
	else
    {
        game->map[game->player_y][game->player_x] = '0';
    }
    if (game->map[new_y][new_x] == 'E' )
    {
        game->map[new_y][new_x] = 'S'; // normal tile
    }
    else
    {
        game->map[new_y][new_x] = 'P';
    }
	game->player_x = new_x;
	game->player_y = new_y;
	game->movecount++;
    printf("Moves: %d\n", game->movecount);
    render_map(game);
}
