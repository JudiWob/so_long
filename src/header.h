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
    int     lines;
    int     columns;
} t_struct;

//take input
void    take_input(int argc, char *argv1, t_struct *mlx);
void    check_input(int argc, char *argv1);
int     count_lines(t_struct *mlx);
void    read_map(char *argv1, t_struct *mlx);

//map
void    check_map(t_struct *mlx);

# endif