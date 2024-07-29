/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:19:39 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:19:40 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void    calc_collision_point_x_y(t_raycaster *raycaster)
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

bool    is_collision_point_wall(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '1')
		return (true);
	return (false);
}

bool    is_collision_point_door(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && (game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '2' || game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '3'))
		return (true);
	return (false);
}

bool    is_collision_point_enemy(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && (game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '4' || game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '5'))
	{
		if (!game->x_enemy_start)
			game->x_enemy_start = game->dist_idx;
		if (game->dist_idx > game->x_enemy_end)
			game->x_enemy_end = game->dist_idx;
		game->enemy_x = (int)raycaster->colis_x;
		game->enemy_y = (int)raycaster->colis_y;
		game->hit_enemy = true;
		return (true);
	}
	return (false);
}

void    set_ray_direction(t_raycaster *raycaster, int *direction)
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

void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle, float *dist)
{
	float raw_dist;
	
	raw_dist = sqrtf(powf(raycaster->colis_x
	                    * SQUARE_SIZE - game->data->player->x, 2)
	                + powf(raycaster->colis_y
	                      * SQUARE_SIZE - game->data->player->y, 2));
	*dist = raw_dist * cosf(ray_angle - to_radians(game->ray_main_angle));
}

void    save_closest_distance(t_raycaster *raycaster, t_game *game)
{
	int i;
	
	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].y == (int)raycaster->colis_y && game->door[i].x == (int)raycaster->colis_x)
			break ;
		++i;
	}
	if (game->depth[game->depth_lvl].dist > 0 && game->depth[game->depth_lvl].dist < game->prev_door_distance)
	{
		game->door[i].dist = game->depth[game->depth_lvl].dist;
		game->prev_door_distance = game->depth[game->depth_lvl].dist;
	}
}