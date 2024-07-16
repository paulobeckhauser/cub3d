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

void    calc_collision_point_x_y(t_raycaster *raycaster, t_game *game)
{
	if (raycaster->dir_x > 0)
		raycaster->colis_x = raycaster->x_iterator / game->square_size;
	else
		raycaster->colis_x = (raycaster->x_iterator - 1) / game->square_size;
	if (raycaster->dir_y > 0)
		raycaster->colis_y = raycaster->y_iterator / game->square_size;
	else
		raycaster->colis_y = (raycaster->y_iterator - 1) / game->square_size;
}

bool    is_collision_point_wall(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '1')
		return (true);
	return (false);
}

bool    is_collision_point_closed_door(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '2')
	{
		game->closed_door_visible = true;
		game->hit_closed_door = true;
		game->hit_opened_door = false;
		return (true);
	}
	return (false);
}

bool    is_collision_point_opened_door(t_raycaster *raycaster, t_game *game)
{
	
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == '3')
	{
		game->open_door_visible = true;
		game->hit_opened_door = true;
		game->hit_closed_door = false;
		return (true);
	}
	return (false);
}

bool    is_collision_point_enemy(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->colis_y >= 0 && (int)raycaster->colis_y < game->data->number_lines_map_element && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x]
	    && game->data->map_element[(int)raycaster->colis_y][(int)raycaster->colis_x] == 'E')
	{
		game->enemy_visible = true;
		game->enemy_x = (int)raycaster->colis_x;
		game->enemy_y = (int)raycaster->colis_y;
		game->hit_enemy = true;
		return (true);
	}
	return (false);
}

void    set_ray_direction(t_raycaster *raycaster, t_game *game, int *direction)
{
	if ((int)raycaster->x_iterator % (int)game->square_size == 0
	    && (int)raycaster->y_iterator % (int)game->square_size == 0)
		return ;
	if ((int)raycaster->x_iterator % (int)game->square_size == 0)
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

// void set_enemy_direction(t_raycaster *raycaster, t_game *game)
// {
	// double dx = game->data->player->x - raycaster->colis_x;
	// double dy = game->data->player->y - raycaster->colis_y;
	// double angle = atan2(dy, dx);
	
	// double angle_degrees = angle * 180 / M_PI;
	
	// if (angle_degrees < 0)
		// angle_degrees += 360;
	
	// game->enemy_direction = (int)round(angle_degrees / 45) % 8;
// }

void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle, float *dist)
{
	float raw_dist;
	
	raw_dist = sqrtf(powf(raycaster->colis_x
	                    * game->square_size - game->data->player->x, 2)
	                + powf(raycaster->colis_y
	                      * game->square_size - game->data->player->y, 2));
	*dist = raw_dist * cosf(ray_angle - to_radians(game->ray_main_angle));
}

void    save_closest_distance(float dist, float *prev_dist, float *closest_dist)
{
	if (dist > 0 && dist < *prev_dist)
	{
		*closest_dist = dist;
		*prev_dist = dist;
	}
}
