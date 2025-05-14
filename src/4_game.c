#include "header.h"

void start_mlx(t_struct *game);
void init_game(t_struct *game);
void load_images(t_struct *game);
void render_map(t_struct *game);
int handle_close(t_struct *game);


void start_mlx(t_struct *game)
{
    init_game(game);
    load_images(game);
    render_map(game);
    mlx_hook(game->win, 17, 0, handle_close, game);
    mlx_loop(game->mlx);

}

void init_game(t_struct *game)
{
    int width; 
    int height;
    
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_printf(game, "Failed to initialize MLX");
    width = game->columns * TILESIZE;
    height = game->lines * TILESIZE;
    game->win = mlx_new_window(game->mlx, width, height, "so_long");
    if (!game->win)
        exit_printf(game, "Window creation failed");
    mlx_clear_window(game->mlx, game->win);
// mlx_init() sets up the MLX environment.
// mlx_new_window() creates the window and makes it ready for rendering.
// At this point, the MLX system is fully initialized, so you can safely load images, 
// create sprites, or prepare your game graphics.
    return;
}

void load_images(t_struct *game)
{
    int x;
    int y;


// The x and y variables you pass to mlx_xpm_file_to_image() will be filled with:
// x: the width of the loaded .xpm image, in pixels
// y: the height of the image, in pixels
    // game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &x, &y);
    // if (!game->img_wall)
    //     exit_printf(game, "Failed to load wall texture");

    game->img_floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &x, &y);
    if (!game->img_floor)
        exit_printf(game, "Failed to load floor texture");

    // game->img_player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &x, &y);
    // if (!game->img_player)
    //     exit_printf(game, "Failed to load player texture");

    // game->img_collectible = mlx_xpm_file_to_image(game->mlx, "img/collectible.xpm", &x, &y);
    // if (!game->img_collectible)
    //     exit_printf(game, "Failed to load collectible texture");

    // game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &x, &y);
    // if (!game->img_exit)
    //     exit_printf(game, "Failed to load exit texture");
}

void render_map(t_struct *game)
{
    int y = 0;
    int x;

    while (y < game->lines)
    {
        x = 0;
        while (x < game->columns)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
                                    x * TILESIZE, y * TILESIZE);
            x++;
        }
        y++;
    }
}

int handle_close(t_struct *game)
{
     free_exit(game);
    return (0);
}