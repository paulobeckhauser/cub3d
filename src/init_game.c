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
	game->square_width = SCREEN_WIDTH / 10.0f;
	game->square_height = SCREEN_HEIGHT / 10.0f;
	game->map_x = 0;
	game->map_y = 0;
	game->map = init_test_map();
	mark_player(game);
	mark_main_ray((game));
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	game->ray_angle = 270;
	game->dist_idx = 0;
	while (game->dist_idx < SCREEN_WIDTH)
		game->dists[game->dist_idx++] = 0;
	game->dist_idx = 0;
	game->direction = 0;
	game->img_x = 0;
	game->img_y = 0;
}