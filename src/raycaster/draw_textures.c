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

void	draw_map(t_game *game, t_image *image)
{
	int x;
	int y;
	
	if (image->created)
	{
		mlx_destroy_image(game->mlx_ptr, image->img);
		image->img = NULL;
	}
	image->created = 1;
	image->img = mlx_new_image(game->mlx_ptr, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT);
	image->data = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	x = 0;
	y = 0;
	while (y < (int)SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < (int)SCREEN_WIDTH)
			image->data[y * (int)SCREEN_WIDTH + x++] = rgb_to_hex(173, 216, 230);
		y++;
	}
	while (y < (int)SCREEN_HEIGHT)
	{
		x = 0;
		while (x < (int)SCREEN_WIDTH)
			image->data[y * (int)SCREEN_WIDTH + x++] = rgb_to_hex(0, 255, 0);
		y++;
	}
	raycaster(game, image);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image->img, 0, 0);
}


void    draw_wall_line(t_game *game, t_image *image)
{
	int line_height;
	int y_iterator;
	int y_end;

	line_height = (int)(DRAWING_SCALE / (game->dists[game->dist_idx] + 1));
	y_iterator = (int)SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = (int)SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > (int)SCREEN_HEIGHT)
		y_end = (int)SCREEN_HEIGHT;
	while (y_iterator < y_end)
	{
		if (game->direction == NORTH)
			image->data[y_iterator++ * (int)SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(165, 42, 42);
		else if (game->direction == SOUTH)
			image->data[y_iterator++ * (int)SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(255, 255, 0);
		else if (game->direction == WEST)
			image->data[y_iterator++ * (int)SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(255, 0, 0);
		else if (game->direction == EAST)
			image->data[y_iterator++ * (int)SCREEN_WIDTH + game->dist_idx] = rgb_to_hex(0, 0, 255);
	}
}

//void    draw_wall_line(t_game *game)
//{
//	int line_height;
//	int y_iterator;
//	int y_end;
//
//	line_height = (int)(DRAWING_SCALE / (game->dists[game->dist_idx] + 1));
//	y_iterator = (int)SCREEN_HEIGHT / 2 - line_height / 2;
//	if (y_iterator < 0)
//		y_iterator = 0;
//	y_end = (int)SCREEN_HEIGHT / 2 + line_height / 2;
//	if (y_end > SCREEN_HEIGHT)
//		y_end = SCREEN_HEIGHT;
//	while (y_iterator <= y_end)
//	{
//		if (game->direction == NORTH)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(165, 42, 42));
//		else if (game->direction == SOUTH)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(255, 255, 0));
//		else if (game->direction == WEST)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(255, 0, 0));
//		else if (game->direction == EAST)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(0, 0, 255));
//	}
//}