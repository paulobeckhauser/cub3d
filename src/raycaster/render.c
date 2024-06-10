/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:26:48 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 15:26:49 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	render_map(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++] = rgb_to_hex(173, 216, 230);
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++]
					= rgb_to_hex((int)(60 + (y - SCREEN_HEIGHT / 2) * 0.05),
								 (int)(30 + (y - SCREEN_HEIGHT / 2) * 0.05),
								 (int)(15 + (y - SCREEN_HEIGHT / 2) * 0.05));
		y++;
	}
	raycaster(game);
	render_crosshair(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image->img, 0, 0);
}

void    render_minimap(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			if (game->map[x])
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_texture, x, y);
		}
	}
}

void	render_crosshair(t_game *game)
{
	int	x;
	int	y;

	(void)game;
	x = SCREEN_WIDTH / 2 - 10.0;
	y = SCREEN_HEIGHT / 2 - 10.0;
	while (x < SCREEN_WIDTH / 2 + 10)
		game->image->data[SCREEN_HEIGHT / 2 * SCREEN_WIDTH + x++] = rgb_to_hex(0, 255, 0);
	while (y < SCREEN_HEIGHT / 2 + 10)
		game->image->data[y++ * SCREEN_WIDTH + SCREEN_WIDTH / 2] = rgb_to_hex(0, 255, 0);
}

int get_pixel_color(void *img_ptr, int x, int y)
{
	char    *data;
	int     bits_per_pixel;
	int     size_line;
	int     endian;
	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (*(int *)(data + ((x + y * size_line / 4) * bits_per_pixel / 8)));
}

void    render_wall_line(t_game *game)
{
	int line_height;
	int y_iterator;
	int y_end;
	int tex_x, tex_y;
	int color;
	
	line_height = DRAWING_SCALE / (game->dists[game->dist_idx] + 1);
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	// Calculate tex_x based on where the ray hit the wall block
	if (game->direction == NORTH || game->direction == SOUTH)
		tex_x = (int)(game->ray_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->ray_hit_y * TEXTURE_SIZE);
	while (y_iterator < y_end)
	{
		// Calculate tex_y based on the current y_iterator value
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
		if (game->direction == NORTH)
			color = get_pixel_color(game->north_texture, tex_x, tex_y);
		else if (game->direction == SOUTH)
			color = get_pixel_color(game->south_texture, tex_x, tex_y);
		else if (game->direction == WEST)
			color = get_pixel_color(game->west_texture, tex_x, tex_y);
		else if (game->direction == EAST)
			color = get_pixel_color(game->east_texture, tex_x, tex_y);
		game->image->data[y_iterator++ * SCREEN_WIDTH + game->dist_idx] = color;
	}
}

//void    render_wall_line(t_game *game)
//{
//	int line_height;
//	int y_iterator;
//	int y_end;
//
//	line_height = (int)(DRAWING_SCALE / (game->dists[game->dist_idx] + 1));
//	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
//	if (y_iterator < 0)
//		y_iterator = 0;
//	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
//	if (y_end > SCREEN_HEIGHT)
//		y_end = SCREEN_HEIGHT;
//	while (y_iterator < y_end)
//	{
//		if (game->direction == NORTH)
//			game->image->data[y_iterator++ * SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(165, 42, 42);
//		else if (game->direction == SOUTH)
//			game->image->data[y_iterator++ * SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(255, 255, 0);
//		else if (game->direction == WEST)
//			game->image->data[y_iterator++ * SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(255, 0, 0);
//		else if (game->direction == EAST)
//			game->image->data[y_iterator++ * SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(0, 0, 255);
//	}
//}
