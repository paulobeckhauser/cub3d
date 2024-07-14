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
	
	angle_incr_radians = to_radians(10.0f);
	angle_iter = to_radians(game->ray_main_angle);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	game->vec_idx = 0;
	while (game->vec_idx < 36)
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
	int		i;

	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH);
	angle_iter = to_radians(game->ray_main_angle) - to_radians(30.0f);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	dir_x = 0;
	dir_y = 0;
	game->dist_idx = 0;
	i = 0;
	while (i < SCREEN_WIDTH)
		game->wall_dists[i++] = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = (float)game->data->player->x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = (float)game->data->player->y + dir_y * 2 * SCREEN_WIDTH;
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

void    cast_ray(t_game *game, float ray_angle)
{
	t_raycaster raycaster;
	
	calc_directions(&raycaster, game);
	raycaster.x_iterator = (float)game->data->player->x;
	raycaster.y_iterator = (float)game->data->player->y;
	raycaster.speed = 1;
	while (((raycaster.dir_x >= 0 && raycaster.x_iterator <= game->ray_new_x)
	        || (raycaster.dir_x < 0 && raycaster.x_iterator >= game->ray_new_x))
	       && ((raycaster.dir_y >= 0 && raycaster.y_iterator <= game->ray_new_y)
	           || (raycaster.dir_y < 0 && raycaster.y_iterator >= game->ray_new_y)))
	{
		if (is_ray_on_square_edge(&raycaster, game))
		{
			calc_collision_point_x_y(&raycaster, game);
//			if (raycaster.colis_x < 0 || raycaster.colis_x >= 1000 || raycaster.colis_y < 0 || raycaster.colis_y >= 1000)
//				return ;
//			if(raycaster.colis_x < 0 || raycaster.colis_y < 0)
//				return ;
			if (is_collision_point_wall(&raycaster, game))
			{
				set_ray_direction(&raycaster, game, &game->wall_direction);
				calc_ray_distance(&raycaster, game, ray_angle, &game->wall_dists[game->dist_idx]);
				game->ray_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
				return ;
			}
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}
