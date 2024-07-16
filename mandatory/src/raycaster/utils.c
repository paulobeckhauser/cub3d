/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:18:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 15:29:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

float	to_radians(float degrees)
{
	return (degrees * (M_PI / 180));
}

void	calc_directions(t_raycaster *raycaster, t_game *game)
{
	raycaster->dir_x = game->ray_new_x - (float)game->data->player->x;
	raycaster->dir_y = game->ray_new_y - (float)game->data->player->y;
	raycaster->len = sqrtf(raycaster->dir_x * raycaster->dir_x
			+ raycaster->dir_y * raycaster->dir_y);
	raycaster->dir_x /= raycaster->len;
	raycaster->dir_y /= raycaster->len;
}

bool	is_ray_on_square_edge(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->x_iterator % (int)game->square_size == 0
		|| (int)raycaster->y_iterator % (int)game->square_size == 0)
		return (true);
	return (false);
}

int	get_pixel_color(void *img_ptr, int x, int y)
{
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (*(int *)(data + ((x + y * size_line / 4) * bits_per_pixel / 8)));
}
