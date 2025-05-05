#include "minilibx/mlx.h"
#include <OpenGL/glu.h> 
#include <OpenGL/gl.h> 
#include <stdio.h>

//#include <GL/gl.h>
//#include <GL/glu.h>

//cc pollok_experiment.c minilibx/libmlx.a -framework OpenGL -framework AppKit

int main()
{
    void    *mlx_connection;
    void    *mlx_window;
    mlx_connection = mlx_init();
    if (!mlx_connection)

    mlx_window = mlx_new_window(mlx_connection, 500, 500, "My first window");


    mlx_pixel_put(mlx_connection, mlx_window, 250, 250, 0x00FF0000);
    mlx_loop(mlx_connection);

}