/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:10:10 by jpaselt           #+#    #+#             */
/*   Updated: 2025/05/17 15:10:17 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <OpenGL/glu.h>
//#include <OpenGL/gl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_struct	*game;

	take_input(argc, argv, &game);
	open_window(game);
	play_game(game);
}
