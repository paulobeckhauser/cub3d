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

#include "../../incl/raycaster.h"

void    calc_dir_vectors(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;
	
	angle_incr_radians = to_radians(10.0f); //field of view (60 deg) divided by screen width
	angle_iter = to_radians(game->ray_angle);
	game->vec_idx = 0;
	while (game->vec_idx < 36)
	{
		game->vectors[game->vec_idx].x = cosf(angle_iter) * game->screen_aspect_ratio;
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

	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH); //field of view (60 deg) divided by screen width
	angle_iter = to_radians(game->ray_angle) - to_radians(30.0f);
	dir_x = 0;
	dir_y = 0;
	game->dist_idx = 0;
	while (game->dist_idx < (int)SCREEN_WIDTH)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = game->player_x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->player_y + dir_y * 2 * SCREEN_HEIGHT;
		cast_ray(game, angle_iter);
		draw_wall_line(game);
		angle_iter += angle_incr_radians;
		++game->dist_idx;
	}
}

void    cast_ray(t_game *game, float ray_angle)
{
	t_raycaster raycaster;
	
	calc_directions(&raycaster, game);
	raycaster.x_iterator = game->player_x;
	raycaster.y_iterator = game->player_y;
	raycaster.speed = 1;
	while (((raycaster.dir_x >= 0 && raycaster.x_iterator <= game->ray_new_x)
		|| (raycaster.dir_x < 0 && raycaster.x_iterator >= game->ray_new_x))
	       && ((raycaster.dir_y >= 0 && raycaster.y_iterator <= game->ray_new_y)
		|| (raycaster.dir_y < 0 && raycaster.y_iterator >= game->ray_new_y)))
	{
		if (is_ray_on_square_edge(&raycaster, game))
		{
			calc_collision_point_x_y(&raycaster, game);
			if (is_collision_point_a_wall(&raycaster, game))
			{
				set_ray_direction(&raycaster, game);
				calc_ray_distance(&raycaster, game, ray_angle);
				return ;
			}
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}
