/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 21:14:55 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	init_vars_check_wall(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

bool	check_edges(int i, int j, t_data *data)
{
	if (i == 0 && check_first_line(i, j, data))
		return (true);
	if ((i == size_array(data->map_element) - 1) && (check_last_line(i, j,
				data)))
		return (true);
	return (false);
}

bool	return_error_wall(t_data *data)
{
	replace_error_message(data, "Map not surrounded by walls");
	return (false);
}
