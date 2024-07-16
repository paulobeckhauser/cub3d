/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:26:48 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 15:26:39 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	render_game(t_game *game)
{
	render_background(game);
	raycaster(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image->img, 0,
		0);
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH
				+ x++] = game->data->color_ceiling;
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++] = game->data->color_floor;
		y++;
	}
}

static void	render_wall_get_pixel_color(t_game *game)
{
	while (game->y_iterator < game->y_end)
	{
		game->tex_y = ((game->y_iterator * 2 - SCREEN_HEIGHT
					+ game->line_height) * TEXTURE_SIZE) / game->line_height
			/ 2;
		if (game->tex_y < 0)
			game->tex_y = 0;
		if (game->wall_direction == NORTH)
			game->color = get_pixel_color(game->north_texture, game->tex_x,
					game->tex_y);
		else if (game->wall_direction == SOUTH)
			game->color = get_pixel_color(game->south_texture, game->tex_x,
					game->tex_y);
		else if (game->wall_direction == WEST)
			game->color = get_pixel_color(game->west_texture, game->tex_x,
					game->tex_y);
		else if (game->wall_direction == EAST)
			game->color = get_pixel_color(game->east_texture, game->tex_x,
					game->tex_y);
		if (game->color != rgb_to_hex(255, 0, 255))
			game->image->data[game->y_iterator * SCREEN_WIDTH
				+ game->dist_idx] = game->color;
		game->y_iterator++;
	}
}

void	render_wall_line(t_game *game)
{
	game->line_height = DRAWING_SCALE / (game->wall_dists[game->dist_idx] + 1);
	game->y_iterator = SCREEN_HEIGHT / 2 - game->line_height / 2;
	if (game->y_iterator < 0)
		game->y_iterator = 0;
	game->y_end = SCREEN_HEIGHT / 2 + game->line_height / 2;
	if (game->y_end > SCREEN_HEIGHT)
		game->y_end = SCREEN_HEIGHT;
	if (game->wall_direction == NORTH || game->wall_direction == SOUTH)
		game->tex_x = (int)(game->ray_hit_x * TEXTURE_SIZE);
	else
		game->tex_x = (int)(game->ray_hit_y * TEXTURE_SIZE);
	if (game->tex_x < 0)
		game->tex_x = 0;
	render_wall_get_pixel_color(game);
}
