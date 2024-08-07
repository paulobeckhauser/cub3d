/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:38:29 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:43:48 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: check_last_line
 * --------------------------
 * Checks if the last line of the map is surrounded by walls.
 * 
 * i: The row index to start checking from (typically the last row of the map).
 * j: The column index to check in the specified row.
 * data: A pointer to the game data structure containing all game information and state.
 * 
 * This function iterates backwards through the row specified by i, checking if each element is a wall ('1') or a space (' ').
 * If a space is encountered, the function continues checking the previous element.
 * If an element other than a wall or space is encountered, an error message is set, and the function returns false.
 * The function returns true if the row is properly surrounded by walls.*/
bool	check_last_line(int i, int j, t_data *data)
{
	int	col;

	col = i;
	while (data->map_element[col][j])
	{
		if (data->map_element[col][j] == '1')
			break ;
		else if (data->map_element[col][j] == ' ')
		{
			col--;
			continue ;
		}
		else
		{
			replace_error_message(data, "Map not surrounded by walls");
			return (false);
		}
		col--;
	}
	return (true);
}

/* Function: check_first_line
 * ---------------------------
 * Checks if the first line of the map is surrounded by walls.
 * 
 * i: The row index to start checking from (typically the first row of the map).
 * j: The column index to check in the specified row.
 * data: A pointer to the game data structure containing all game information and state.
 * 
 * This function iterates through the row specified by i, checking if each element is a wall ('1') or a space (' ').
 * If a space is encountered, the function continues checking the next element.
 * If an element other than a wall or space is encountered, an error message is set, and the function returns false.
 * The function returns true if the row is properly surrounded by walls.
 */
bool	check_first_line(int i, int j, t_data *data)
{
	int	col;

	if (i == 0)
	{
		col = i;
		while (data->map_element[col][j])
		{
			if (data->map_element[col][j] == '1')
				break ;
			else if (data->map_element[col][j] == ' ')
			{
				col++;
				continue ;
			}
			else
			{
				replace_error_message(data, "Map not surrounded by walls");
				return (false);
			}
			col++;
		}
	}
	return (true);
}

/* Function: check_spaces
 * -----------------------
 * Checks for spaces in the map and validates surrounding walls.
 * 
 * data: A pointer to the game data structure containing all game information and state.
 * i: The row index to check in the map.
 * 
 * This function iterates through each column of the specified row, checking for spaces or tab/newline characters.
 * If a space or valid whitespace character is encountered, it calls check_edges to validate the surrounding walls.
 * If an invalid character is encountered, it calls return_error_wall to set an error message and returns false.
 * The function returns true if all spaces are properly surrounded by walls.*/
bool	check_spaces(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map_element[i][j])
	{
		if (data->map_element[i][j] == '1')
		{
			j++;
			continue ;
		}
		else if (data->map_element[i][j] == ' ' || (data->map_element[i][j] >= 9
				&& data->map_element[i][j] <= 13))
			return (check_edges(i, j, data));
		else
			return (return_error_wall(data));
		j++;
	}
	return (true);
}

/* Function: check_wall
 * ---------------------
 * Checks if all walls in the map are valid.
 * 
 * data: A pointer to the game data structure containing all game information and state.
 * 
 * This function initializes variables for iteration and iterates through each row of the map.
 * It specifically checks the first and last rows for proper wall enclosure by calling check_spaces.
 * The function returns false if any row is not properly enclosed by walls, otherwise returns true.
 */
bool	check_wall(t_data *data)
{
	int	i;
	int	j;

	init_vars_check_wall(&i, &j);
	while (data->map_element[i])
	{
		if (i == 0 || i == size_array(data->map_element) - 1)
		{
			if (!check_spaces(data, i))
				return (false);
		}
		i++;
	}
	return (true);
}
