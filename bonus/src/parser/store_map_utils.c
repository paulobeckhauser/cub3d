/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:03:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 20:05:26 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: store_first_line_map_element
 * ---------------------------------------
 * Identifies and stores the index of the first line of the map in the game data.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function iterates through the lines of the game file stored in data.
 * It checks each line to determine if it is a map element and not an empty line.
 * The index of the first such line is stored in data->line_start_map_position.
 */
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

/* Function: store_last_line_map_element
 * --------------------------------------
 * Identifies and stores the index of the last line of the map in the game data.
 * 
 * data: A pointer to the game data structure.
 * 
 * Starting from the index stored in data->line_start_map_position,
 * this function iterates through the lines of the game file.
 * It looks for the first empty line after the start of the map,
 * indicating the end of the map. The index of the line just before this empty line
 * is stored in data->line_end_map_position. If no empty line is found,
 * the last line of the map is assumed to be the last line with content.
 */
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
