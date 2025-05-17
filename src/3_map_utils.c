/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_map_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:47 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/17 15:12:59 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	is_valid_characters(t_struct *game);
void	copy_map(t_struct *game);
void	find_player(t_struct *game);
void	flood_fill(t_struct *game, int x, int y);
void	check_fill(t_struct *game);

void	is_valid_characters(t_struct *game)
{
	int	i;
	int	j;
	int	pe;

	i = -1;
	pe = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] == 'P' || game->map[i][j] == 'E')
				pe++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				exit_printf(game, "Error: Map contains non valid character\n");
		}
	}
	if (pe != 2 || game->collectibles < 1)
		exit_printf(game, "Error: CharaOnly one P and E and at least 1 C\n");
}

void	copy_map(t_struct *game)
{
	int	i;

	game->map_cpy = malloc(sizeof(char *) * (game->lines + 1));
	if (!game->map_cpy)
		free_exit(game);
	i = 0;
	while (i < game->lines)
	{
		game->map_cpy[i] = ft_strdup(game->map[i]);
		if (!game->map_cpy[i])
			free_exit(game);
		i++;
	}
	game->map_cpy[i] = NULL;
	return ;
}

void	find_player(t_struct *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map_cpy[y])
	{
		x = 0;
		while (game->map_cpy[y][x])
		{
			if (game->map_cpy[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_struct *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->columns || y >= game->lines)
		return ;
	if (game->map_cpy[y][x] == '1' || game->map_cpy[y][x] == 'V')
		return ;
	game->map_cpy[y][x] = 'V';
	flood_fill(game, x + 1, y); // right
	flood_fill(game, x - 1, y); // left
	flood_fill(game, x, y + 1); // down
	flood_fill(game, x, y - 1); // up
}

void	check_fill(t_struct *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_cpy[i])
	{
		j = 0;
		while (game->map_cpy[i][j])
		{
			if (game->map_cpy[i][j] == 'C')
				exit_printf(game, "Error: not all C are reachable\n");
			if (game->map_cpy[i][j] == 'E')
				exit_printf(game, "Error: E not reachable\n");
			j++;
		}
		i++;
	}
}
