/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:53:43 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/19 20:58:12 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_vars(t_data *data)
{
	data->color_ceiling = 0;
	data->color_ceiling_count = 0;
	data->color_floor = 0;
	data->color_floor_count = 0;
	data->cub_file = NULL;
	data->line_start_map_position = 0;
	data->line_end_map_position = 0;
	data->map_element = NULL;
	data->map_error_message = NULL;
	data->number_lines_map = 0;
	data->number_lines_map_element = 0;
	data->text_count_n = 0;
	data->text_count_s = 0;
	data->text_count_w = 0;
	data->text_count_e = 0;
	data->texture_north = NULL;
	data->texture_south = NULL;
	data->texture_west = NULL;
	data->texture_east = NULL;
	data->player->direction = '\0';
	data->player->x = 0;
	data->player->y = 0;
}
