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

#include "../incl/raycaster.h"
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
	game->map = init_test_map();
	mark_player(game);
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	game->ray_main_angle = 290.0f;
	game->ray_hit_x = 0;
	game->ray_hit_y = 0;
	game->ray_door_hit_x = 0;
	game->ray_door_hit_y = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
	{
		game->wall_dists[game->dist_idx] = 0;
		game->door_dists[game->dist_idx] = 0;
		game->enemy_dists[game->dist_idx] = 0;
		game->body_hit[game->dist_idx++] = false;
	}
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
	game->closed_door_visible = false;
	game->open_door_visible = false;
	game->door_are_opening = false;
	game->door_are_closing = false;
	game->closest_door_distance = INFINITY;
	game->prev_door_distance = 0;
	game->enemy_animation_start_time = 0;
	game->closest_enemy_distance = INFINITY;
	game->prev_enemy_distance = 0;
	game->ray_enemy_hit_x = 0;
	game->ray_enemy_hit_y = 0;
	game->hit_enemy = false;
	game->mouse_x = 0;
	game->first_enemy_dist = -1;
	game->hp_frame_updated = false;
	game->player_dead = false;
}

void    init_keys(t_game *game)
{
	int i;
	
	i = 0;
	while (i < 9)
		game->keys[i++] = false;
}