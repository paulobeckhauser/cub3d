/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:51:44 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 20:05:17 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	check_if_map_element(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'W' || str[i] == 'E' || (str[i] >= 9
				&& str[i] <= 13))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_if_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_map_last_element(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = data->line_end_map_position + 1;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (data->cub_file[i][j] != ' ')
			{
				replace_error_message(data, "Map element in wrong format");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_element_input(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = data->line_start_map_position + 1;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (data->cub_file[i][j] != '0' && data->cub_file[i][j] != '1'
			    && data->cub_file[i][j] != ' ' && data->cub_file[i][j] != 'N'
			    && data->cub_file[i][j] != 'S' && data->cub_file[i][j] != 'E'
			    && data->cub_file[i][j] != 'W' && data->cub_file[i][j] != '2'
			    && data->cub_file[i][j] != '3' && data->cub_file[i][j] != '4'
			    && data->cub_file[i][j] != '6'
			    && (data->cub_file[i][j] < 9
			        || data->cub_file[i][j] > 13))
			{
				replace_error_message(data, "Map element in wrong format");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_empty_line_map(t_data *data)
{
	int	i;

	i = data->line_start_map_position;
	while (i < data->line_end_map_position)
	{
		if (check_if_empty_line(data->cub_file[i]))
		{
			replace_error_message(data, "Map element in wrong format");
			return (false);
		}
		i++;
	}
	return (true);
}
