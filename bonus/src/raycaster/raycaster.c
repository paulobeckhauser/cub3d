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
	game->dist_idx = 0;
	game->closed_door_visible = false;
	game->open_door_visible = false;
	game->prev_door_distance = INFINITY;
	game->closest_door_distance = 0;
	game->prev_enemy_distance = INFINITY;
	game->closest_enemy_distance = 0;
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	game->enemy_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	for (int i=0; i < SCREEN_WIDTH; i++)
	{
		game->wall_dists[i] = 0;
		game->door_dists[i] = 0;
		game->enemy_dists[i] = 0;
		game->body_hit[i] = false;
	}
	while (game->dist_idx < SCREEN_WIDTH)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
		cast_ray(game, angle_iter);
		render_wall_line(game);
		if (game->hit_opened_door || game->hit_closed_door)
			render_door_line(game);
		if (game->hit_enemy)
			render_enemy_line(game);
		else
			game->first_enemy_dist = -1;
		angle_iter += angle_incr_radians;
		if (angle_iter < 0)
			angle_iter += 2 * M_PI;
		else if (angle_iter > 2 * M_PI)
			angle_iter -= 2 * M_PI;
		++game->dist_idx;
	}
	game->first_enemy_dist = -1;
//	if (game->hit_enemy)
		render_enemy(game);
}

void    render_enemy(t_game *game)
{
	int enemy_square_pixels_seen;
	int i;
	int current_square_size;
	
	enemy_square_pixels_seen = 0;
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		if (game->enemy_dists[i++] != 0)
			++enemy_square_pixels_seen;
	}
	current_square_size = (int)((SCREEN_WIDTH - SQUARE_SIZE) / game->closest_enemy_distance * SQUARE_SIZE);
	printf("enemy_square_pixels_seen: %i\n", enemy_square_pixels_seen);
	printf("distance: %i\n", (int)game->closest_enemy_distance);
	printf("calculated square size: %i\n", current_square_size);
}

void    cast_ray(t_game *game, float ray_angle)
{
	t_raycaster raycaster;
	
	game->found_wall = false;
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
			if (is_collision_point_wall(&raycaster, game) && !game->found_wall)
			{
				set_ray_direction(&raycaster, game, &game->wall_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->wall_dists[game->dist_idx]);
				game->ray_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
//				return ;
				game->found_wall = true;
			}
			if (is_collision_point_closed_door(&raycaster, game))
			{
				set_ray_direction(&raycaster, game, &game->door_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->door_dists[game->dist_idx]);
				save_closest_distance(game->door_dists[game->dist_idx], &game->prev_door_distance, &game->closest_door_distance);
				game->ray_door_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_door_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
			}
			if (is_collision_point_opened_door(&raycaster, game))
			{
				set_ray_direction(&raycaster, game, &game->door_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->door_dists[game->dist_idx]);
				save_closest_distance(game->door_dists[game->dist_idx], &game->prev_door_distance, &game->closest_door_distance);
				game->ray_door_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_door_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
			}
			if (is_collision_point_enemy(&raycaster, game))
			{
				// set_enemy_direction(&raycaster, game);
				calc_ray_distance(&raycaster, game, ray_angle, &game->enemy_dists[game->dist_idx]);
				save_closest_distance(game->enemy_dists[game->dist_idx], &game->prev_enemy_distance, &game->closest_enemy_distance);
				game->ray_enemy_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_enemy_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
			}
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}
