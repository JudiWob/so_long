/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:11:09 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/17 15:11:10 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exit_printf(t_struct *game, char *message, int fd);
void	free_exit(t_struct *game);
void	free_map(t_struct *game);
void	destroy_images(t_struct *game);
void    correct_error_message(t_struct *game, int pe, int collectibles);


void	exit_printf(t_struct *game, char *message, int fd)
{
	ft_printf(fd,"%s\n", message);
	if (game)
		free_exit(game);
	exit(EXIT_FAILURE);
}

void	free_exit(t_struct *game)
{
	free_map(game);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	free_map(t_struct *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	i = -1;
	if (game->map_cpy)
	{
		while (game->map_cpy[++i])
			free(game->map_cpy[i]);
		free(game->map_cpy);
	}
	if (game->fd >= 0)
	{
		close(game->fd);
		game->fd = -1;
	}
}

void	destroy_images(t_struct *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_exit_player)
		mlx_destroy_image(game->mlx, game->img_exit_player);
}

void correct_error_message(t_struct *game, int pe, int collectibles)
{
	if (pe != 2 || collectibles < 1)
	
	if(pe < 2)
		exit_printf(game, "Error: Too few P or E. Map must contain 1 each",
			 2);
	if(pe > 2)
		exit_printf(game, "Error: Too many P or E. Map must contain 1 each",
			 2);
	if(collectibles < 1)
		exit_printf(game, "Error: Map must contain at least 1 C",
			 2);
}