#include "header.h"
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <OpenGL/glu.h> 
//#include <OpenGL/gl.h> 
#include <stdio.h>

///cc main_pol.c minilibx-linux/libgame.a -lXext -lX11 -lm -lXrandr -lXcursor -lGL
//cc main_pol.c minilibx-linux/libgame.a -framework OpenGL -framework AppKit

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int main(int argc, char **argv)
{
    t_struct *game;

    game = malloc(sizeof(t_struct));
    if (!game)
        exit(EXIT_FAILURE);
    take_input(argc, argv[1], game);
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_printf(game, "Failed to initialize MLX");
    start_game(mlx);
    if(game)
        free_exit(game);


    
    // void    *game_connection;
    // void    *game_window;
    // game_connection = game_init();

    // game_window = game_new_window(game_connection, 500, 500, "My first window");

    // game_pixel_put(game_connection, game_window, 250, 250, 0x00FF00);

	// game_hook(game_window, 17, 0, close_window, NULL);
    // game_loop(game_connection);

}
