/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:42:59 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/06 16:46:20 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define TILESIZE 128
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_ESC 65307

#include <stdlib.h>

typedef struct s_struct
{
    int     fd;
    char    **map;
    char    **map_cpy;
    int     lines;
    int     columns;
    int     player_y;
    int     player_x;
    int     collectibles;
    int     movecount; 
    void    *mlx;
    void    *win;
    void    *img_player;
    void    *img_wall;
    void    *img_floor;
    void    *img_collectible;  
    void    *img_exit;
    void    *img_exit_player;
} t_struct;

//take input
void    take_input(int argc, char **argv, t_struct **game);
void    init_struct(t_struct **game);
void    check_argv(int argc, char **argv, t_struct *game);
int     count_lines(char *argv1, t_struct *game);
void    read_map(char *argv1, t_struct *game);

//map
void    check_map(t_struct *game);
void    trim_newlines(t_struct *game);
void    is_rectangle(t_struct *game);
void    is_size(t_struct *game);
void    is_walls(t_struct *game);


//map1
void    check_map(t_struct *game);
void    trim_newlines(t_struct *game);
void    is_rectangle(t_struct *game);
void    is_size(t_struct *game);
void    is_walls(t_struct *game);


//map_utils
void    is_valid_characters(t_struct *game);
void    copy_map(t_struct *game);
void    find_player(t_struct *game);
void    flood_fill(t_struct *game, int x, int y);
void    check_fill(t_struct *game);

//render
void    open_window(t_struct *game);
void    init_game(t_struct *game);
void    load_images(t_struct *game);
int     render_map(t_struct *game);
void    choose_image(int x, int y, t_struct *game);

//play
void    play_game(t_struct *game);
int     handle_mouse_close(t_struct *game);
int     keyboard_input(int keycode, t_struct *game);
void	move_player(t_struct *game, int x, int y);


//free
void    exit_printf(t_struct *game, char *message);
void    free_exit(t_struct *game);


#endif