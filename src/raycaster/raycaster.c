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

#include "../../incl/raycaster_test.h"
#include "../../incl/standard_libs.h"
#include "../../incl/cub3d.h"

// change degrees to radians
// radians = degrees * (math.pi / 180)

// calculate new coordinates after moving ray by some angle
// x' = x * cos(θ) - y * sin(θ) y' = x * sin(θ) + y * cos(θ)

void	calc_new_ray_x_y(t_game *game)
{
	t_ray_utils ray;

	ray.radians = game->ray_angle * (M_PI / 180);
	ray.shifted_x = game->ray_x - game->player_x;
	ray.shifted_y = game->ray_y - game->player_y;
	ray.new_x = ray.shifted_x * cos(ray.radians) - ray.shifted_y * sin(ray.radians);
	ray.new_y = ray.shifted_x * sin(ray.radians) + ray.shifted_y * cos(ray.radians);
	game->ray_x = ray.new_x + game->player_x;
	game->ray_y = ray.new_y + game->player_y;
	game->ray_angle = 0;
}
