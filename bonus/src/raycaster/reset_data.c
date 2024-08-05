/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:23:20 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:26:34 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	reset_objects_data(t_game *game)
{
	game->prev_door_distance = INFINITY;
	game->enemy_visible = false;
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->depth_lvl < DEPTH_MAX)
	{
		game->dist_idx = 0;
		while (game->dist_idx < SCREEN_WIDTH)
			game->enemy[game->depth_lvl].hit_body[game->dist_idx++] = false;
		game->depth[game->depth_lvl].dist = 0;
		game->depth[game->depth_lvl].obj = EMPTY;
		game->depth[game->depth_lvl].ray_hit_x = 0;
		game->depth[game->depth_lvl].ray_hit_y = 0;
		game->depth[game->depth_lvl].colis_y = 0;
		game->depth[game->depth_lvl].colis_x = 0;
		game->door[game->depth_lvl].dist = -1;
		game->enemy[game->depth_lvl].size = 0;
		game->enemy[game->depth_lvl].x_start = 0;
		game->enemy[game->depth_lvl].x_end = 0;
		game->enemy[game->depth_lvl].tex_x = 0;
		game->enemy[game->depth_lvl++].visible = false;
	}
	game->depth_lvl = 0;
	game->dist_idx = 0;
}

void	reset_depth_data(t_game *game)
{
	game->depth_lvl = 0;
	while (game->depth_lvl < DEPTH_MAX)
	{
		game->depth[game->depth_lvl].dist = 0;
		game->depth[game->depth_lvl].obj = EMPTY;
		game->depth[game->depth_lvl].ray_hit_x = 0;
		game->depth[game->depth_lvl].ray_hit_y = 0;
		game->depth[game->depth_lvl].colis_y = 0;
		game->depth[game->depth_lvl++].colis_x = 0;
	}
	game->depth_lvl = 0;
}

void	init_raycaster_data(t_raycaster *raycaster, t_game *game,
		float ray_new_x, float ray_new_y)
{
	raycaster->dir_x = ray_new_x - game->data.player->x;
	raycaster->dir_y = ray_new_y - game->data.player->y;
	raycaster->len = sqrtf(raycaster->dir_x * raycaster->dir_x
			+ raycaster->dir_y * raycaster->dir_y);
	raycaster->dir_x /= raycaster->len;
	raycaster->dir_y /= raycaster->len;
	raycaster->x_iterator = game->data.player->x;
	raycaster->y_iterator = game->data.player->y;
	raycaster->speed = 1;
	raycaster->colis_x = 0;
	raycaster->colis_y = 0;
	raycaster->prev_colis_x = 0;
	raycaster->prev_colis_y = 0;
	raycaster->found_wall = false;
}
