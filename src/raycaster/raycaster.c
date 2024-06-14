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
#include "../../incl/cub3d.h"

void    calc_dir_vectors(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;
	
	angle_incr_radians = to_radians(10.0f); //field of view (60 deg) divided by screen width
	angle_iter = to_radians(game->ray_main_angle);
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

	angle_incr_radians = to_radians(FIELD_OF_VIEW / SCREEN_WIDTH); //field of view (60 deg) divided by screen width
	angle_iter = to_radians(game->ray_main_angle) - to_radians(30.0f);
	dir_x = 0;
	dir_y = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		dir_x = cosf(angle_iter);
		dir_y = sinf(angle_iter);
		game->ray_new_x = game->player_x + dir_x * 2 * SCREEN_WIDTH;
		game->ray_new_y = game->player_y + dir_y * 2 * SCREEN_WIDTH;
		cast_ray(game, angle_iter);
		render_wall_line(game);
		if (game->hit_opened_door)
			render_closer_wall_line(game);
		angle_iter += angle_incr_radians;
		if (angle_iter < 0) {
			angle_iter += 2 * M_PI;
		} else if (angle_iter > 2 * M_PI) {
			angle_iter -= 2 * M_PI;
		}
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
			if (raycaster.colis_x < 0 || raycaster.colis_x >= 10 || raycaster.colis_y < 0 || raycaster.colis_y >= 10)
				return ;
			if (is_collision_point_a_wall(&raycaster, game) || is_collision_point_a_closed_door(&raycaster, game))
			{
				set_ray_direction(&raycaster, game);
				calc_ray_distance(&raycaster, game, ray_angle);
				game->ray_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
				return ;
			}
			if (is_collision_point_a_opened_door(&raycaster, game))
			{
				set_closer_ray_direction(&raycaster, game);
				calc_ray_distance_opened_door(&raycaster, game, ray_angle);
				game->ray_open_door_hit_x = fmodf(raycaster.x_iterator, game->square_size) / game->square_size;
				game->ray_open_door_hit_y = fmodf(raycaster.y_iterator, game->square_size) / game->square_size;
			}
		}
		raycaster.x_iterator += raycaster.dir_x * raycaster.speed;
		raycaster.y_iterator += raycaster.dir_y * raycaster.speed;
	}
}

void    render_closer_wall_line(t_game *game)
{
	int line_height;
	int y_iterator;
	int y_end;
	int tex_x;
	int	tex_y;
	int color;
	
	line_height = DRAWING_SCALE / (game->closer_dists[game->dist_idx] + 1);
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	if (game->closer_direction == NORTH || game->closer_direction == SOUTH)
		tex_x = (int)(game->ray_open_door_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->ray_open_door_hit_y * TEXTURE_SIZE);
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
		color = get_pixel_color(game->door_opened_texture, tex_x, tex_y);
		if (color != rgb_to_hex(255, 0, 255) && game->hit_opened_door)
			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
		y_iterator++;
	}
	game->hit_opened_door = false;
}