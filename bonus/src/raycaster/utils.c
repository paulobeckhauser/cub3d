/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:18:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:18:02 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

float	to_radians(float degrees)
{
	return (degrees * (M_PI / (ANGLE_MAX / 2)));
}

void    calc_directions(t_raycaster *raycaster, t_game *game)
{
	raycaster->dir_x = game->ray_new_x - game->data->player->x;
	raycaster->dir_y = game->ray_new_y - game->data->player->y;
	raycaster->len = sqrtf(raycaster->dir_x * raycaster->dir_x + raycaster->dir_y * raycaster->dir_y);
	raycaster->dir_x /= raycaster->len;
	raycaster->dir_y /= raycaster->len;
}

bool    is_ray_on_square_edge(t_raycaster *raycaster)
{
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0
		|| (int)raycaster->y_iterator % SQUARE_SIZE == 0)
		return (true);
	return (false);
}

int get_pixel_color(void *img_ptr, int x, int y)
{
	char    *data;
	int     bits_per_pixel;
	int     size_line;
	int     endian;

	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (*(int *)(data + ((x + y * size_line / 4) * bits_per_pixel / 8)));
}