/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:25:00 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:40:30 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	is_ray_on_square_edge(t_raycaster *raycaster)
{
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0
		|| (int)raycaster->y_iterator % SQUARE_SIZE == 0)
		return (true);
	return (false);
}

bool	is_ray_out_of_map(t_raycaster *raycaster, t_game *game)
{
	if (raycaster->colis_y < 0 || raycaster->colis_x < 0
		|| !game->data.map_element[(int)raycaster->colis_y]
		|| ft_strlen(game->data.map_element[(int)raycaster->colis_y])
		< (size_t)raycaster->colis_x
		|| !game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x])
		return (true);
	return (false);
}

void	set_ray_direction(t_raycaster *raycaster, int *direction)
{
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0
		&& (int)raycaster->y_iterator % SQUARE_SIZE == 0)
		return ;
	if ((int)raycaster->x_iterator % SQUARE_SIZE == 0)
	{
		if (raycaster->dir_x >= 0)
			*direction = EAST;
		else
			*direction = WEST;
	}
	else
	{
		if (raycaster->dir_y >= 0)
			*direction = SOUTH;
		else
			*direction = NORTH;
	}
}

void	calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle,
		float *dist)
{
	float	raw_dist;

	raw_dist = sqrtf(powf(raycaster->colis_x * SQUARE_SIZE
				- game->data.player->x, 2) + powf(raycaster->colis_y
				* SQUARE_SIZE - game->data.player->y, 2));
	*dist = raw_dist * cosf(ray_angle
			- to_radians(game->ray_main_angle));
}
