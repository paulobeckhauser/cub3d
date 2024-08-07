/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:15:33 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:14 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: render_border
Draws a border around a specified area on the screen.
size: The size of the area to border.
x, y: The top-left coordinates of the area.
game: A pointer to the game structure containing all game information and state.
This function iterates over the specified area and draws a border of a predefined thickness by changing the color of the pixels at the edges. */
void	render_border(t_game *game, int size, int x, int y)
{
	int	x_iter;
	int	y_iter;

	y_iter = y;
	while (y_iter < size + y)
	{
		x_iter = x;
		while (x_iter < size + x)
		{
			if ((x_iter >= x && x_iter < BORDER_THICKNESS + x) || x_iter >= size
				+ x - BORDER_THICKNESS || (y_iter >= 0
					&& y_iter < BORDER_THICKNESS + y) || y_iter >= size + y
				- BORDER_THICKNESS)
				game->image.data[y_iter * SCREEN_WIDTH
					+ x_iter] = rgb_to_hex(32, 204, 0);
			++x_iter;
		}
		++y_iter;
	}
}
