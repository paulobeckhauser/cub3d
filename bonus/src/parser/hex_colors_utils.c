/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_colors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:35 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:19:16 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: init_vars_colors
Initializes RGB color variables to 0.
red: Pointer to the red component variable.
green: Pointer to the green component variable.
blue: Pointer to the blue component variable.
This function sets the initial values of red, green, and blue to 0. */
void	init_vars_colors(int *red, int *green, int *blue)
{
	*red = 0;
	*green = 0;
	*blue = 0;
}

/* Function: check_garbage_values_colors
Checks for non-numeric characters in a string representing a color component.
str: The string to check.
data: A pointer to the game data structure.
Returns true if the string contains only numeric characters, false otherwise. */
static bool	check_garbage_values_colors(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (replace_error_message(data, "RGB in wrong format"), false);
		i++;
	}
	return (true);
}

/* Function: get_red_color
Extracts and validates the red component from an RGB color array.
red: Pointer to the red component variable.
array: The array containing the RGB color components as strings.
data: A pointer to the game data structure.
Returns true if the red component is successfully extracted and validated, false otherwise. */
bool	get_red_color(int *red, char **array, t_data *data)
{
	if (ft_strcmp(array[0], "0") == 0)
		*red = 0;
	else
	{
		*red = ft_atoi(array[0]);
		if (!check_error_rgb_format(*red, data)
			|| !check_garbage_values_colors(array[0], data))
			return (false);
	}
	return (true);
}

/* Function: get_green_color
Extracts and validates the green component from an RGB color array.
green: Pointer to the green component variable.
array: The array containing the RGB color components as strings.
data: A pointer to the game data structure.
Returns true if the green component is successfully extracted and validated, false otherwise. */
bool	get_green_color(int *green, char **array, t_data *data)
{
	if (ft_strcmp(array[1], "0") == 0)
		*green = 0;
	else
	{
		*green = ft_atoi(array[1]);
		if (!check_error_rgb_format(*green, data)
			|| !check_garbage_values_colors(array[1], data))
			return (false);
	}
	return (true);
}

/* Function: get_blue_color
Extracts and validates the blue component from an RGB color array.
blue: Pointer to the blue component variable.
array: The array containing the RGB color components as strings.
data: A pointer to the game data structure.
Returns true if the blue component is successfully extracted and validated, false otherwise. */
bool	get_blue_color(int *blue, char **array, t_data *data)
{
	if (ft_strcmp(array[2], "0") == 0)
		*blue = 0;
	else
	{
		*blue = ft_atoi(array[2]);
		if (!check_error_rgb_format(*blue, data)
			|| !check_garbage_values_colors(array[2], data))
			return (false);
	}
	return (true);
}
