/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:10:02 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 15:10:03 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

double	to_radians(double degrees)
{
	return (degrees * (M_PI / 180));
}

void	mark_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
			{
				game->player_x = x * game->square_width + game->square_width / 2;
				game->player_y = y * game->square_height + game->square_height / 2;
				return ;
			}
			x++;
		}
		y++;
	}

}

void	mark_main_ray(t_game *game)
{
	game->ray_main_x = game->player_x;
	game->ray_main_y = 2 * -game->square_height;
}

// change degrees to radians
// radians = degrees * (math.pi / 180)
// calculate new coordinates after moving ray by some angle
// x' = x * cos(θ) - y * sin(θ) y' = x * sin(θ) + y * cos(θ)

void	calc_new_ray_x_y(t_game *game)
{
	t_ray_utils ray;

	ray.radians = to_radians(game->ray_angle);
	ray.shifted_x = game->ray_main_x - game->player_x;
	ray.shifted_y = game->ray_main_y - game->player_y;
	ray.new_x = ray.shifted_x * cos(ray.radians) - ray.shifted_y * sin(ray.radians);
	ray.new_y = ray.shifted_x * sin(ray.radians) + ray.shifted_y * cos(ray.radians);
	game->ray_new_x = ray.new_x + game->player_x;
	game->ray_new_y = ray.new_y + game->player_y;
}

void	cast_rays(t_game *game)
{
	double	angle_incr_radians;
	double	angle_iter;
	double	dir_x;
	double	dir_y;

	angle_incr_radians = to_radians(60.0 / SCREEN_WIDTH); //field of view (60 deg) divided by screen width
	angle_iter = to_radians(game->ray_angle) - to_radians(30.0);
	dir_x = 0;
	dir_y = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		dir_x = cos(angle_iter);
		dir_y = sin(angle_iter);
		game->ray_new_x = game->player_x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->player_y + dir_y * 2 * SCREEN_HEIGHT;
		draw_ray(game);
		draw_wall_line(game);
		angle_iter += angle_incr_radians;
		++game->dist_idx;
	}
}
