/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 12:55:21 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init_game(t_game *game)
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
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	if (game->data->player->direction == 'N')
		game->ray_main_angle = 0.75f * ANGLE_MAX;
	else if (game->data->player->direction == 'W')
		game->ray_main_angle = 0.5f * ANGLE_MAX;
	else if (game->data->player->direction == 'S')
		game->ray_main_angle = 0.25f * ANGLE_MAX;
	else
		game->ray_main_angle = 0;
	game->ray_hit_x = 0;
	game->ray_hit_y = 0;
	game->dist_idx = 0;
	game->wall_direction = 0;
	game->door_direction = 0;
	game->img_x = 0;
	game->img_y = 0;
	init_keys(game);
	game->door_are_opening = false;
	game->door_are_closing = false;
	game->mouse_x = 0;
	game->hp_frame_updated = false;
	game->player_dead = false;
	game->depth_lvl = 0;
	game->dist_idx = 0;
	while (game->depth_lvl < DEPTH_MAX)
	{
		game->depth[game->depth_lvl].dist = 0;
		game->depth[game->depth_lvl].obj = EMPTY;
		game->depth[game->depth_lvl].ray_hit_y = 0;
		game->depth[game->depth_lvl].ray_hit_x = 0;
		game->depth[game->depth_lvl].colis_y = 0;
		game->depth[game->depth_lvl].colis_x = 0;
		game->door[game->depth_lvl].y = 0;
		game->door[game->depth_lvl].x = 0;
		game->enemy[game->depth_lvl].x = 0;
		game->enemy[game->depth_lvl].y = 0;
		game->enemy[game->depth_lvl].x_start = 0;
		game->enemy[game->depth_lvl].x_end = 0;
		game->enemy[game->depth_lvl].size = 0;
		game->enemy[game->depth_lvl].tex_x = 0;
		game->enemy[game->depth_lvl].visible = false;
		game->enemy[game->depth_lvl].dead = false;
		++game->depth_lvl;
	}
	game->depth_lvl = 0;
	game->dist_idx = 0;
	game->main_menu = true;
	game->animation_gun = false;
	game->enemy_count = 0;
	game->won_game = false;
	game->player = PABECKHA;
	game->enemy_visible = false;
}

void	init_keys(t_game *game)
{
	int i;

	i = 0;
	while (i < NUM_KEYS)
		game->keys[i++] = false;
}