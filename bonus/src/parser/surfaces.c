/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surfaces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:35:57 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: check_input_surfaces
 * -------------------------------
 * Validates the input for floor and ceiling colors in the configuration file.
 * 
 * data: A pointer to the data structure containing all parsed information.
 * 
 * This function checks if there is exactly one input for both floor and ceiling colors.
 * If there are multiple inputs or no input for either, it sets an appropriate error message.
 * Returns true if the inputs are valid, false otherwise.
 */
bool	check_input_surfaces(t_data *data)
{
	if (data->color_floor_count > 1)
	{
		replace_error_message(data, "More than 1 input for floor color");
		return (false);
	}
	else if (data->color_floor_count < 1)
	{
		replace_error_message(data,
			"No input for floor color or in wrong format");
		return (false);
	}
	if (data->color_ceiling_count > 1)
	{
		replace_error_message(data, "More than 1 input for ceiling color");
		return (false);
	}
	else if (data->color_ceiling_count < 1)
	{
		replace_error_message(data,
			"No input for ceiling color or in wrong format");
		return (false);
	}
	return (true);
}

/* Function: floor_ceiling_lines
 * ------------------------------
 * Parses and stores the floor and ceiling color values from the configuration file.
 * 
 * array: An array of strings containing the split line from the configuration file.
 * data: A pointer to the data structure containing all parsed information.
 * i: The current index of the line being processed in the configuration file.
 * 
 * This function checks if the first element of the array is "F" or "C" (indicating floor or ceiling),
 * and then attempts to store the corresponding color value in hexadecimal format.
 * Returns true if the color is successfully stored, false otherwise.
 */
bool	floor_ceiling_lines(char **array, t_data *data, int i)
{
	if (array[0])
	{
		if (ft_strcmp(array[0], "F") == 0)
		{
			if (!clean_store_hex_color(data, i, 'F'))
				return (false);
		}
		else if (ft_strcmp(array[0], "C") == 0)
		{
			if (!clean_store_hex_color(data, i, 'C'))
				return (false);
		}
	}
	return (true);
}

/* Function: store_surface_colors
 * -------------------------------
 * Reads the configuration file and stores the floor and ceiling color values.
 * 
 * data: A pointer to the data structure containing all parsed information.
 * 
 * This function iterates through each line of the configuration file, splits the line into an array,
 * and processes it to store floor and ceiling colors. It checks for memory allocation failures and
 * validates the input for floor and ceiling colors.
 * Returns true if all colors are successfully stored and validated, false otherwise.
 */
bool	store_surface_colors(t_data *data)
{
	int		i;
	char	**array;

	i = 0;
	array = NULL;
	while (data->cub_file[i])
	{
		array = ft_split(data->cub_file[i], ' ');
		if (!array)
		{
			free_2d_array(array);
			return (replace_error_message(data, "Memory allocation failed"),
				false);
		}
		if (!floor_ceiling_lines(array, data, i))
			return (free_2d_array(array), false);
		free_2d_array(array);
		i++;
	}
	if (!check_input_surfaces(data))
		return (false);
	return (true);
}
