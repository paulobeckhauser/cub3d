/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:22:03 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init_game(t_game *game)
{
	int	i;

	init_mlx(game);
	init_image(game);
	init_utils(game);
	game->animation.door_are_opening = false;
	game->animation.door_are_closing = false;
	game->animation.hp_frame_updated = false;
	game->animation.animation_gun = false;
	i = 0;
	while (i < NUM_KEYS)
		game->keys[i++] = false;
	i = 0;
	while (i < DEPTH_MAX)
	{
		game->door[i].y = 0;
		game->door[i].x = 0;
		game->enemy[i].x = 0;
		game->enemy[i].y = 0;
		game->enemy[i].dead = false;
		++i;
	}
	calc_dir_vectors(game);
}

void	init_utils(t_game *game)
{
	if (game->data.player->direction == 'N')
		game->ray_main_angle = 0.75f * ANGLE_MAX;
	else if (game->data.player->direction == 'W')
		game->ray_main_angle = 0.5f * ANGLE_MAX;
	else if (game->data.player->direction == 'S')
		game->ray_main_angle = 0.25f * ANGLE_MAX;
	else
		game->ray_main_angle = 0;
	game->ray_hit_x = 0;
	game->ray_hit_y = 0;
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	game->dist_idx = 0;
	game->wall_direction = 0;
	game->door_direction = 0;
	game->img_x = 0;
	game->img_y = 0;
	game->mouse_x = 0;
	game->player_dead = false;
	game->main_menu = true;
	game->enemy_count = 0;
	game->won_game = false;
	game->player = PABECKHA;
}

void	init_image(t_game *game)
{
	game->image.img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->image.bits_per_pixel = 32;
	game->image.line_length = SCREEN_WIDTH;
	game->image.endian = 0;
	game->image.data = (int *)mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		perror("mlx");
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3d");
	if (!game->win_ptr)
	{
		perror("mlx window");
		exit(EXIT_FAILURE);
	}
}

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
