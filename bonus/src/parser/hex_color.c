/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:16 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: rgb_to_hex
Converts RGB color values to a hexadecimal color code.
red: The red component of the color (0-255).
green: The green component of the color (0-255).
blue: The blue component of the color (0-255).
Returns the hexadecimal representation of the color. */

int	rgb_to_hex(int red, int green, int blue)
{
	int	hex;

	hex = (red << 16) | (green << 8) | blue;
	hex = (hex & 0xFFFFFF) | 0x00 << 24;
	return (hex);
}

/* Function: array_format_check
Checks if the RGB color array has the correct format.
array: The array containing the RGB color components as strings.
data: A pointer to the game data structure.
Returns true if the format is correct, false otherwise. */

bool	array_format_check(char **array, t_data *data)
{
	if (!array[0] || !array[1] || !array[2])
	{
		replace_error_message(data, "RGB in wrong format");
		free_2d_array(array);
		return (false);
	}
	return (true);
}

/* Function: check_error_rgb_format
Validates the range of a single RGB color component.
color: The color component to validate.
data: A pointer to the game data structure.
Returns true if the color is within the valid range (1-255), false otherwise. */

bool	check_error_rgb_format(int color, t_data *data)
{
	if (color <= 0 || color > 255)
	{
		replace_error_message(data, "RGB in wrong format");
		return (false);
	}
	return (true);
}

/* Function: store_hex_color
Stores the hexadecimal color value for either the floor or ceiling.
str: The string containing the RGB color components separated by commas.
data: A pointer to the game data structure.
surf: A character indicating whether the color is for the floor ('F') or ceiling ('C').
Returns true if the color is successfully stored, false otherwise. */

bool	store_hex_color(char *str, t_data *data, char surf)
{
	char	**array;
	int		red;
	int		green;
	int		blue;

	array = ft_split(str, ',');
	if (!array)
		return (free_2d_array(array), false);
	init_vars_colors(&red, &green, &blue);
	if (!array_format_check(array, data) || !get_red_color(&red, array, data)
		|| !get_green_color(&green, array, data) || !get_blue_color(&blue,
			array, data))
	{
		free_2d_array(array);
		return (false);
	}
	if (surf == 'F')
		data->color_floor = rgb_to_hex(red, green, blue);
	else if (surf == 'C')
		data->color_ceiling = rgb_to_hex(red, green, blue);
	else
		return (false);
	free_2d_array(array);
	return (true);
}

/* Function: clean_store_hex_color
Cleans and stores the hexadecimal color value for either the floor or ceiling.
data: A pointer to the game data structure.
i: The index of the color in the data structure.
surf: A character indicating whether the color is for the floor ('F') or ceiling ('C').
Returns true if the color is successfully cleaned and stored, false otherwise. */

bool	clean_store_hex_color(t_data *data, int i, char surf)
{
	char	*cleaned_string;

	cleaned_string = NULL;
	cleaned_string = clean_str_color(data, i, surf);
	if (!cleaned_string || !(check_other_values_rgb(cleaned_string, data)))
	{
		free(cleaned_string);
		free_variables_error(data);
		return (false);
	}
	if (!store_hex_color(cleaned_string, data, surf))
	{
		free(cleaned_string);
		return (false);
	}
	if (surf == 'F')
		data->color_floor_count++;
	else if (surf == 'C')
		data->color_ceiling_count++;
	free(cleaned_string);
	return (true);
}
