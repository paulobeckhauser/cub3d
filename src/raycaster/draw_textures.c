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
#include "../../incl/raycaster.h"

void	draw_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->background, 0, 0);
	cast_rays(game);
}


void    draw_wall_line(t_game *game)
{
	int line_height;
	int y_iterator;
	int y_end;

	line_height = (int)(DRAWING_SCALE / (game->dists[game->dist_idx] + 1));
//	printf("ray length: %f\n", game->dists[game->dist_idx] + 1);
//	printf("idx: %i\n", game->dist_idx);
	y_iterator = (int)SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = (int)SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	while (y_iterator <= y_end)
	{
		if (game->direction == NORTH)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(165, 42, 42));
		else if (game->direction == SOUTH)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(255, 255, 0));
		else if (game->direction == WEST)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(255, 0, 0));
		else if (game->direction == EAST)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, (int)y_iterator++, rgb_to_hex(0, 0, 255));
	}
}

//void    draw_wall_line(t_game *game)
//{
//	int line_height = (int)round(DRAWING_SCALE / game->dists[game->dist_idx]);
//	int draw_start = -line_height / 2 + (int)SCREEN_HEIGHT / 2;
//	int draw_end = line_height / 2 + (int)SCREEN_HEIGHT / 2;
//
//	if (draw_start < 0) draw_start = 0;
//	if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;
//
//	for (int y = draw_start; y < draw_end; y++)
//	{
//		if (game->direction == NORTH)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, y++, rgb_to_hex(165, 42, 42));
//		else if (game->direction == SOUTH)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, y++, rgb_to_hex(255, 255, 0));
//		else if (game->direction == WEST)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, y++, rgb_to_hex(255, 0, 0));
//		else if (game->direction == EAST)
//			mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->dist_idx, y++, rgb_to_hex(0, 0, 255));
//	}
//}

void    draw_ray(t_game *game)
{
	double	dir_x;
	double	dir_y;
	double	len;
	double	x_iterator;
	double	y_iterator;
	double	speed;
	int		colis_x;
	int		colis_y;

	dir_x = game->ray_new_x - game->player_x;
	dir_y = game->ray_new_y - game->player_y;
	len = sqrt(dir_x * dir_x + dir_y * dir_y);
	dir_x /= len;
	dir_y /= len;
	x_iterator = game->player_x;
	y_iterator = game->player_y;
	speed = 1;
	while (((dir_x >= 0 && x_iterator <= game->ray_new_x) || (dir_x < 0 && x_iterator >= game->ray_new_x))
			&& ((dir_y >= 0 && y_iterator <= game->ray_new_y) || (dir_y < 0 && y_iterator >= game->ray_new_y)))
	{
		if ((int)x_iterator % (int)game->square_width == 0 || (int)y_iterator % (int)game->square_height == 0)
		{
			if (dir_x > 0)
				colis_x = (int)x_iterator / (int)game->square_width;
			else
				colis_x = (int)(x_iterator - 1) / (int)game->square_width;
			if (dir_y > 0)
				colis_y = (int)y_iterator / (int)game->square_height;
			else
				colis_y = (int)(y_iterator - 1) / (int)game->square_height;
			if (game->map[colis_y][colis_x] == '1')
			{
				if ((int)x_iterator % (int)game->square_width == 0)
				{
					if (dir_x > 0)
						game->direction = EAST;
					else
						game->direction = WEST;
				}
				else
				{
					if (dir_y > 0)
						game->direction = SOUTH;
					else
						game->direction = NORTH;
				}
				game->dists[game->dist_idx] = sqrt(pow((double)colis_x * game->square_width - game->player_x, 2) + pow((double)colis_y * game->square_height - game->player_y, 2));
				return ;
			}
		}
//		mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)x_iterator, (int)y_iterator, rgb_to_hex(255, 0, 0)); //for drawing rays
		x_iterator += dir_x * speed;
		y_iterator += dir_y * speed;
	}
}