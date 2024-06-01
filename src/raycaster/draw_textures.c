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

#include <stdio.h>

#include "../../incl/cub3d.h"
#include "../../incl/raycaster_test.h"
#include "../../incl/structs.h"
#include "../../libs/mlx_linux/mlx.h"

void	draw_map(t_game *game)
{
	t_line *map_line_start;
	int	j;
	game->map_x = 0;
	game->map_y = 0;
	map_line_start = game->map_line;
	while (game->map_line)
	{
		j = 0;
		game->map_x = 0;
		while (j < game->map_line->len)
		{

			if (game->map_line->sprites[j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_floor, (int)game->map_x, (int)game->map_y);
			else if (game->map_line->sprites[j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_wall, (int)game->map_x, (int)game->map_y);
			else if (game->map_line->sprites[j] == 'N')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_floor, (int)game->map_x, (int)game->map_y);
				if (!game->player_marked)
				{
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_player, (int)game->map_x, (int)game->map_y);
					game->player_marked = 1;
					game->player_x = game->map_x;
					game->player_y = game->map_y;
					game->ray_x = game->player_x + 8;
					game->ray_y = game->player_y - 92;
				}
			}
			game->map_x += 64;
			j++;
		}
		game->map_y += 64;
		game->map_line = game->map_line->next;
	}
	game->map_line = map_line_start;
	draw_ray(game);
}

double  calc_slope(t_game *game)
{
	return (game->ray_y - game->player_y) / (game->ray_y - game->player_y);
}

double  calc_y_intercept(t_game *game)
{
	return (game->player_y - )
}

// calculate y for each x using y = mx + b,
// m - the slope of the line m = (y2 - y1) / (x2 -x1),
// b - y-intercept b = y1 - m * x1

void	draw_ray(t_game *game)
{
	double  x_iterator;
	double  y_iterator;
	double  slope;
	double  y_intercept;
	
	x_iterator = game->player_x;
	y_iterator = game->player_y;
	slope = calc_slope(game);
	y_intercept = calc_y_intercept(game);
	while (x_iterator <= game->player_x && y_iterator <= game->player_y)
	{
		x_iterator += 1;
		y_iterator = slope * x_iterator + y_intercept;
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)x_iterator, (int)y_iterator, rgb_to_hex(255, 0, 0));
	}
}