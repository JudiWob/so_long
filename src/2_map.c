/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:38 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/17 15:10:41 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_map(t_struct *game);
void	trim_newlines(t_struct *game);
void	is_rectangle(t_struct *game);
void	is_size(t_struct *game);
void	is_walls(t_struct *game);

void	check_map(t_struct *game)
{
	trim_newlines(game);
	is_rectangle(game);
	is_size(game);
	is_walls(game);
	is_valid_characters(game);
	copy_map(game);
	find_player(game);
	flood_fill(game, game->player_x, game->player_y);
	check_fill(game);
}

void	is_rectangle(t_struct *game)
{
	int	width;
	int	temp;
	int	i;

	width = -1;
	i = 0;
	while (game->map[i] && i < game->lines)
	{
		temp = ft_strlen(game->map[i]);
		if (width == -1)
			width = temp;
		if (temp != width)
			exit_printf(game, "Error: Map is not a rectangle\n");
		i++;
	}
	game->columns = width;
}

void	trim_newlines(t_struct *game)
{
	int		i;
	int		count;
	char	*nl;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		nl = ft_strchr(game->map[i], '\n');
		if (nl)
			*nl = '\0';
		if (game->map[i][0] != '\0')
			count++;
		i++;
	}
	game->lines = count;
	return ;
}

void	is_size(t_struct *game)
{
	if (game->lines < 5 || game->columns < 3)
		exit_printf(game, "Error: Map is too small, minimum 3*5 (x*y)");
}

void	is_walls(t_struct *game)
{
	int	j;

	j = 0;
	while (j < game->columns)
	{
		if (game->map[0][j] != '1' || game->map[game->lines - 1][j] != '1')
			exit_printf(game, "Error: Map not fully enclosed by walls\n");
		j++;
	}
	j = 0;
	while (j < game->lines)
	{
		if (game->map[j][0] != '1' || game->map[j][game->columns - 1] != '1')
			exit_printf(game, "Error: Map not fully enclosed by walls\n");
		j++;
	}
	return ;
}
