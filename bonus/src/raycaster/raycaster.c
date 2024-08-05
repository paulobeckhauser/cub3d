/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:10:02 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:39:07 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	raycaster(t_game *game)
{
	float			angle_iter;
	float			dir_x;
	float			dir_y;

	angle_iter = to_radians(game->ray_main_angle) - to_radians(FIELD_OF_VIEW
			/ 2);
	angle_iter = fix_angle_overflow(angle_iter);
	reset_objects_data(game);
	while (game->dist_idx < SCREEN_WIDTH)
	{
		reset_depth_data(game);
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = game->data.player->x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->data.player->y + dir_y * 2 * SCREEN_WIDTH;
		cast_ray(game, angle_iter);
		render_vertical(game);
		angle_iter += to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
		angle_iter = fix_angle_overflow(angle_iter);
		++game->dist_idx;
	}
}

void	cast_ray(t_game *game, float ray_angle)
{
	t_raycaster	raycaster;

	init_raycaster_data(&raycaster, game, game->ray_new_x, game->ray_new_y);
	while (is_direction_in_range(&raycaster, game))
	{
		if (is_ray_on_square_edge(&raycaster))
		{
			calc_collision_point_x_y(&raycaster);
			if (is_ray_out_of_map(&raycaster, game))
				return ;
			else if (is_collision_point_wall(&raycaster, game)
				&& !is_coll_point_same(&raycaster) && !raycaster.found_wall)
				save_object_wall(&raycaster, game, ray_angle);
			else if (is_collision_point_door(&raycaster, game)
				&& !is_coll_point_same(&raycaster))
				save_object_door(&raycaster, game, ray_angle);
			else if (is_collision_point_enemy(&raycaster, game)
				&& !is_coll_point_same(&raycaster))
				save_object_enemy(&raycaster, game, ray_angle);
		}
		raycaster.prev_colis_x = (int)raycaster.colis_x;
		raycaster.prev_colis_y = (int)raycaster.colis_y;
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}

int	find_enemy_end(t_game *game, float angle_iter, int enemy_i)
{
	float	dir_x;
	float	dir_y;
	float	ray_new_x;
	float	ray_new_y;
	int		dist_idx;

	dist_idx = game->enemy[enemy_i].x_start;
	if (dist_idx == 0)
		game->enemy[enemy_i].x_start = find_enemy_start(game, angle_iter,
				enemy_i);
	while (true)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		ray_new_x = game->data.player->x + dir_x * 2 * SCREEN_WIDTH;
		ray_new_y = game->data.player->y + dir_y * 2 * SCREEN_WIDTH;
		if (!cast_ray_till_enemy(game, ray_new_x, ray_new_y, enemy_i))
			return (dist_idx);
		angle_iter += to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
		angle_iter = fix_angle_overflow(angle_iter);
		++dist_idx;
	}
}

int	find_enemy_start(t_game *game, float angle_iter, int enemy_i)
{
	float	dir_x;
	float	dir_y;
	float	ray_new_x;
	float	ray_new_y;
	int		dist_idx;

	dist_idx = game->dist_idx;
	while (true)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		ray_new_x = game->data.player->x + dir_x * 2 * SCREEN_WIDTH;
		ray_new_y = game->data.player->y + dir_y * 2 * SCREEN_WIDTH;
		if (!cast_ray_till_enemy(game, ray_new_x, ray_new_y, enemy_i))
			return (dist_idx);
		angle_iter -= to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
		angle_iter = fix_angle_overflow(angle_iter);
		--dist_idx;
	}
}

int	cast_ray_till_enemy(t_game *game, float ray_new_x, float ray_new_y,
		int enemy_i)
{
	t_raycaster	raycaster;

	init_raycaster_data(&raycaster, game, ray_new_x, ray_new_y);
	while (true)
	{
		if (is_ray_on_square_edge(&raycaster))
		{
			calc_collision_point_x_y(&raycaster);
			if (raycaster.colis_y < 0 || raycaster.colis_x < 0
				|| !game->data.map_element[(int)raycaster.colis_y]
				|| ft_strlen(game->data.map_element[(int)raycaster.colis_y])
				< (size_t)raycaster.colis_x
				|| !game->data.map_element[(int)raycaster.colis_y]
				[(int)raycaster.colis_x])
				return (0);
			if ((int)raycaster.colis_x == game->enemy[enemy_i].x
				&& (int)raycaster.colis_y == game->enemy[enemy_i].y)
				return (1);
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}
