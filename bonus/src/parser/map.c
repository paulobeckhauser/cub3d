/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/21 17:57:14 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: allocate_map_element
 * ------------------------------
 * Allocates memory for the map elements.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function calculates the number of lines in the map element and allocates memory accordingly.
 * Returns true if memory allocation is successful, otherwise it calls the error handling function and returns false.
 */
static bool	allocate_map_element(t_data *data)
{
	data->number_lines_map_element = data->line_end_map_position
		- data->line_start_map_position + 1;
	data->map_element = malloc((data->number_lines_map_element + 1)
			* sizeof(char *));
	if (!data->map_element)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	return (true);
}

/* Function: store_lines_map
 * -------------------------
 * Stores each line of the map from the file into the map element array.
 * 
 * data: A pointer to the game data structure.
 * i: The starting line position in the file to begin storing map lines.
 * 
 * Iterates through each line of the map in the file, duplicating it into the map element array.
 * Returns true if all lines are successfully stored, otherwise it calls the error handling function and returns false.
 */
static bool	store_lines_map(t_data *data, int i)
{
	int	j;

	j = 0;
	while (i <= data->line_end_map_position)
	{
		data->map_element[j] = ft_strdup(data->cub_file[i]);
		if (!data->map_element[j])
		{
			replace_error_message(data, "Memory allocation failed");
			free_variables_error(data);
			return (false);
		}
		i++;
		j++;
	}
	data->map_element[j] = NULL;
	return (true);
}

/* Function: store_map_element
 * ---------------------------
 * Initiates the process of storing map elements from the file into the game data structure.
 * 
 * data: A pointer to the game data structure.
 * 
 * Calls functions to allocate memory for and store each line of the map element.
 * Returns true if the map element is successfully stored, otherwise returns false.
 */
bool	store_map_element(t_data *data)
{
	int	i;

	i = data->line_start_map_position;
	if (!allocate_map_element(data))
		return (false);
	if (!data->map_element)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	if (!store_lines_map(data, i))
		return (false);
	return (true);
}

/* Function: store_map
 * -------------------
 * Orchestrates the process of storing the entire map from the file into the game data structure.
 * 
 * data: A pointer to the game data structure.
 * 
 * Calls various functions to store the first and last line of the map element, check the map's validity, and ensure it's properly enclosed.
 * Returns true if the entire map is successfully stored and validated, otherwise returns false.
 */
bool	store_map(t_data *data)
{
	store_first_line_map_element(data);
	store_last_line_map_element(data);
	if (!store_map_element(data) || !check_map_last_element(data)
		|| !check_map_element_input(data) || !check_empty_line_map(data)
		|| !check_player(data) || !check_surround(data))
		return (false);
	return (true);
}
