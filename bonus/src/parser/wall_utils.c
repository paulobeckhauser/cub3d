/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:42:33 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: init_vars_check_wall
 * -------------------------------
 * Initializes the variables used for wall checking to 0.
 * 
 * i: Pointer to the integer to be initialized.
 * j: Pointer to the second integer to be initialized.
 * 
 * This function is a utility function used to initialize the loop variables for wall checking.
 */
void	init_vars_check_wall(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

/* Function: check_edges
 * ----------------------
 * Checks if the current position is at the edge of the map and if it is properly surrounded by walls.
 * 
 * i: The current row index in the map.
 * j: The current column index in the map.
 * data: A pointer to the game data structure.
 * 
 * Returns true if the current position is at the edge and is properly surrounded by walls, false otherwise.
 */
bool	check_edges(int i, int j, t_data *data)
{
	if (i == 0 && check_first_line(i, j, data))
		return (true);
	if ((i == size_array(data->map_element) - 1) && (check_last_line(i, j,
				data)))
		return (true);
	return (false);
}

/* Function: return_error_wall
 * ----------------------------
 * Sets the error message for a map not being properly surrounded by walls.
 * 
 * data: A pointer to the game data structure.
 * 
 * Returns false to indicate an error has occurred.
 */
bool	return_error_wall(t_data *data)
{
	replace_error_message(data, "Map not surrounded by walls");
	return (false);
}

/* Function: write_map_lines
 * --------------------------
 * Copies the map data into a backup array.
 * 
 * map_backup: The backup array where the map data will be copied.
 * data: A pointer to the game data structure.
 * 
 * Returns true if the map lines were successfully copied, false if a memory allocation error occurred.
 */
static bool	write_map_lines(char **map_backup, t_data *data)
{
	int	i;

	i = 0;
	while (data->map_element[i])
	{
		map_backup[i] = ft_strdup(data->map_element[i]);
		if (!map_backup[i])
		{
			replace_error_message(data, "Memory allocation failed");
			free_variables_error(data);
			return (false);
		}
		i++;
	}
	map_backup[i] = NULL;
	return (true);
}

/* Function: check_surround
 * -------------------------
 * Checks if the map is properly surrounded by walls using a flood fill algorithm.
 * 
 * data: A pointer to the game data structure.
 * 
 * Returns true if the map is properly surrounded by walls, false otherwise.
 */
bool	check_surround(t_data *data)
{
	char	**map_backup;

	map_backup = malloc((size_array(data->map_element) + 1) * sizeof(char *));
	if (!map_backup)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	if (!write_map_lines(map_backup, data) || !apply_ffill_algo(map_backup,
			data))
	{
		free_2d_array(map_backup);
		return (false);
	}
	free_2d_array(map_backup);
	return (true);
}
