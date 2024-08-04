/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:10:02 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 13:06:38 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	calc_dir_vectors(t_game *game)
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

int	find_enemy(t_game *game)
{
	int	i;

	i = ENEMY_MAX - 1;
	while (i >= 0)
	{
		if (game->depth[game->depth_lvl].colis_x == game->enemy[i].x
			&& game->depth[game->depth_lvl].colis_y == game->enemy[i].y)
		{
			if (game->depth_lvl == 0)
				game->enemy_visible = true;
			return (i);
		}
		--i;
	}
	return (i);
}

void	render_vertical(t_game *game)
{
	while (game->depth_lvl >= 0)
	{
		if (game->depth[game->depth_lvl].obj == WALL)
			render_wall_line(game);
		else if (game->depth[game->depth_lvl].obj == DOOR)
			render_door_line(game);
		else if (game->depth[game->depth_lvl].obj == ENEMY)
			render_enemy_line(game, find_enemy(game));
		--game->depth_lvl;
	}
}

float	fix_angle_overflow(float angle_iter)
{
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	return (angle_iter);
}

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
		game->ray_new_x = game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
		cast_ray(game, angle_iter);
		render_vertical(game);
		angle_iter += to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
		angle_iter = fix_angle_overflow(angle_iter);
		++game->dist_idx;
	}
}

bool	is_ray_out_of_map(t_raycaster *raycaster, t_game *game)
{
	if (raycaster->colis_y < 0 || raycaster->colis_x < 0
		|| !game->data->map_element[(int)raycaster->colis_y]
		|| ft_strlen(game->data->map_element[(int)raycaster->colis_y])
		< (size_t)raycaster->colis_x
		|| !game->data->map_element[(int)raycaster->colis_y]
		[(int)raycaster->colis_x])
		return (true);
	return (false);
}

bool	is_direction_in_range(t_raycaster *raycaster, t_game *game)
{
	if (((raycaster->dir_x >= 0 && raycaster->x_iterator <= game->ray_new_x)
			|| (raycaster->dir_x < 0 && raycaster->x_iterator
				>= game->ray_new_x))
		&& ((raycaster->dir_y >= 0 && raycaster->y_iterator <= game->ray_new_y)
			|| (raycaster->dir_y < 0
				&& raycaster->y_iterator >= game->ray_new_y)))
		return (true);
	return (false);
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

void	calc_enemy_data_relative_to_player(t_game *game, float ray_angle, int i)
{
	int	y;

	game->enemy[i].x_start = game->dist_idx;
	game->enemy[i].x_end = find_enemy_end(game, ray_angle, i);
	game->enemy[i].size = game->enemy[i].x_end - game->enemy[i].x_start;
	game->enemy[i].visible = true;
	if (game->enemy[i].x_start < 0)
	{
		y = 0;
		while (y < game->enemy[i].x_start * -1)
		{
			game->enemy[i].tex_x += (float)TEXTURE_SIZE_DEFAULT
				/ (float)game->enemy[i].size;
			++y;
		}
	}
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

bool	is_coll_point_same(t_raycaster *raycaster)
{
	if ((int)raycaster->colis_y != raycaster->prev_colis_y
		|| (int)raycaster->colis_x != raycaster->prev_colis_x)
		return (false);
	return (true);
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
		ray_new_x = game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		ray_new_y = game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
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
		ray_new_x = game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		ray_new_y = game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
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
				|| !game->data->map_element[(int)raycaster.colis_y]
				|| ft_strlen(game->data->map_element[(int)raycaster.colis_y])
				< (size_t)raycaster.colis_x
				|| !game->data->map_element[(int)raycaster.colis_y]
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
