/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:08:00 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:25:36 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: check_garbage_values_map
 * -----------------------------------
 * Checks for irrelevant data in the map section of the .cub file.
 * 
 * data: A pointer to the game data structure.
 * 
 * Iterates through the lines of the .cub file before the map starts. Splits each line by spaces and checks if the first element is a valid map identifier.
 * If an invalid identifier is found, it frees the allocated memory, sets an error message, and returns false.
 * Returns true if no irrelevant data is found.
 */
bool	check_garbage_values_map(t_data *data)
{
	int		i;
	char	**array;

	i = 0;
	array = NULL;
	while (data->cub_file[i] && i < data->line_start_map_position)
	{
		array = ft_split(data->cub_file[i], ' ');
		if (array[0] == NULL || ft_strcmp(array[0], "NO") == 0
			|| ft_strcmp(array[0], "SO") == 0 || ft_strcmp(array[0], "WE") == 0
			|| ft_strcmp(array[0], "EA") == 0 || ft_strcmp(array[0], "F") == 0
			|| ft_strcmp(array[0], "C") == 0)
			free_2d_array(array);
		else
		{
			free_2d_array(array);
			return (replace_error_message(data, "Irrelevant data in map"),
				false);
		}
		i++;
	}
	return (true);
}

/* Function: parser
 * ----------------
 * Parses the .cub file and initializes the game data structure.
 * 
 * str: The path to the .cub file.
 * data: A pointer to the game data structure.
 * 
 * Allocates memory for the player structure. Initializes game variables and checks the file extension.
 * Stores the content of the .cub file, surface colors, textures, and the map. Also checks for irrelevant data before the map starts.
 * Returns 0 if parsing is successful, otherwise it frees allocated memory and exits the program.
 */
int	parser(char *str, t_data *data)
{
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
	{
		replace_error_message(data, "Memory allocation failed");
		return (free_variables_error(data));
	}
	init_vars(data);
	if (!check_extension(data, str, "cub") || !store_cub_file(data, str)
		|| !store_surface_colors(data) || !store_textures(data)
		|| !store_map(data) || !check_garbage_values_map(data))
		return (free_variables_error(data));
	return (0);
}
