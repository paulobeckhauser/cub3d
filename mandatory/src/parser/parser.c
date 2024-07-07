/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:08:00 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/07 15:25:58 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	parser(char *str, t_data *data)
{
	// t_data	data;

	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
	{
		replace_error_message(data, "Memory allocation failed");
		return (free_variables_error(data));
	}
	init_vars(data);
	if (!check_extension(data, str, "cub") || !store_cub_file(data, str)
		|| !store_surface_colors(data) || !store_textures(data)
		|| !store_map(data))
		return (free_variables_error(data));
	// free(data->player);
	// free(data->texture_north);
	// free(data->texture_south);
	// free(data->texture_east);
	// free(data->texture_west);
	// free_2d_array(data->map_element);
	// free_2d_array(data->cub_file);
	return (0);
}
