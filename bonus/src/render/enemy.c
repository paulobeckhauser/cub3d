/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:14:36 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:48 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: render_enemy_line
Renders a vertical line representing an enemy on the screen.
game: A pointer to the game structure containing all game information and state.
enemy_i: The index of the enemy in the game's enemy array.
This function calculates the start and end points of the vertical line based on the enemy's size and position. It then calls render_enemy_pixels_vertical to draw the line on the screen. */
void	render_enemy_line(t_game *game, int enemy_i)
{
	int		y;
	int		y_end;
	float	scale;

	scale = 0.1f * (float)game->enemy[enemy_i].size;
	y = SCREEN_HEIGHT / 2 - game->enemy[enemy_i].size / 2 + (int)scale;
	if (y < 0)
		y = 0;
	if (y >= SCREEN_HEIGHT)
		y = SCREEN_HEIGHT - 1;
	y_end = SCREEN_HEIGHT / 2 + game->enemy[enemy_i].size / 2 + (int)scale;
	if (y_end < 0)
		y_end = 0;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT - 1;
	render_enemy_pixels_vertical(game, enemy_i, y, y_end);
	game->enemy[enemy_i].tex_x += (float)TEXTURE_SIZE_DEFAULT
		/ (float)game->enemy[enemy_i].size;
}

/* Function: render_enemy_pixels_vertical
Renders the pixels of the enemy's vertical line on the screen.
game: A pointer to the game structure containing all game information and state.
enemy_i: The index of the enemy in the game's enemy array.
y, y_end: The start and end points of the vertical line on the y-axis.
This function iterates from y to y_end, drawing each pixel of the enemy's line. It checks the color of each pixel to avoid drawing the background color, and marks the pixel as part of the enemy's body if the enemy is not dead. */
void	render_enemy_pixels_vertical(t_game *game, int enemy_i, int y,
			int y_end)
{
	float	tex_y;
	int		color;

	tex_y = 0;
	while (y < y_end)
	{
		color = get_pixel_color(game->enemy[enemy_i].texture,
				(int)game->enemy[enemy_i].tex_x, (int)tex_y);
		if (color != rgb_to_hex(255, 0, 255))
		{
			game->image.data[y * SCREEN_WIDTH + game->dist_idx] = color;
			if (!game->enemy[enemy_i].dead)
				game->enemy[enemy_i].hit_body[game->dist_idx] = true;
		}
		++y;
		tex_y += (float)TEXTURE_SIZE_DEFAULT / (float)game->enemy[enemy_i].size;
	}
}
