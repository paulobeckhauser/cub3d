/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:47:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:40:59 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: check_north_texture
 * ------------------------------
 * Checks if the north texture input is valid.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function checks if there is exactly one input for the north texture.
 * If there are more than one or none, it sets an error message accordingly.
 */
bool	check_north_texture(t_data *data)
{
	if (data->text_count_n > 1)
	{
		replace_error_message(data, "More than 1 input for North Texture");
		return (false);
	}
	else if (data->text_count_n < 1)
	{
		replace_error_message(data,
			"No input for North Texture or in wrong format");
		return (false);
	}
	return (true);
}

/* Function: check_south_texture
 * ------------------------------
 * Checks if the south texture input is valid.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function checks if there is exactly one input for the south texture.
 * If there are more than one or none, it sets an error message accordingly.
 */
bool	check_south_texture(t_data *data)
{
	if (data->text_count_s > 1)
	{
		replace_error_message(data, "More than 1 input for South Texture");
		return (false);
	}
	else if (data->text_count_s < 1)
	{
		replace_error_message(data,
			"No input for South Texture or in wrong format");
		return (false);
	}
	return (true);
}

/* Function: check_west_texture
 * -----------------------------
 * Checks if the west texture input is valid.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function checks if there is exactly one input for the west texture.
 * If there are more than one or none, it sets an error message accordingly.
 */
bool	check_west_texture(t_data *data)
{
	if (data->text_count_w > 1)
	{
		replace_error_message(data, "More than 1 input for West Texture");
		return (false);
	}
	else if (data->text_count_w < 1)
	{
		replace_error_message(data,
			"No input for West Texture or in wrong format");
		return (false);
	}
	return (true);
}

/* Function: check_east_texture
 * -----------------------------
 * Checks if the east texture input is valid.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function checks if there is exactly one input for the east texture.
 * If there are more than one or none, it sets an error message accordingly.
 */
bool	check_east_texture(t_data *data)
{
	if (data->text_count_e > 1)
	{
		replace_error_message(data, "More than 1 input for East Texture");
		return (false);
	}
	else if (data->text_count_e < 1)
	{
		replace_error_message(data,
			"No input for East Texture or in wrong format");
		return (false);
	}
	return (true);
}

/* Function: check_input_texture
 * ------------------------------
 * Checks if all texture inputs are valid.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function checks if the inputs for north, south, west, and east textures are valid by calling their respective check functions.
 * If any of the checks fail, it returns false.
 */
bool	check_input_texture(t_data *data)
{
	if (!check_north_texture(data) || !check_south_texture(data)
		|| !check_west_texture(data) || !check_east_texture(data))
		return (false);
	return (true);
}
