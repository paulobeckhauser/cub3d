/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:16:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:56:16 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: render_gun
Renders the player's gun on the screen.
game: A pointer to the game structure containing all game information and state.
This function calculates the starting position for the gun rendering based on the screen size and the gun's texture size. It then iterates over the pixels of the gun's texture, mapping them to the screen while skipping the transparent color (magenta). */
void	render_gun(t_game *game)
{
	int		x;
	int		y;
	float	tex_x;
	float	tex_y;
	int		color;

	y = SCREEN_HEIGHT - TEXTURE_SIZE_GUN;
	tex_y = 0;
	while (y < SCREEN_HEIGHT && tex_y < TEXTURE_SIZE_GUN)
	{
		x = SCREEN_WIDTH - TEXTURE_SIZE_GUN;
		tex_x = 0;
		while (x < SCREEN_WIDTH && tex_x < TEXTURE_SIZE_GUN)
		{
			color = get_pixel_color(game->textures.gun_current_texture,
					(int)tex_x, (int)tex_y);
			if (color != rgb_to_hex(255, 0, 255))
				game->image.data[y * SCREEN_WIDTH + x] = color;
			++x;
			tex_x += (float)SIZE_GUN / (float)TEXTURE_SIZE_GUN;
		}
		++y;
		tex_y += (float)SIZE_GUN / (float)TEXTURE_SIZE_GUN;
	}
}

/* Function: render_crosshair
Renders a simple crosshair in the center of the screen.
game: A pointer to the game structure containing all game information and state.
This function calculates the center of the screen and draws two lines (horizontal and vertical) to form a crosshair. The color of the crosshair is set to green. */
void	render_crosshair(t_game *game)
{
	int	x;
	int	y;

	x = SCREEN_WIDTH / 2 - 10.0;
	y = SCREEN_HEIGHT / 2 - 10.0;
	while (x < SCREEN_WIDTH / 2 + 10)
		game->image.data[SCREEN_HEIGHT / 2 * SCREEN_WIDTH
			+ x++] = rgb_to_hex(0, 255, 0);
	while (y < SCREEN_HEIGHT / 2 + 10)
		game->image.data[y++ *SCREEN_WIDTH + SCREEN_WIDTH / 2]
			= rgb_to_hex(0, 255, 0);
}
