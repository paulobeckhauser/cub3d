/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:38:29 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 21:20:17 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	check_last_line(int i, int j, t_data *data)
{
	int	col;

	col = i;
	while (data->map_element[col][j])
	{
		if (data->map_element[col][j] == '1')
			break ;
		else if (data->map_element[col][j] == ' ')
		{
			col--;
			continue ;
		}
		else
		{
			replace_error_message(data, "Map not surrounded by walls");
			return (false);
		}
		col--;
	}
	return (true);
}

bool	check_first_line(int i, int j, t_data *data)
{
	int	col;

	if (i == 0)
	{
		col = i;
		while (data->map_element[col][j])
		{
			if (data->map_element[col][j] == '1')
				break ;
			else if (data->map_element[col][j] == ' ')
			{
				col++;
				continue ;
			}
			else
			{
				replace_error_message(data, "Map not surrounded by walls");
				return (false);
			}
			col++;
		}
	}
	return (true);
}

bool	check_spaces(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map_element[i][j])
	{
		if (data->map_element[i][j] == '1')
		{
			j++;
			continue ;
		}
		else if (data->map_element[i][j] == ' ' || (data->map_element[i][j] >= 9
				&& data->map_element[i][j] <= 13))
			return (check_edges(i, j, data));
		else
			return (return_error_wall(data));
		j++;
	}
	return (true);
}

bool	check_wall(t_data *data)
{
	int	i;
	int	j;

	init_vars_check_wall(&i, &j);
	while (data->map_element[i])
	{
		if (i == 0 || i == size_array(data->map_element) - 1)
		{
			if (!check_spaces(data, i))
				return (false);
		}
		i++;
	}
	return (true);
}
