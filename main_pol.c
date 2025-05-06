#include "minilibx-linux/mlx.h"
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <OpenGL/glu.h> 
//#include <OpenGL/gl.h> 
#include <stdio.h>

///cc main_pol.c minilibx-linux/libmlx.a -lXext -lX11 -lm -lXrandr -lXcursor -lGL
//cc main_pol.c minilibx-linux/libmlx.a -framework OpenGL -framework AppKit

int main()
{
    void    *mlx_connection;
    void    *mlx_window;
    mlx_connection = mlx_init();

    mlx_window = mlx_new_window(mlx_connection, 500, 500, "My first window");


    mlx_pixel_put(mlx_connection, mlx_window, 250, 250, 0x00FF00);
    mlx_loop(mlx_connection);

}
