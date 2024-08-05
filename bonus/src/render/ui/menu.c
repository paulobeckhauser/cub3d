/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:16:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:16:20 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

void	render_main_menu(t_game *game)
{
	int		x;
	float	tex_x;

	x = 0;
	tex_x = 0;
	while (x < SCREEN_WIDTH && tex_x < TEXTURE_MENU_WIDTH)
	{
		render_main_menu_pixels_vertical(game, tex_x, x);
		tex_x += (float)TEXTURE_MENU_WIDTH / (float)SCREEN_WIDTH;
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.img, 0,
		0);
}

void	render_main_menu_pixels_vertical(t_game *game, float tex_x, int x)
{
	int		y;
	float	tex_y;

	y = 0;
	tex_y = 0;
	while (y < SCREEN_HEIGHT && tex_y < TEXTURE_MENU_HEIGHT)
	{
		if (game->player_dead)
			game->image.data[y * SCREEN_WIDTH + x]
				= get_pixel_color(game->textures.game_over_texture,
					(int) tex_x, (int) tex_y);
		else if (game->won_game)
			game->image.data[y * SCREEN_WIDTH + x]
				= get_pixel_color(game->textures.win_screen,
					(int) tex_x, (int) tex_y);
		else
			game->image.data[y * SCREEN_WIDTH + x]
				= get_pixel_color(game->textures.main_menu_current,
					(int) tex_x, (int) tex_y);
		tex_y += (float) TEXTURE_MENU_HEIGHT / (float) SCREEN_HEIGHT;
		y++;
	}
}
