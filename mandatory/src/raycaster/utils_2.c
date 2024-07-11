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

#include "../../incl/cub3d.h"

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

bool    is_collision_point_wall(t_raycaster *raycaster, t_game *game)
{
	if (game->map[(int)raycaster->colis_y][(int)raycaster->colis_x] == '1')
		return (true);
	return (false);
}

void    set_ray_direction(t_raycaster *raycaster, t_game *game, int *direction)
{
	if ((int)raycaster->x_iterator % (int)game->square_size == 0
	    && (int)raycaster->y_iterator % (int)game->square_size == 0)
		return ;
	if ((int)raycaster->x_iterator % (int)game->square_size == 0)
	{
		if (raycaster->dir_x >= 0)
			*direction = EAST;
		else
			*direction = WEST;
	}
	else
	{
		if (raycaster->dir_y >= 0)
			*direction = SOUTH;
		else
			*direction = NORTH;
	}
}

void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle, float *dist)
{
	float raw_dist;
	
	raw_dist = sqrtf(powf(raycaster->colis_x
	                    * game->square_size - game->data->player->x, 2)
	                + powf(raycaster->colis_y
	                      * game->square_size - game->data->player->y, 2));
	*dist = raw_dist * cosf(ray_angle - to_radians(game->ray_main_angle));
}
