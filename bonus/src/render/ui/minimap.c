/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:10:09 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:54:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: render_minimap
Renders the minimap on the screen, showing the player's surroundings in a simplified form. */
void	render_minimap(t_game *game)
{
	t_minimap	minimap;

	minimap.screen_y = 0;
	minimap.map_y = (int)game->data.player->y / SQUARE_SIZE
		- (MINIMAP_SIZE_SQUARES / 2);
	while (minimap.screen_y < MINIMAP_SIZE_SQUARES)
	{
		minimap.screen_x = 0;
		minimap.map_x = (int)game->data.player->x
			/ SQUARE_SIZE - (MINIMAP_SIZE_SQUARES / 2);
		while (minimap.screen_x < MINIMAP_SIZE_SQUARES)
		{
			minimap.tex_y = 0;
			while (minimap.tex_y < MINIMAP_SCALE)
			{
				minimap.tex_x = 0;
				render_minimap_horizontal_pixels(game, &minimap);
				++minimap.tex_y;
			}
			minimap.map_x++;
			minimap.screen_x++;
		}
		minimap.screen_y++;
		minimap.map_y++;
	}
}

/* Function: render_minimap_horizontal_pixels
Renders horizontal pixels for the minimap, coloring based on the map element type. */
void	render_minimap_horizontal_pixels(t_game *game, t_minimap *minimap)
{
	while (minimap->tex_x < MINIMAP_SCALE)
	{
		if (minimap->map_x < 0 || minimap->map_y < 0
			|| minimap->map_y >= game->data.number_lines_map_element
			|| !game->data.map_element[minimap->map_y]
			|| !game->data.map_element[minimap->map_y][minimap->map_x])
			break ;
		if (game->data.map_element[minimap->map_y][minimap->map_x] == '0')
			minimap->color = rgb_to_hex(74, 17, 17);
		else if (game->data.map_element[minimap->map_y][minimap->map_x] == '1')
			minimap->color = rgb_to_hex(30, 28, 87);
		else if (game->data.map_element[minimap->map_y][minimap->map_x] == '2'
			|| game->data.map_element[minimap->map_y][minimap->map_x] == '3')
			minimap->color = get_pixel_color(game->textures.door_minimap,
					minimap->tex_x, minimap->tex_y);
		else if (game->data.map_element[minimap->map_y][minimap->map_x] == '4')
			minimap->color = get_pixel_color(game->textures.skull,
					minimap->tex_x, minimap->tex_y);
		else
			break ;
		game->image.data[(minimap->screen_y * MINIMAP_SCALE + minimap->tex_y)
			* SCREEN_WIDTH + (minimap->screen_x * MINIMAP_SCALE
				+ minimap->tex_x)] = minimap->color;
		minimap->tex_x++;
	}
}

/* Function: render_minimap_bg
Renders the background for the minimap, typically in a single color for visibility. */
void	render_minimap_bg(t_game *game)
{
	int	tex_x;
	int	tex_y;

	tex_y = 0;
	while (tex_y < MINIMAP_SIZE)
	{
		tex_x = 0;
		while (tex_x < MINIMAP_SIZE)
		{
			game->image.data[tex_y * SCREEN_WIDTH + tex_x] = rgb_to_hex(0, 0,
					0);
			++tex_x;
		}
		++tex_y;
	}
}

/* Function: render_minimap_player
Renders the player's icon on the minimap, centered and scaled according to the minimap size. */
void	render_minimap_player(t_game *game)
{
	int		x;
	int		y;
	float	tex_x;
	float	tex_y;
	int		color;

	tex_y = 0;
	y = 0;
	while (y < MINIMAP_SCALE)
	{
		x = 0;
		tex_x = 0;
		while (x < MINIMAP_SCALE)
		{
			color = get_pixel_color(game->textures.player_texture, tex_x,
					tex_y);
			game->image.data[(MINIMAP_SIZE / 2 + y) * SCREEN_WIDTH
				+ (MINIMAP_SIZE / 2 + x)] = color;
			tex_x += (float)TEXTURE_SIZE_MINIMAP / (float)MINIMAP_SCALE;
			++x;
		}
		tex_y += (float)TEXTURE_SIZE_MINIMAP / (float)MINIMAP_SCALE;
		++y;
	}
	render_border(game, MINIMAP_SIZE, 0, 0);
}
