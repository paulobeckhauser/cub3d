/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:29:20 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:35:32 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	calc_collision_point_x_y(t_raycaster *raycaster)
{
	if (raycaster->dir_x > 0)
		raycaster->colis_x = raycaster->x_iterator / SQUARE_SIZE;
	else
		raycaster->colis_x = (raycaster->x_iterator - 1) / SQUARE_SIZE;
	if (raycaster->dir_y > 0)
		raycaster->colis_y = raycaster->y_iterator / SQUARE_SIZE;
	else
		raycaster->colis_y = (raycaster->y_iterator - 1) / SQUARE_SIZE;
}

bool	is_collision_point_wall(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0
		&& (int)raycaster->colis_y < game->data.number_lines_map_element
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x]
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x] == '1')
		return (true);
	return (false);
}

bool	is_collision_point_door(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0
		&& (int)raycaster->colis_y < game->data.number_lines_map_element
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x]
		&& (game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '2'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '3'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '6'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '7'))
		return (true);
	return (false);
}

bool	is_collision_point_enemy(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0
		&& (int)raycaster->colis_y < game->data.number_lines_map_element
		&& game->data.map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x]
		&& (game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '4'
			|| game->data.map_element[(int)raycaster->colis_y]
			[(int)raycaster->colis_x] == '5'))
		return (true);
	return (false);
}

bool	is_coll_point_same(t_raycaster *raycaster)
{
	if ((int)raycaster->colis_y != raycaster->prev_colis_y
		|| (int)raycaster->colis_x != raycaster->prev_colis_x)
		return (false);
	return (true);
}
