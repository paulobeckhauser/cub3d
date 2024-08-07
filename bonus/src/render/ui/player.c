/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:12:16 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:54:51 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: render_hp
Renders the player's current health points (HP) on the screen. */
void	render_hp(t_game *game)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	x = SIZE_AVATAR;
	while (x < TEXTURE_WIDTH_HP + SIZE_AVATAR)
	{
		y = SCREEN_HEIGHT - TEXTURE_HEIGHT_HP;
		while (y < SCREEN_HEIGHT)
		{
			tex_x = x;
			tex_y = y - (SCREEN_HEIGHT - TEXTURE_HEIGHT_HP);
			color = get_pixel_color(game->textures.hp_current_texture, tex_x,
					tex_y);
			game->image.data[y * SCREEN_WIDTH + x] = color;
			y++;
		}
		x++;
	}
}

/* Function: render_avatar
Renders the player's avatar on the screen, typically in a corner for constant visibility. */
void	render_avatar(t_game *game)
{
	int		x;
	int		y;
	float	tex_x;
	float	tex_y;

	y = SCREEN_HEIGHT - SIZE_AVATAR;
	tex_y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		tex_x = 0;
		while (x < SIZE_AVATAR)
		{
			game->image.data[y * SCREEN_WIDTH
				+ x] = get_pixel_color(game->textures.avatar_current,
					(int)tex_x, (int)tex_y);
			++x;
			tex_x += (float)TEXTURE_SIZE_AVATAR / (float)SIZE_AVATAR;
		}
		++y;
		tex_y += (float)TEXTURE_SIZE_AVATAR / (float)SIZE_AVATAR;
	}
	render_border(game, SIZE_AVATAR, 0, SCREEN_HEIGHT - SIZE_AVATAR);
}
