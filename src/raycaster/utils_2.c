/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:19:39 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:19:40 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

void    calc_collision_point_x_y(t_raycaster *raycaster, t_game *game)
{
	if (raycaster->dir_x > 0)
		raycaster->colis_x = raycaster->x_iterator / game->square_size;
	else
		raycaster->colis_x = (raycaster->x_iterator - 1) / game->square_size;
	if (raycaster->dir_y > 0)
		raycaster->colis_y = raycaster->y_iterator / game->square_size;
	else
		raycaster->colis_y = (raycaster->y_iterator - 1) / game->square_size;
}

bool    is_collision_point_a_wall(t_raycaster *raycaster, t_game *game)
{
	if (game->map[(int)raycaster->colis_y][(int)raycaster->colis_x] == '1')
		return (true);
	return (false);
}

void    set_ray_direction(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->x_iterator % (int)game->square_size == 0
		&& (int)raycaster->y_iterator % (int)game->square_size == 0)
		return ;
	else if ((int)raycaster->x_iterator % (int)game->square_size == 0)
	{
		if (raycaster->dir_x >= 0)
			game->direction = EAST;
		else
			game->direction = WEST;
	}
	else
	{
		if (raycaster->dir_y >= 0)
			game->direction = SOUTH;
		else
			game->direction = NORTH;
	}
}

void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle)
{
	float raw_dist;
	
	raw_dist = sqrt(pow(raycaster->colis_x
	                    * game->square_size - game->player_x, 2)
	                + pow(raycaster->colis_y
	                      * game->square_size - game->player_y, 2));
	game->dists[game->dist_idx] = raw_dist * cosf(ray_angle - to_radians(game->ray_main_angle));
}