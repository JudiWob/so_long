#include "header.h"
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <OpenGL/glu.h> 
//#include <OpenGL/gl.h> 
#include <stdio.h>

///cc main_pol.c minilibx-linux/libgame.a -lXext -lX11 -lm -lXrandr -lXcursor -lGL
//cc main_pol.c minilibx-linux/libgame.a -framework OpenGL -framework AppKit

int main(int argc, char **argv)
{
    t_struct *game;

    take_input(argc, argv, &game);
    open_window(game);
    play_game(game);
    free_exit(game);
}


