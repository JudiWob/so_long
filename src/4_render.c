/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:54 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/17 15:21:40 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	open_window(t_struct *game);
void	init_game(t_struct *game);
void	load_images(t_struct *game);
int		render_map(t_struct *game);
void	choose_image(int x, int y, t_struct *game);

void	open_window(t_struct *game)
{
	init_game(game);
	load_images(game);
	render_map(game);
}

void	init_game(t_struct *game)
{
	int	window_width;
	int	window_height;
	int	screen_width;
	int	screen_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit_printf(game, "Failed to initialize MLX", 2);
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	window_width = game->columns * TILESIZE;
	window_height = game->lines * TILESIZE;
	if (window_width > screen_width || window_height > screen_height)
		exit_printf(game, "Error: Map is too big for the screen", 2);
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			"so_long");
	if (!game->win)
		exit_printf(game, "Window creation failed", 2);
	mlx_clear_window(game->mlx, game->win);
	return ;
}
// mlx_init() sets up the MLX environment.
// mlx_new_window() creates the window and makes it ready for rendering.
// At this point, the MLX system is fully initialized,
//	so you can safely load images,
// create sprites, or prepare your game graphics.

// The x and y variables you pass to mlx_xpm_file_to_image() will be filled with
// x: the width of the loaded .xpm image, in pixels
// y: the height of the image, in pixels

void	load_images(t_struct *game)
{
	int	x;
	int	y;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &x, &y);
	if (!game->img_wall)
		exit_printf(game, "Failed to load wall image", 2);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm", &x, &y);
	if (!game->img_floor)
		exit_printf(game, "Failed to load floor image", 2);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm", &x,
			&y);
	if (!game->img_player)
		exit_printf(game, "Failed to load player image", 2);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"img/collectible.xpm", &x, &y);
	if (!game->img_collectible)
		exit_printf(game, "Failed to load collectible image", 2);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &x, &y);
	if (!game->img_exit)
		exit_printf(game, "Failed to load exit image", 2);
	game->img_exit_player = mlx_xpm_file_to_image(game->mlx,
			"img/exit_player.xpm", &x, &y);
	if (!game->img_exit_player)
		exit_printf(game, "Failed to load exit_player image", 2);
	return ;
}

int	render_map(t_struct *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->lines)
	{
		x = -1;
		while (++x < game->columns)
		{
			choose_image(x, y, game);
		}
	}
	return (0);
}

void	choose_image(int x, int y, t_struct *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILESIZE,
		y * TILESIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TILESIZE, y * TILESIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
			* TILESIZE, y * TILESIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* TILESIZE, y * TILESIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* TILESIZE, y * TILESIZE);
	else if (game->map[y][x] == 'S')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_player, x
			* TILESIZE, y * TILESIZE);
}
