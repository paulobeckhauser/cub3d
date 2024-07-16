/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:08:00 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 18:42:34 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	parser(char *str, t_data *data)
{
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
	return (0);
}
