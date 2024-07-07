/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/07 15:33:00 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void    init_game(t_game *game, t_data *data)
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
	// game->map = init_test_map();
	game->map = data->map_element;
	// mark_player(game);

	game->player_x = data->player->x;
	game->player_y = data->player->y;
	
	game->ray_new_x = 0;
	game->ray_new_y = 0;

	if (data->player->direction == 'N')
		game->ray_main_angle = 280.0f;

	else if (data->player->direction == 'W')
		game->ray_main_angle = 190.0f;

	else if (data->player->direction == 'S')
		game->ray_main_angle = 100.0f;
	else
		game->ray_main_angle = 10.0f;
	
	// game->ray_main_angle = 280.0f;
	game->ray_hit_x = 0;
	game->ray_hit_y = 0;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
		game->wall_dists[game->dist_idx++] = 0;
	game->dist_idx = 0;
	game->wall_direction = 0;
	game->img_x = 0;
	game->img_y = 0;
	init_keys(game);
}

void    init_keys(t_game *game)
{
	int i;
	
	i = 0;
	while (i < 9)
		game->keys[i++] = false;
}
