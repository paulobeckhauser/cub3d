/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_colors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:47:35 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 19:49:09 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	init_vars_colors(int *red, int *green, int *blue)
{
	*red = 0;
	*green = 0;
	*blue = 0;
}

bool	get_red_color(int *red, char **array, t_data *data)
{
	if (ft_strcmp(array[0], "0") == 0)
		*red = 0;
	else
	{
		*red = ft_atoi(array[0]);
		if (!check_error_rgb_format(*red, data, array))
			return (false);
	}
	return (true);
}

bool	get_green_color(int *green, char **array, t_data *data)
{
	if (ft_strcmp(array[1], "0") == 0)
		*green = 0;
	else
	{
		*green = ft_atoi(array[1]);
		if (!check_error_rgb_format(*green, data, array))
			return (false);
	}
	return (true);
}

bool	get_blue_color(int *blue, char **array, t_data *data)
{
	if (ft_strcmp(array[2], "0") == 0)
		*blue = 0;
	else
	{
		*blue = ft_atoi(array[2]);
		if (!check_error_rgb_format(*blue, data, array))
			return (false);
	}
	return (true);
}
