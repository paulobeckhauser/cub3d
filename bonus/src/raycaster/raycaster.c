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
	
	angle_incr_radians = to_radians(ROTATION_SPEED);
	angle_iter = to_radians(game->ray_main_angle);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	game->vec_idx = 0;
	while (game->vec_idx < ANGLE_MAX / ROTATION_SPEED)
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
	int     i;

	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
	angle_iter = to_radians(game->ray_main_angle) - to_radians(FIELD_OF_VIEW / 2);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	dir_x = 0;
	dir_y = 0;
	game->prev_door_distance = INFINITY;
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	game->enemy_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->depth_lvl < DEPTH_MAX)
	{
		while (game->dist_idx < SCREEN_WIDTH)
		{
			game->body_hit[game->depth_lvl][game->dist_idx++] = false;
		}
		game->depth[game->depth_lvl].dist = 0;
		game->depth[game->depth_lvl].obj = EMPTY;
		game->depth[game->depth_lvl].ray_hit_x = 0;
		game->depth[game->depth_lvl].ray_hit_y = 0;
		game->depth[game->depth_lvl].colis_y = 0;
		game->depth[game->depth_lvl].colis_x = 0;
		game->door[game->depth_lvl].dist = 0;
		game->enemy[game->depth_lvl].size = 0;
		game->enemy[game->depth_lvl].x_start = 0;
		game->enemy[game->depth_lvl].x_end = 0;
		game->enemy[game->depth_lvl].tex_x = 0;
		game->enemy[game->depth_lvl].x_iter = 0;
		game->enemy[game->depth_lvl].found = false;
		++game->depth_lvl;
	}
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		game->depth_lvl = 0;
		while (game->depth_lvl < DEPTH_MAX)
		{
			game->depth[game->depth_lvl].dist = 0;
			game->depth[game->depth_lvl].obj = EMPTY;
			game->depth[game->depth_lvl].ray_hit_x = 0;
			game->depth[game->depth_lvl].ray_hit_y = 0;
			game->depth[game->depth_lvl].colis_y = 0;
			game->depth[game->depth_lvl].colis_x = 0;
			game->door[game->depth_lvl].dist = 0;
//			game->enemy[game->depth_lvl].size = 0;
//			game->enemy[game->depth_lvl].x_start = 0;
//			game->enemy[game->depth_lvl].x_end = 0;
//			game->enemy[game->depth_lvl].rendered = false;
			++game->depth_lvl;
		}
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
			else if (game->depth[game->depth_lvl].obj == ENEMY)
			{
				i = ENEMY_MAX - 1;
				while (i >= 0)
				{
//				    printf("%i ", game->depth_lvl);
//					printf("%i ", game->enemy[i].size);
					if (game->enemy[i].size) {
						break ;
					}
					--i;
				}
				render_enemy_line(game, i);
			}
            --game->depth_lvl;
		}
		angle_iter += angle_incr_radians;
		if (angle_iter < 0)
			angle_iter += 2 * M_PI;
		else if (angle_iter > 2 * M_PI)
			angle_iter -= 2 * M_PI;
		++game->dist_idx;
	}
}

void    cast_ray(t_game *game, float ray_angle)
{
	t_raycaster raycaster;
	
	calc_directions(&raycaster, game, game->ray_new_x, game->ray_new_y);
	raycaster.x_iterator = game->data->player->x;
	raycaster.y_iterator = game->data->player->y;
	raycaster.speed = 1;
	raycaster.prev_colis_x = 0;
	raycaster.prev_colis_y = 0;
	raycaster.found_wall = false;
	while (((raycaster.dir_x >= 0 && raycaster.x_iterator <= game->ray_new_x)
	        || (raycaster.dir_x < 0 && raycaster.x_iterator >= game->ray_new_x))
	       && ((raycaster.dir_y >= 0 && raycaster.y_iterator <= game->ray_new_y)
	           || (raycaster.dir_y < 0 && raycaster.y_iterator >= game->ray_new_y)))
	{
		if (is_ray_on_square_edge(&raycaster))
		{
			calc_collision_point_x_y(&raycaster);
			if (raycaster.colis_y < 0 || raycaster.colis_x < 0 || !game->data->map_element[(int)raycaster.colis_y]
			    || !game->data->map_element[(int)raycaster.colis_y][(int)raycaster.colis_x])
			{
				return ;
			}
			else if (is_collision_point_wall(&raycaster, game)
				&& ((int)raycaster.colis_y != raycaster.prev_colis_y
					|| (int)raycaster.colis_x != raycaster.prev_colis_x)
				&& !raycaster.found_wall)
			{
//				printf("idx: %i depth: %i\n", game->dist_idx, game->depth_lvl);
				set_ray_direction(&raycaster, &game->wall_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->depth[game->depth_lvl].dist);
				game->depth[game->depth_lvl].ray_hit_x = fmodf(raycaster.x_iterator, SQUARE_SIZE) / SQUARE_SIZE;
				game->depth[game->depth_lvl].ray_hit_y = fmodf(raycaster.y_iterator, SQUARE_SIZE) / SQUARE_SIZE;
				game->depth[game->depth_lvl].obj = WALL;
				++game->depth_lvl;
				raycaster.found_wall = true;
//				return ;
			}
			else if (is_collision_point_door(&raycaster, game)
				&& ((int)raycaster.colis_y != raycaster.prev_colis_y
					|| (int)raycaster.colis_x != raycaster.prev_colis_x))
			{
				set_ray_direction(&raycaster, &game->door_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->depth[game->depth_lvl].dist);
				save_closest_distance(&raycaster, game);
				game->depth[game->depth_lvl].ray_hit_x = fmodf(raycaster.x_iterator, SQUARE_SIZE) / SQUARE_SIZE;
				game->depth[game->depth_lvl].ray_hit_y = fmodf(raycaster.y_iterator, SQUARE_SIZE) / SQUARE_SIZE;
				game->depth[game->depth_lvl].obj = DOOR;
				game->depth[game->depth_lvl].colis_y = raycaster.colis_y;
				game->depth[game->depth_lvl].colis_x = raycaster.colis_x;
				++game->depth_lvl;
			}
			else if (is_collision_point_enemy(&raycaster, game)
				&& ((int)raycaster.colis_y != raycaster.prev_colis_y
					|| (int)raycaster.colis_x != raycaster.prev_colis_x))
			{
				calc_ray_distance(&raycaster, game, ray_angle, &game->depth[game->depth_lvl].dist);
				game->depth[game->depth_lvl].obj = ENEMY;
				int i = 0;
//				printf("idx: %i depth: %i\n", game->dist_idx, game->depth_lvl);
				while (i < ENEMY_MAX)
				{
					if ((int)raycaster.colis_y == game->enemy[i].y && (int)raycaster.colis_x == game->enemy[i].x
						&& game->enemy[i].size == 0 && !game->enemy[i].found)
					{
//						printf("colis_x: %f colis_y %f", raycaster.colis_x, raycaster.colis_y);
//						printf("raycaster: colis_x: %i colis_y %i ", (int)raycaster.colis_x, (int)raycaster.colis_y);
//						printf("game->dist_idx: %i ", i);
						game->enemy[i].x_start = game->dist_idx;
						game->enemy[i].x_iter = game->enemy[i].x_start;
						game->enemy[i].x_end = find_enemy_end(game, ray_angle);
						game->enemy[i].size = game->enemy[i].x_end - game->enemy[i].x_start;
						render_vertical_line(game->enemy[i].x_start, game, 0, 255, 0);
						render_vertical_line(game->enemy[i].x_end, game,255, 0, 0);
//						game->enemy[i].found = true;
//						printf("size: %i ", game->enemy[i].size);
						break ;
					}
					++i;
				}
				++game->depth_lvl;
			}
		}
		raycaster.prev_colis_x = (int)raycaster.colis_x;
		raycaster.prev_colis_y = (int)raycaster.colis_y;
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}

int	find_enemy_end(t_game *game, float angle_iter)
{
	float	angle_incr_radians;
	float	dir_x;
	float	dir_y;
	float   ray_new_x;
	float   ray_new_y;
	int     dist_idx;
	
	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
	dir_x = 0;
	dir_y = 0;
	dist_idx = game->dist_idx;
//	printf("game->dist_idx: %i ", game->dist_idx);
	while (dist_idx < SCREEN_WIDTH)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		ray_new_x = game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		ray_new_y = game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
		if (!cast_ray_till_enemy(game, ray_new_x, ray_new_y))
		{
//			printf("%s\n", game->str);
//			printf("dist_idx: %i\n", dist_idx);
			return (dist_idx);
		}
		angle_iter += angle_incr_radians;
		if (angle_iter < 0)
			angle_iter += 2 * M_PI;
		else if (angle_iter > 2 * M_PI)
			angle_iter -= 2 * M_PI;
		++dist_idx;
	}
	return (dist_idx);
}

int cast_ray_till_enemy(t_game *game, float ray_new_x, float ray_new_y)
{
	t_raycaster raycaster;
	int         depth_lvl;
	
	calc_directions(&raycaster, game, ray_new_x, ray_new_y);
	raycaster.x_iterator = game->data->player->x;
	raycaster.y_iterator = game->data->player->y;
	raycaster.prev_colis_x = 0;
	raycaster.prev_colis_y = 0;
	raycaster.speed = 1;
	depth_lvl = 0;
	while (1)
	{
		if (is_ray_on_square_edge(&raycaster))
		{
			calc_collision_point_x_y(&raycaster);
//			printf("colis_x: %f colis_y %f ", raycaster.colis_x, raycaster.colis_y);
//			printf("colis_x: %i colis_y %i ", (int)raycaster.colis_x, (int)raycaster.colis_y);
			if (raycaster.colis_y < 0 || raycaster.colis_x < 0 || !game->data->map_element[(int)raycaster.colis_y]
			    || !game->data->map_element[(int)raycaster.colis_y][(int)raycaster.colis_x])
			{
				game->str = "end";
//				printf("end\n");
				return 0;
			}
//			if (is_collision_point_wall(&raycaster, game)  && ((int)raycaster.colis_y != raycaster.prev_colis_y || (int)raycaster.colis_x != raycaster.prev_colis_x))
//			{
//				if (depth_lvl == game->depth_lvl)
//				{
//					return 0;
//				}
//				++depth_lvl;
//			}
//			if (is_collision_point_door(&raycaster, game) && ((int)raycaster.colis_y != raycaster.prev_colis_y || (int)raycaster.colis_x != raycaster.prev_colis_x))
//			{
//				if (depth_lvl == game->depth_lvl)
//				{
//					game->str = "door";
//					printf("door\n");
//					return 0;
//				}
//				++depth_lvl;
//			}
			if (is_collision_point_enemy(&raycaster, game) && ((int)raycaster.colis_y != raycaster.prev_colis_y || (int)raycaster.colis_x != raycaster.prev_colis_x))
			{
				if (depth_lvl - game->depth_lvl == -1 || game->depth_lvl - game->depth_lvl == 1 || game->depth_lvl == depth_lvl)
				{
//					printf("x: %i y: %i\n", (int)raycaster.colis_x, (int)raycaster.colis_y);
//					game->str = "enemy";
//					printf("enemy\n");
					return 1;
				}
				++depth_lvl;
			}
		}
		raycaster.prev_colis_x = (int)raycaster.colis_x;
		raycaster.prev_colis_y = (int)raycaster.colis_y;
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
	return (0);
}
