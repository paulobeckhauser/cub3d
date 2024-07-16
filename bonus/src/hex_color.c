/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/01 18:16:29 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	rgb_to_hex(int red, int green, int blue)
{
	int	hex;

	hex = (red << 16) | (green << 8) | blue;
	hex = (hex & 0xFFFFFF) | 0x00 << 24;
	return (hex);
}

bool	store_hex_color(char *str, t_data *data, char surf)
{
	char	**array;
	int		red;
	int		green;
	int		blue;

	array = ft_split(str, ',');
	red = 0;
	green = 0;
	blue = 0;
	if (!array[0] || !array[1] || !array[2])
	{
		replace_error_message(data, "RGB in wrong format");
		free_2d_array(array);
		return (false);
	}
	if (ft_strcmp(array[0], "0") == 0)
		red = 0;
	else
	{
		red = ft_atoi(array[0]);
		if (red <= 0 || red > 255)
		{
			replace_error_message(data, "RGB in wrong format");
			free_2d_array(array);
			return (false);
		}
	}
	if (ft_strcmp(array[1], "0") == 0)
		green = 0;
	else
	{
		green = ft_atoi(array[1]);
		if (green <= 0 || green > 255)
		{
			replace_error_message(data, "RGB in wrong format");
			free_2d_array(array);
			return (false);
		}
	}
	if (ft_strcmp(array[2], "0") == 0)
		blue = 0;
	else
	{
		blue = ft_atoi(array[2]);
		if (blue <= 0 || blue > 255)
		{
			replace_error_message(data, "RGB in wrong format");
			free_2d_array(array);
			return (false);
		}
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
