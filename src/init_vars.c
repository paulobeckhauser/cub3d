/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:53:43 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/19 20:48:23 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_vars(t_data *data)
{
	data->cub_file = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->number_lines_map = 0;
	data->map_error_message = NULL;
	data->number_lines_map_element = 0;
	data->map_element = NULL;
	data->line_start_map_position = 0;
	data->line_end_map_position = 0;
	data->player->direction = '\0';
	data->player->x = 0;
	data->player->y = 0;
	data->text_count_n = 0;
	data->s_text_count = 0;
	data->w_text_count = 0;
	data->e_text_count = 0;
	data->floor_color_count = 0;
	data->ceiling_color_count = 0;
}
