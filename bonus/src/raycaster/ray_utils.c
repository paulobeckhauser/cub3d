/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:25:00 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:46:09 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: is_ray_on_square_edge
 * --------------------------------
 * Checks if the ray is exactly on the edge of a square in the game map.
 * 
 * raycaster: A pointer to the raycaster structure containing raycasting information.
 * 
 * Returns true if the ray's current position is exactly on the edge of a square, false otherwise.
 */
bool	is_ray_on_square_edge(t_raycaster *raycaster)
{
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0
		|| (int)raycaster->y_iterator % SQUARE_SIZE == 0)
		return (true);
	return (false);
}

/* Function: is_ray_out_of_map
 * ----------------------------
 * Checks if the ray has gone out of the bounds of the game map.
 * 
 * raycaster: A pointer to the raycaster structure containing raycasting information.
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Returns true if the ray's current position is outside the game map, false otherwise.
 */
bool	is_ray_out_of_map(t_raycaster *raycaster, t_game *game)
{
	if (raycaster->colis_y < 0 || raycaster->colis_x < 0
		|| !game->data.map_element[(int)raycaster->colis_y]
		|| ft_strlen(game->data.map_element[(int)raycaster->colis_y])
		< (size_t)raycaster->colis_x
		|| !game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x])
		return (true);
	return (false);
}

/* Function: set_ray_direction
 * ----------------------------
 * Sets the direction of the ray based on its current position and direction of movement.
 * 
 * raycaster: A pointer to the raycaster structure containing raycasting information.
 * direction: A pointer to an integer where the direction of the ray will be stored.
 * 
 * This function determines the ray's direction (NORTH, SOUTH, EAST, WEST) based on its movement and updates the direction parameter accordingly.
 */
void	set_ray_direction(t_raycaster *raycaster, int *direction)
{
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0
		&& (int)raycaster->y_iterator % SQUARE_SIZE == 0)
		return ;
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0)
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

/* Function: calc_ray_distance
 * ----------------------------
 * Calculates the distance from the player to the point where the ray collides with an obstacle.
 * 
 * raycaster: A pointer to the raycaster structure containing raycasting information.
 * game: A pointer to the game structure containing all game information and state.
 * ray_angle: The angle of the ray being cast.
 * dist: A pointer to a float where the calculated distance will be stored.
 * 
 * This function calculates the distance corrected for fish-eye effect, taking into account the angle of the ray relative to the player's viewing direction.
 */
void	calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle,
		float *dist)
{
	float	raw_dist;

	raw_dist = sqrtf(powf(raycaster->colis_x * SQUARE_SIZE
				- game->data.player->x, 2) + powf(raycaster->colis_y
				* SQUARE_SIZE - game->data.player->y, 2));
	*dist = raw_dist * cosf(ray_angle
			- to_radians(game->ray_main_angle));
}
