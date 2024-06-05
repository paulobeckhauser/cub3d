/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:37:08 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:37:12 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

void    change_angle_left(t_game *game)
{
	game->ray_angle -= 10;
	if (game->ray_angle <= 0)
		game->ray_angle += 360;
}

void    change_angle_right(t_game *game)
{
	game->ray_angle += 10;
	if (game->ray_angle >= 360)
		game->ray_angle -= 360;
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
