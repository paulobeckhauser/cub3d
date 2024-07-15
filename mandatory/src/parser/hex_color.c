/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 19:49:12 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	rgb_to_hex(int red, int green, int blue)
{
	int	hex;

	hex = (red << 16) | (green << 8) | blue;
	hex = (hex & 0xFFFFFF) | 0x00 << 24;
	return (hex);
}

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

bool	check_error_rgb_format(int color, t_data *data, char **array)
{
	if (color <= 0 || color > 255)
	{
		replace_error_message(data, "RGB in wrong format");
		free_2d_array(array);
		return (false);
	}
	return (true);
}

bool	store_hex_color(char *str, t_data *data, char surf)
{
	char	**array;
	int		red;
	int		green;
	int		blue;

	array = ft_split(str, ',');
	init_vars_colors(&red, &green, &blue);
	if (!array_format_check(array, data))
		return (false);
	if (!get_red_color(&red, array, data) || !get_green_color(&green, array,
			data) || !get_blue_color(&blue, array, data))
		return (false);
	if (surf == 'F')
		data->color_floor = rgb_to_hex(red, green, blue);
	else if (surf == 'C')
		data->color_ceiling = rgb_to_hex(red, green, blue);
	else
		return (false);
	free_2d_array(array);
	return (true);
}

bool	clean_store_hex_color(t_data *data, int i, char surf)
{
	char	*cleaned_string;

	cleaned_string = NULL;
	cleaned_string = clean_str_color(data, i, surf);
	if (!cleaned_string)
	{
		free(cleaned_string);
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
