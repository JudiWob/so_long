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

#include <stdlib.h>

typedef struct s_struct
{
    int     fd;
    char    **map;
    char    **map_cpy;
    int     lines;
    int     columns;
} t_struct;

//take input
void    take_input(int argc, char *argv1, t_struct **mlx);
void    check_arg(int argc, char *argv1);
int     count_lines(char *argv1, t_struct *mlx);
void    read_map(char *argv1, t_struct *mlx);

//map
void    check_map(t_struct *mlx);
void    trim_newlines(t_struct *mlx);
void    is_rectangle(t_struct *mlx);
void    is_size(t_struct *mlx);
void    is_walls(t_struct *mlx);


//map1
void    is_valid_characters(t_struct *mlx);
void    is_character_count(t_struct *mlx);
void    is_functional(t_struct *mlx);

//utils
void exit_printf(t_struct *mlx, char *message);

void free_exit(t_struct *mlx);

void    copy_map(t_struct *mlx);


# endif