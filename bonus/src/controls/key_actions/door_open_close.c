/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:43:52 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: open_close_door
 * -------------------------
 * Checks the distance to each door in the game and opens or closes it if the player
 * is within a certain distance.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Iterates through all doors in the game. If a door is within the defined open distance,
 * it triggers a change in the door's state (open or close) and exits the loop to ensure
 * only one door is interacted with per function call.
 */
void	open_close_door(t_game *game)
{
	int				i;

	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].dist >= 0 && game->door[i].dist < DOOR_OPEN_DISTANCE)
		{
			change_door_state(game, i);
			return ;
		}
		++i;
	}
}

/* Function: change_door_state
 * ---------------------------
 * Changes the state of a specified door from open to closed or vice versa.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * i: The index of the door in the game's door array.
 * 
 * Depending on the current state of the door (represented by specific characters in the
 * map data), this function toggles the door's state. If the door is a special door (indicated
 * by '6') that can only be opened when there are no enemies, it checks the enemy count before
 * opening. The function sets flags to indicate whether doors are currently being opened or closed.
 */
void	change_door_state(t_game *game, int i)
{
	if (game->data.map_element[game->door[i].y][game->door[i].x]
		== '6' && game->enemy_count <= 0)
	{
		game->animation.door_are_opening = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '7';
	}
	else if (game->data.map_element[game->door[i].y][game->door[i].x] == '2')
	{
		game->animation.door_are_opening = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '3';
	}
	else if (game->data.map_element[game->door[i].y][game->door[i].x] == '7')
	{
		game->animation.door_are_closing = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '6';
	}
	else
	{
		game->animation.door_are_closing = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '2';
	}
}
