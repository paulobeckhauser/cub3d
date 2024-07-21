/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:10:02 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 15:10:03 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void    calc_dir_vectors(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;
	
	angle_incr_radians = to_radians(4);
	angle_iter = to_radians(game->ray_main_angle);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	game->vec_idx = 0;
	while (game->vec_idx < 90)
	{
		game->vectors[game->vec_idx].x = cosf(angle_iter);
		game->vectors[game->vec_idx].y = sinf(angle_iter);
		game->vec_idx++;
		angle_iter += angle_incr_radians;
		if (angle_iter >= 2 * M_PI)
			angle_iter -= 2 * M_PI;
	}
	game->vec_idx = 0;
}

void	raycaster(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;
	float	dir_x;
	float	dir_y;

	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
	angle_iter = to_radians(game->ray_main_angle) - to_radians(30.0f);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	dir_x = 0;
	dir_y = 0;
	game->door_visible = false;
	game->prev_door_distance = INFINITY;
	game->closest_door_distance = 0;
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	game->enemy_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->depth_lvl < 30)
	{
		while (game->dist_idx < SCREEN_WIDTH)
		{
			game->depth[game->depth_lvl].dist = 0;
			game->body_hit[game->depth_lvl][game->dist_idx++] = false;
		}
		game->door[game->depth_lvl].dist = 0;
		game->depth[game->depth_lvl].obj = EMPTY;
		++game->depth_lvl;
	}
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		game->depth_lvl = 0;
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
		cast_ray(game, angle_iter);
		while (game->depth_lvl >= 0)
		{
			if (game->depth[game->depth_lvl].obj == WALL)
				render_wall_line(game);
			else if (game->depth[game->depth_lvl].obj == DOOR)
				render_door_line(game);
//			else if (game->depth[game->depth_lvl].obj == ENEMY)
//				render_enemy_line(game);
            --game->depth_lvl;
		}
		angle_iter += angle_incr_radians;
		if (angle_iter < 0)
			angle_iter += 2 * M_PI;
		else if (angle_iter > 2 * M_PI)
			angle_iter -= 2 * M_PI;
		++game->dist_idx;
	}
//	if (game->hit_enemy)
//		render_enemy(game);
}


void    cast_ray(t_game *game, float ray_angle)
{
	t_raycaster raycaster;
	
	calc_directions(&raycaster, game);
	raycaster.x_iterator = game->data->player->x;
	raycaster.y_iterator = game->data->player->y;
	raycaster.speed = 1;
	while (((raycaster.dir_x >= 0 && raycaster.x_iterator <= game->ray_new_x)
	        || (raycaster.dir_x < 0 && raycaster.x_iterator >= game->ray_new_x))
	       && ((raycaster.dir_y >= 0 && raycaster.y_iterator <= game->ray_new_y)
	           || (raycaster.dir_y < 0 && raycaster.y_iterator >= game->ray_new_y)))
	{
		if (is_ray_on_square_edge(&raycaster, game))
		{
			calc_collision_point_x_y(&raycaster, game);
			if (raycaster.colis_y < 0 || raycaster.colis_x < 0 || !game->data->map_element[(int)raycaster.colis_y]
			    || !game->data->map_element[(int)raycaster.colis_y][(int)raycaster.colis_x])
				return ;
			if (is_collision_point_wall(&raycaster, game))
			{
				set_ray_direction(&raycaster, game, &game->wall_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->depth[game->depth_lvl].dist);
				game->depth[game->depth_lvl].ray_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->depth[game->depth_lvl].ray_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
				game->depth[game->depth_lvl].obj = WALL;
				return ;
			}
			if (is_collision_point_door(&raycaster, game))
			{
				set_ray_direction(&raycaster, game, &game->door_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->depth[game->depth_lvl].dist);
				save_closest_distance(&raycaster, game);
				game->depth[game->depth_lvl].ray_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->depth[game->depth_lvl].ray_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
				game->depth[game->depth_lvl].obj = DOOR;
				++game->depth_lvl;
			}
			if (is_collision_point_enemy(&raycaster, game))
			{
				calc_ray_distance(&raycaster, game, ray_angle, &game->depth[game->depth_lvl].dist);
				game->depth[game->depth_lvl].obj = ENEMY;
				++game->depth_lvl;
			}
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}

//
//void    cast_ray(t_game *game, float ray_angle)
//{
//	t_raycaster raycaster;
//
//	game->found_wall = false;
//	game->found_door = false;
//	calc_directions(&raycaster, game);
//	raycaster.x_iterator = game->data->player->x;
//	raycaster.y_iterator = game->data->player->y;
//	raycaster.speed = 1;
//	while (((raycaster.dir_x >= 0 && raycaster.x_iterator <= game->ray_new_x)
//	        || (raycaster.dir_x < 0 && raycaster.x_iterator >= game->ray_new_x))
//	       && ((raycaster.dir_y >= 0 && raycaster.y_iterator <= game->ray_new_y)
//	           || (raycaster.dir_y < 0 && raycaster.y_iterator >= game->ray_new_y)))
//	{
//		if (is_ray_on_square_edge(&raycaster, game))
//		{
//			calc_collision_point_x_y(&raycaster, game);
//			if (raycaster.colis_y < 0 || raycaster.colis_x < 0 || !game->data->map_element[(int)raycaster.colis_y]
//				|| !game->data->map_element[(int)raycaster.colis_y][(int)raycaster.colis_x]) {
//				return ;
//			}
//			if (is_collision_point_wall(&raycaster, game) && !game->found_wall)
//			{
//				set_ray_direction(&raycaster, game, &game->wall_direction);
//				calc_ray_distance(&raycaster, game, ray_angle, &game->wall_dists[game->depth_lvl][game->dist_idx]);
//				game->ray_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
//				game->ray_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
////				return ;
//				game->found_wall = true;
//			}
//			if (is_collision_point_closed_door(&raycaster, game))
//			{
//				set_ray_direction(&raycaster, game, &game->door_direction);
//				calc_ray_distance(&raycaster, game, ray_angle, &game->door_dists[game->depth_lvl][game->dist_idx]);
//				save_closest_distance(game->door_dists[game->depth_lvl][game->dist_idx], &game->prev_door_distance, &game->closest_door_distance);
//				game->ray_door_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
//				game->ray_door_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
//				game->found_door = true;
//			}
//			if (is_collision_point_opened_door(&raycaster, game))
//			{
//				set_ray_direction(&raycaster, game, &game->door_direction);
//				calc_ray_distance(&raycaster, game, ray_angle, &game->door_dists[game->depth_lvl][game->dist_idx]);
//				save_closest_distance(game->door_dists[game->depth_lvl][game->dist_idx], &game->prev_door_distance, &game->closest_door_distance);
//				game->ray_door_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
//				game->ray_door_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
//				game->found_door = true;
//			}
//			if (is_collision_point_enemy(&raycaster, game))
//			{
//				calc_ray_distance(&raycaster, game, ray_angle, &game->enemy_dists[game->depth_lvl][game->dist_idx]);
//			}
//		}
//		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
//		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
//	}
//}
