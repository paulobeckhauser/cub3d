/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:29:20 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:44:57 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: calc_collision_point_x_y
 * -----------------------------------
 * Calculates the x and y coordinates of the collision point based on the raycaster's direction and position.
 * 
 * raycaster: A pointer to the raycaster structure containing all raycasting information and state.
 * 
 * This function adjusts the collision point coordinates based on the direction of the raycaster. It ensures that the collision points are calculated accurately for both positive and negative directions.
 */
void	calc_collision_point_x_y(t_raycaster *raycaster)
{
	if (raycaster->dir_x > 0)
		raycaster->colis_x = raycaster->x_iterator / SQUARE_SIZE;
	else
		raycaster->colis_x = (raycaster->x_iterator - 1) / SQUARE_SIZE;
	if (raycaster->dir_y > 0)
		raycaster->colis_y = raycaster->y_iterator / SQUARE_SIZE;
	else
		raycaster->colis_y = (raycaster->y_iterator - 1) / SQUARE_SIZE;
}

/* Function: is_collision_point_wall
 * ----------------------------------
 * Checks if the collision point corresponds to a wall in the game map.
 * 
 * raycaster: A pointer to the raycaster structure containing all raycasting information and state.
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Returns true if the collision point is a wall, otherwise false. This function is crucial for determining collision with walls to stop movement or raycasting.
 */
bool	is_collision_point_wall(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0
		&& (int)raycaster->colis_y < game->data.number_lines_map_element
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x]
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x] == '1')
		return (true);
	return (false);
}

/* Function: is_collision_point_door
 * ----------------------------------
 * Checks if the collision point corresponds to a door in the game map.
 * 
 * raycaster: A pointer to the raycaster structure containing all raycasting information and state.
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Returns true if the collision point is a door, otherwise false. This function helps in determining interactions with doors, such as opening or closing them.
 */
bool	is_collision_point_door(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0
		&& (int)raycaster->colis_y < game->data.number_lines_map_element
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x]
		&& (game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '2'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '3'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '6'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '7'))
		return (true);
	return (false);
}

/* Function: is_collision_point_enemy
 * -----------------------------------
 * Checks if the collision point corresponds to an enemy in the game map.
 * 
 * raycaster: A pointer to the raycaster structure containing all raycasting information and state.
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Returns true if the collision point is an enemy, otherwise false. This function is used to determine if the player's attack hits an enemy.
 */
bool	is_collision_point_enemy(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0
		&& (int)raycaster->colis_y < game->data.number_lines_map_element
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x]
		&& (game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '4'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '5'))
		return (true);
	return (false);
}

/* Function: is_coll_point_same
 * -----------------------------
 * Checks if the current collision point is the same as the previous one.
 * 
 * raycaster: A pointer to the raycaster structure containing all raycasting information and state.
 * 
 * Returns true if the current and previous collision points are the same, otherwise false. This function is useful for optimizing collision detection by avoiding redundant checks.
 */
bool	is_coll_point_same(t_raycaster *raycaster)
{
	if ((int)raycaster->colis_y != raycaster->prev_colis_y
		|| (int)raycaster->colis_x != raycaster->prev_colis_x)
		return (false);
	return (true);
}
