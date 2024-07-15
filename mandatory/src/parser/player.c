/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:17:16 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 18:25:09 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	check_number_player(t_data *data, int count_player)
{
	if (count_player == 0)
	{
		replace_error_message(data, "No player in the map");
		return (false);
	}
	else if (count_player > 1)
	{
		replace_error_message(data, "More than one player in the map");
		return (false);
	}
	return (true);
}

bool	count_player(t_data *data)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	j = 0;
	count_player = 0;
	while (data->map_element[i])
	{
		j = 0;
		while (data->map_element[i][j])
		{
			if (data->map_element[i][j] == 'N' || data->map_element[i][j] == 'S'
				|| data->map_element[i][j] == 'W'
				|| data->map_element[i][j] == 'E')
			{
				count_player++;
			}
			j++;
		}
		i++;
	}
	if (!check_number_player(data, count_player))
		return (false);
	return (true);
}

void	replace_player_for_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_element[i])
	{
		j = 0;
		while (data->map_element[i][j])
		{
			if (data->map_element[i][j] == 'N' || data->map_element[i][j] == 'S'
				|| data->map_element[i][j] == 'W'
				|| data->map_element[i][j] == 'E')
			{
				data->player->x = (float)j * 100 + 100 / 2;
				data->player->y = (float)i * 100 + 100 / 2;
				data->player->direction = data->map_element[i][j];
				data->map_element[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

bool	check_player(t_data *data)
{
	if (!count_player(data))
		return (false);
	replace_player_for_floor(data);
	return (true);
}
