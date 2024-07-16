/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:47:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 16:56:12 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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

bool	check_input_texture(t_data *data)
{
	if (!check_north_texture(data) || !check_south_texture(data)
		|| !check_west_texture(data) || !check_east_texture(data))
		return (false);
	return (true);
}
