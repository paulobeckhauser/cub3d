/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:08:22 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:57:15 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: render_wall_line
Calculates and renders a vertical slice of a wall.
game: A pointer to the game structure containing all game information and state.
This function calculates the height of the wall slice to be drawn based on the distance from the player to the wall. It then determines the texture coordinates to use for the slice and calls render_wall_pixels_vertical to draw the slice on the screen. */
void	render_wall_line(t_game *game)
{
	t_render	render;

	render.line_height = DRAWING_SCALE
		/ (game->depth[game->depth_lvl].dist + 1);
	render.y_iterator = SCREEN_HEIGHT / 2 - render.line_height / 2;
	if (render.y_iterator < 0)
		render.y_iterator = 0;
	render.y_end = SCREEN_HEIGHT / 2 + render.line_height / 2;
	if (render.y_end > SCREEN_HEIGHT)
		render.y_end = SCREEN_HEIGHT;
	if (game->wall_direction == NORTH || game->wall_direction == SOUTH)
		render.tex_x = (int)(game->depth[game->depth_lvl].ray_hit_x
				* TEXTURE_SIZE_DEFAULT);
	else
		render.tex_x = (int)(game->depth[game->depth_lvl].ray_hit_y
				* TEXTURE_SIZE_DEFAULT);
	render.color = rgb_to_hex(255, 0, 255);
	render_wall_pixels_vertical(game, &render);
}

/* Function: render_wall_pixels_vertical
Draws the calculated wall slice on the screen.
game: A pointer to the game structure containing all game information and state.
render: A structure containing rendering information such as texture coordinates and color.
This function iterates over the calculated height of the wall slice, determining the texture's y-coordinate for each pixel and drawing it on the screen if it's not the transparent color. */
void	render_wall_pixels_vertical(t_game *game, t_render *render)
{
	while (render->y_iterator < render->y_end)
	{
		render->tex_y = ((render->y_iterator * 2
					- SCREEN_HEIGHT + render->line_height)
				* TEXTURE_SIZE_DEFAULT) / render->line_height / 2;
		if (game->wall_direction == NORTH)
			render->color = get_pixel_color(game->textures.north_texture,
					render->tex_x, render->tex_y);
		else if (game->wall_direction == SOUTH)
			render->color = get_pixel_color(game->textures.south_texture,
					render->tex_x, render->tex_y);
		else if (game->wall_direction == WEST)
			render->color = get_pixel_color(game->textures.west_texture,
					render->tex_x, render->tex_y);
		else if (game->wall_direction == EAST)
			render->color = get_pixel_color(game->textures.east_texture,
					render->tex_x, render->tex_y);
		if (render->color != rgb_to_hex(255, 0, 255))
			game->image.data[render->y_iterator * SCREEN_WIDTH
				+ game->dist_idx] = render->color;
		render->y_iterator++;
	}
}

/* Function: render_door_line
Calculates and renders a vertical slice of a door.
game: A pointer to the game structure containing all game information and state.
This function calculates the height of the door slice to be drawn based on the distance from the player to the door. It then determines the texture coordinates to use for the slice and calls render_door_pixels_vertical to draw the slice on the screen. */
void	render_door_line(t_game *game)
{
	t_render	render;

	render.line_height = DRAWING_SCALE
		/ (game->depth[game->depth_lvl].dist + 1);
	render.y_iterator = SCREEN_HEIGHT / 2 - render.line_height / 2;
	if (render.y_iterator < 0)
		render.y_iterator = 0;
	render.y_end = SCREEN_HEIGHT / 2 + render.line_height / 2;
	if (render.y_end > SCREEN_HEIGHT)
		render.y_end = SCREEN_HEIGHT;
	if (game->door_direction == NORTH || game->door_direction == SOUTH)
		render.tex_x = (int)(game->depth[game->depth_lvl].ray_hit_x
				* TEXTURE_SIZE_DEFAULT);
	else
		render.tex_x = (int)(game->depth[game->depth_lvl].ray_hit_y
				* TEXTURE_SIZE_DEFAULT);
	render_door_pixels_vertical(game, &render);
}

/* Function: render_door_pixels_vertical
Draws the calculated door slice on the screen.
game: A pointer to the game structure containing all game information and state.
render: A structure containing rendering information such as texture coordinates and color.
This function iterates over the calculated height of the door slice, determining the texture's y-coordinate for each pixel and drawing it on the screen if it's not the transparent color. It checks each door in the game to see if it matches the current collision point and uses the appropriate texture if a match is found. */
void	render_door_pixels_vertical(t_game *game, t_render *render)
{
	int			i;

	while (render->y_iterator < render->y_end)
	{
		render->tex_y = ((render->y_iterator * 2
					- SCREEN_HEIGHT + render->line_height)
				* TEXTURE_SIZE_DEFAULT) / render->line_height / 2;
		i = 0;
		while (i < DOOR_MAX)
		{
			if ((int)game->depth[game->depth_lvl].colis_y == game->door[i].y
				&& (int)game->depth[game->depth_lvl].colis_x == game->door[i].x)
			{
				render->color = get_pixel_color(game->door[i].texture,
						render->tex_x, render->tex_y);
				break ;
			}
			++i;
		}
		if (render->color != rgb_to_hex(255, 0, 255))
			game->image.data[render->y_iterator * SCREEN_WIDTH
				+ game->dist_idx] = render->color;
		render->y_iterator++;
	}
}
