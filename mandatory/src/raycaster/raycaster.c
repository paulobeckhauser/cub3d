/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:10:02 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 13:02:46 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	calc_dir_vectors(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;

	angle_incr_radians = to_radians(3);
	angle_iter = to_radians(game->ray_main_angle);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	game->vec_idx = 0;
	while (game->vec_idx < 120)
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

void	get_new_ray_values(t_game *game, float angle_incr_radians,
		float angle_iter)
{
	float	dir_x;
	float	dir_y;

	dir_x = 0;
	dir_y = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = (float)game->data->player->x + dir_x * 2
			* SCREEN_WIDTH;
		game->ray_new_y = (float)game->data->player->y + dir_y * 2
			* SCREEN_WIDTH;
		cast_ray(game, angle_iter);
		render_wall_line(game);
		angle_iter += angle_incr_radians;
		if (angle_iter < 0)
			angle_iter += 2 * M_PI;
		else if (angle_iter > 2 * M_PI)
			angle_iter -= 2 * M_PI;
		++game->dist_idx;
	}
}

void	raycaster(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;
	int		i;

	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
	angle_iter = to_radians(game->ray_main_angle) - to_radians(30.0f);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	game->dist_idx = 0;
	i = 0;
	while (i < SCREEN_WIDTH)
		game->wall_dists[i++] = 0;
	get_new_ray_values(game, angle_incr_radians, angle_iter);
}

void	cast_ray_support(t_game *game, float ray_angle, t_raycaster raycaster)
{
	set_ray_direction(&raycaster, game, &game->wall_direction);
	calc_ray_distance(&raycaster, game, ray_angle,
		&game->wall_dists[game->dist_idx]);
	game->ray_hit_x = fmodf(raycaster.x_iterator, game->square_size)
		/ game->square_size;
	game->ray_hit_y = fmodf(raycaster.y_iterator, game->square_size)
		/ game->square_size;
}

void	cast_ray(t_game *game, float ray_angle)
{
	t_raycaster	raycaster;

	calc_directions(&raycaster, game);
	raycaster.x_iterator = (float)game->data->player->x;
	raycaster.y_iterator = (float)game->data->player->y;
	raycaster.speed = 1;
	while (true)
	{
		if (is_ray_on_square_edge(&raycaster, game))
		{
			calc_collision_point_x_y(&raycaster, game);
			if (is_collision_point_wall(&raycaster, game))
			{
				cast_ray_support(game, ray_angle, raycaster);
				return ;
			}
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}
