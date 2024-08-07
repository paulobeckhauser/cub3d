/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:17:16 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:27:21 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: check_number_player
 * ------------------------------
 * Checks if the number of players in the map is valid (exactly one).
 * 
 * data: A pointer to the game data structure.
 * count_player: The number of players found in the map.
 * 
 * Returns false and sets an error message if no player or more than one player is found. Returns true for exactly one player.
 */
bool	check_number_player(t_data *data, int count_player)
{
	if (count_player == 0)
	{
		replace_error_message(data, "No player in the map");
		return (false);
	}
	else if (count_player > 1)
	{
		replace_error_message(data, "More than one player in the map");
		return (false);
	}
	return (true);
}

/* Function: count_player
 * -----------------------
 * Counts the number of players ('N', 'S', 'W', 'E') in the map.
 * 
 * data: A pointer to the game data structure.
 * 
 * Iterates through the map elements, counting occurrences of player direction symbols. Calls check_number_player to validate the count.
 * Returns false if the player count is invalid, true otherwise.
 */
bool	count_player(t_data *data)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	j = 0;
	count_player = 0;
	while (data->map_element[i])
	{
		j = 0;
		while (data->map_element[i][j])
		{
			if (data->map_element[i][j] == 'N' || data->map_element[i][j] == 'S'
				|| data->map_element[i][j] == 'W'
				|| data->map_element[i][j] == 'E')
			{
				count_player++;
			}
			j++;
		}
		i++;
	}
	if (!check_number_player(data, count_player))
		return (false);
	return (true);
}

/* Function: replace_player_for_floor
 * -----------------------------------
 * Replaces the player's position on the map with a floor tile ('0').
 * 
 * data: A pointer to the game data structure.
 * 
 * Iterates through the map, finding the player's position. Updates the player's position in the data structure and replaces the player symbol on the map with '0'.
 */
void	replace_player_for_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_element[i])
	{
		j = 0;
		while (data->map_element[i][j])
		{
			if (data->map_element[i][j] == 'N' || data->map_element[i][j] == 'S'
				|| data->map_element[i][j] == 'W'
				|| data->map_element[i][j] == 'E')
			{
				data->player->x = (float)j * 100 + 100 / 2;
				data->player->y = (float)i * 100 + 100 / 2;
				data->player->direction = data->map_element[i][j];
				data->map_element[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

/* Function: check_player
 * -----------------------
 * Validates the player's presence and position in the map.
 * 
 * data: A pointer to the game data structure.
 * 
 * Calls count_player to ensure there is exactly one player. If valid, calls replace_player_for_floor to update the map.
 * Returns false if the player count is invalid, true otherwise.
 */
bool	check_player(t_data *data)
{
	if (!count_player(data))
		return (false);
	replace_player_for_floor(data);
	return (true);
}
