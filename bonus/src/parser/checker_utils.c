/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:13:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:25 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: size_array
 * ---------------------
 * Counts the number of elements in a null-terminated array of strings.
 * 
 * array: The array of strings to be counted.
 * 
 * Returns the number of elements in the array, not counting the null terminator.
 */
int	size_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/* Function: check_extension
 * --------------------------
 * Checks if a given string ends with a specified extension.
 * 
 * data: A pointer to the game data structure where error messages can be stored.
 * str: The string whose extension is to be checked.
 * extension: The expected extension of the string.
 * 
 * Returns true if the string ends with the specified extension, false otherwise.
 * If the string does not end with the expected extension, an error message is set in the game data structure.
 */
bool	check_extension(t_data *data, char *str, char *extension)
{
	int		i;
	char	**array;

	array = NULL;
	array = ft_split(str, '.');
	i = size_array(array) - 1;
	if (size_array(array) == 1 || ft_strcmp(array[i], extension) != 0)
	{
		replace_error_message(data, "Map is not a '.cub' file");
		free_2d_array(array);
		return (false);
	}
	free_2d_array(array);
	return (true);
}

/* Function: check_other_values_rgb
 * ---------------------------------
 * Validates the format of an RGB value string.
 * 
 * cleaned_string: The RGB value string to be validated.
 * data: A pointer to the game data structure where error messages can be stored.
 * 
 * Returns true if the RGB value string is correctly formatted, false otherwise.
 * A correctly formatted RGB value string should contain exactly three numeric values separated by commas.
 * If the format is incorrect, an error message is set in the game data structure.
 */
bool	check_other_values_rgb(char *cleaned_string, t_data *data)
{
	char	**array;

	(void)data;
	array = ft_split(cleaned_string, ',');
	if (!array)
	{
		return (false);
	}
	if (size_array(array) != 3)
	{
		return (replace_error_message(data, "More elements in rgb value"),
			false);
	}
	free_2d_array(array);
	return (true);
}
