/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_play.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:11:04 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/17 15:15:44 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	play_game(t_struct *game);
int		handle_mouse_close(t_struct *game);
int		keyboard_input(int keycode, t_struct *game);
void	move_player(t_struct *game, int x, int y);
void	refresh_map(int new_x, int new_y, t_struct *game);

void	play_game(t_struct *game)
{
	mlx_hook(game->win, 17, 0, handle_mouse_close, game);
	mlx_expose_hook(game->win, render_map, game);
	mlx_hook(game->win, 2, 1L << 0, keyboard_input, game);
	mlx_loop(game->mlx);
	free_exit(game);
}

int	handle_mouse_close(t_struct *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	keyboard_input(int keycode, t_struct *game)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_struct *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	next_position;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	next_position = game->map[new_y][new_x];
	if (next_position == '1')
	{
		return ;
	}
	if (next_position == 'C')
	{
		game->collectibles--;
	}
	refresh_map(new_x, new_y, game);
}

void	refresh_map(int new_x, int new_y, t_struct *game)
{
	if (game->map[game->player_y][game->player_x] == 'S')
		game->map[game->player_y][game->player_x] = 'E';
	else
	{
		game->map[game->player_y][game->player_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E')
		game->map[new_y][new_x] = 'S';
	else
	{
		game->map[new_y][new_x] = 'P';
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->movecount++;
	ft_printf(1, "Moves: %d\n", game->movecount);
	render_map(game);
	if (game->map[new_y][new_x] == 'S' || game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
			exit_printf(game, "💎💎💎🌺 You win! 🌺💎💎💎", 1);
	}
}
