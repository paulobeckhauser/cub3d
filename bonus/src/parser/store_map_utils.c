/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:03:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 22:10:32 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	store_first_line_map_element(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub_file[i])
	{
		if (check_if_map_element(data->cub_file[i])
			&& !check_if_empty_line(data->cub_file[i]))
		{
			data->line_start_map_position = i;
			break ;
		}
		i++;
	}
}

void	store_last_line_map_element(t_data *data)
{
	int	i;

	i = data->line_start_map_position;
	while (data->cub_file[i])
	{
		if (check_if_empty_line(data->cub_file[i]))
		{
			data->line_end_map_position = i - 1;
			break ;
		}
		i++;
	}
	data->line_end_map_position = i - 1;
}
