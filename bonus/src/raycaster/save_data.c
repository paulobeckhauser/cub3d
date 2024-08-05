/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:30:40 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:36:07 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	save_closest_distance(t_raycaster *raycaster, t_game *game)
{
	int	i;

	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].y == (int)raycaster->colis_y
			&& game->door[i].x == (int)raycaster->colis_x)
			break ;
		++i;
	}
	if (game->depth[game->depth_lvl].dist > 0
		&& game->depth[game->depth_lvl].dist < game->prev_door_distance)
	{
		game->door[i].dist = game->depth[game->depth_lvl].dist;
		game->prev_door_distance = game->depth[game->depth_lvl].dist;
	}
}

void	save_object_wall(t_raycaster *raycaster, t_game *game, float ray_angle)
{
	set_ray_direction(raycaster, &game->wall_direction);
	calc_ray_distance(raycaster, game, ray_angle,
		&game->depth[game->depth_lvl].dist);
	game->depth[game->depth_lvl].ray_hit_x = fmodf(raycaster->x_iterator,
			SQUARE_SIZE) / SQUARE_SIZE;
	game->depth[game->depth_lvl].ray_hit_y = fmodf(raycaster->y_iterator,
			SQUARE_SIZE) / SQUARE_SIZE;
	game->depth[game->depth_lvl].obj = WALL;
	++game->depth_lvl;
	raycaster->found_wall = true;
}

void	save_object_door(t_raycaster *raycaster, t_game *game, float ray_angle)
{
	set_ray_direction(raycaster, &game->door_direction);
	calc_ray_distance(raycaster, game, ray_angle,
		&game->depth[game->depth_lvl].dist);
	save_closest_distance(raycaster, game);
	game->depth[game->depth_lvl].ray_hit_x = fmodf(raycaster->x_iterator,
			SQUARE_SIZE) / SQUARE_SIZE;
	game->depth[game->depth_lvl].ray_hit_y = fmodf(raycaster->y_iterator,
			SQUARE_SIZE) / SQUARE_SIZE;
	game->depth[game->depth_lvl].obj = DOOR;
	game->depth[game->depth_lvl].colis_x = (int)raycaster->colis_x;
	game->depth[game->depth_lvl].colis_y = (int)raycaster->colis_y;
	++game->depth_lvl;
}

void	save_object_enemy(t_raycaster *raycaster, t_game *game, float ray_angle)
{
	int	i;

	calc_ray_distance(raycaster, game, ray_angle,
		&game->depth[game->depth_lvl].dist);
	game->depth[game->depth_lvl].obj = ENEMY;
	game->depth[game->depth_lvl].colis_x = (int)raycaster->colis_x;
	game->depth[game->depth_lvl].colis_y = (int)raycaster->colis_y;
	i = 0;
	while (i < ENEMY_MAX)
	{
		if ((int)raycaster->colis_y == game->enemy[i].y
			&& game->enemy[i].size == 0
			&& (int)raycaster->colis_x == game->enemy[i].x)
		{
			calc_enemy_data_relative_to_player(game, ray_angle, i);
			break ;
		}
		++i;
	}
	++game->depth_lvl;
}
