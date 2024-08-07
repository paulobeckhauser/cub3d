/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:09:30 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:19 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: flood_fill
 * --------------------
 * Recursively fills an area of the map with a specified character.
 * 
 * map: The game map represented as a 2D character array.
 * x: The x-coordinate of the starting point for the fill.
 * y: The y-coordinate of the starting point for the fill.
 * target: The character that defines the area to be filled.
 * 
 * This function checks if the current position is within the bounds of the map and not already filled.
 * It then marks the current position as filled and recursively fills adjacent positions.
 * Returns true if the fill was successful, false if it encountered an edge that is not enclosed.
 */
bool	flood_fill(char **map, int x, int y, char target)
{
	size_t	new_y;
	bool	up;
	bool	down;
	bool	right;
	bool	left;

	new_y = (size_t)y;
	if (x < 0 || x >= size_array(map) || y < 0 || new_y >= ft_strlen(map[x]))
		return (false);
	if (map[x][y] == ' ')
		return (false);
	if (map[x][y] != target || map[x][y] == 'X')
		return (true);
	map[x][y] = 'X';
	down = flood_fill(map, x + 1, y, target);
	up = flood_fill(map, x - 1, y, target);
	right = flood_fill(map, x, y + 1, target);
	left = flood_fill(map, x, y - 1, target);
	return (up && down && right && left);
}

/* Function: apply_ffill_algo
 * ---------------------------
 * Applies the flood fill algorithm to the entire map to check for enclosure.
 * 
 * map_backup: A backup of the game map represented as a 2D character array.
 * data: A pointer to a structure containing game data and state.
 * 
 * This function iterates over the map, applying the flood fill algorithm starting from each '0' character.
 * If any '0' character area is not fully enclosed, it sets an error message and returns false.
 * Returns true if all '0' character areas are fully enclosed.
 */
bool	apply_ffill_algo(char **map_backup, t_data *data)
{
	bool	all_surrounded;
	int		i;
	int		j;

	all_surrounded = true;
	i = 0;
	j = 0;
	while (map_backup[i])
	{
		j = 0;
		while (map_backup[i][j])
		{
			if (map_backup[i][j] == '0')
			{
				if (!flood_fill(map_backup, i, j, '0'))
				{
					replace_error_message(data, "Map not surrounded");
					all_surrounded = false;
				}
			}
			j++;
		}
		i++;
	}
	return (all_surrounded);
}
