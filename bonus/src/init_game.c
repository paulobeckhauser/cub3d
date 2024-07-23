/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 12:25:27 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void    init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		perror("mlx");
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win_ptr)
	{
		perror("mlx window");
		exit(EXIT_FAILURE);
	}
	game->square_size = 100;
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	if (game->data->player->direction == 'N')
		game->ray_main_angle = 270;
	else if (game->data->player->direction == 'W')
		game->ray_main_angle = 180;
	else if (game->data->player->direction == 'S')
		game->ray_main_angle = 90;
	else
		game->ray_main_angle = 0;
	game->ray_hit_x = 0;
	game->ray_hit_y = 0;
	game->ray_door_hit_x = 0;
	game->ray_door_hit_y = 0;
	game->dist_idx = 0;
	game->wall_direction = 0;
	game->door_direction = 0;
	// game->enemy_x = 0;
	// game->enemy_y = 0;
	game->img_x = 0;
	game->img_y = 0;
	init_keys(game);
	game->door_animation_start_time = 0;
	game->gun_animation_start_time = 0;
	game->hit_closed_door = false;
	game->hit_opened_door = false;
//	game->closed_door_visible = false;
//	game->open_door_visible = false;
	game->door_visible = false;
	game->door_are_opening = false;
	game->door_are_closing = false;
	game->enemy_animation_start_time = 0;
	game->hit_enemy = false;
	game->mouse_x = 0;
	game->hp_frame_updated = false;
	game->player_dead = false;
	game->x_enemy_start = 0;
	game->x_enemy_end = 0;
	game->colis_y = 0;
	game->colis_x = 0;
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->depth_lvl < 30)
	{
		while (game->dist_idx < SCREEN_WIDTH)
		{
			game->body_hit[game->depth_lvl][game->dist_idx++] = false;
		}
		game->depth[game->depth_lvl].dist = 0;
		game->depth[game->depth_lvl].obj = EMPTY;
		game->depth[game->depth_lvl].ray_hit_x = 0;
		game->depth[game->depth_lvl].ray_hit_y = 0;
		game->door[game->depth_lvl].y = 0;
		game->door[game->depth_lvl].x = 0;
		++game->depth_lvl;
	}
	game->depth_lvl = 0;
	game->dist_idx = 0;
}

void    init_keys(t_game *game)
{
	int i;
	
	i = 0;
	while (i < 9)
		game->keys[i++] = false;
}