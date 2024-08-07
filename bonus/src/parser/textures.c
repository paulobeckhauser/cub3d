/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:58 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:41:55 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: check_xpm_extension
 * ------------------------------
 * Checks if the provided texture file has an .xpm extension.
 * 
 * data: A pointer to the game's data structure.
 * str: The filename string to check.
 * 
 * This function splits the filename by '.', checks the last element of the resulting array to ensure it is "xpm",
 * and returns false with an error message if not. It returns true if the file extension is correct.
 */
bool	check_xpm_extension(t_data *data, char *str)
{
	char	**array;
	int		i;

	array = NULL;
	array = ft_split(str, '.');
	i = size_array(array) - 1;
	if (array[i])
	{
		if (ft_strcmp(array[i], "xpm") != 0)
		{
			replace_error_message(data,
				"One or more texture not in .xpm format");
			free_2d_array(array);
			return (false);
		}
	}
	free_2d_array(array);
	return (true);
}

/* Function: check_storage_textures
 * ---------------------------------
 * Checks and stores texture paths from the game's configuration file.
 * 
 * data: A pointer to the game's data structure.
 * 
 * This function iterates through each line of the game's configuration file,
 * splits each line by spaces, and attempts to store texture paths for north, south, west, and east walls.
 * It returns false if any texture path storage fails.
 */
bool	check_storage_textures(t_data *data)
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
			replace_error_message(data, "Memory allocation failed");
			return (free_2d_array(array), false);
		}
		if (array[0])
		{
			if (!store_north_texture_format(data, array)
				|| !store_south_texture_format(data, array)
				|| !store_west_texture_format(data, array)
				|| !store_east_texture_format(data, array))
				return (free_2d_array(array), false);
		}
		i++;
		free_2d_array(array);
	}
	return (true);
}

/* Function: check_open_texture_files
 * -----------------------------------
 * Verifies that texture files can be opened (i.e., they exist and are accessible).
 * 
 * data: A pointer to the game's data structure.
 * 
 * This function attempts to open each texture file specified in the game's data structure.
 * It returns false and sets an error message if any file cannot be opened.
 */
bool	check_open_texture_files(t_data *data)
{
	int	fd_north;
	int	fd_south;
	int	fd_west;
	int	fd_east;

	fd_north = open(data->texture_north, O_RDONLY);
	fd_south = open(data->texture_south, O_RDONLY);
	fd_west = open(data->texture_west, O_RDONLY);
	fd_east = open(data->texture_east, O_RDONLY);
	if (fd_north == -1 || fd_south == -1 || fd_west == -1 || fd_east == -1)
	{
		replace_error_message(data, "One or more texture file does not exist");
		close(fd_north);
		close(fd_south);
		close(fd_west);
		close(fd_east);
		return (false);
	}
	close(fd_north);
	close(fd_south);
	close(fd_west);
	close(fd_east);
	return (true);
}

/* Function: store_textures
 * -------------------------
 * Orchestrates the checking and storing of texture paths from the configuration file.
 * 
 * data: A pointer to the game's data structure.
 * 
 * This function sequentially calls other functions to check the storage of textures,
 * validate texture file inputs, and verify that texture files can be opened.
 * It returns false if any step fails.
 */
bool	store_textures(t_data *data)
{
	if (!check_storage_textures(data) || !check_input_texture(data)
		|| !check_open_texture_files(data))
		return (false);
	return (true);
}
