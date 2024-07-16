/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 15:31:35 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	utils_init_game(t_game *game, t_data *data)
{
	if (data->player->direction == 'N')
		game->ray_main_angle = 270;
	else if (data->player->direction == 'W')
		game->ray_main_angle = 180;
	else if (data->player->direction == 'S')
		game->ray_main_angle = 90;
	else
		game->ray_main_angle = 0;
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
	game->line_height = 0;
	game->y_iterator = 0;
	game->y_end = 0;
	game->tex_x = 0;
	game->tex_y = 0;
	game->color = 0;
}

void	init_game(t_game *game, t_data *data)
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
	game->square_size = 100;
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	utils_init_game(game, data);
}

void	init_keys(t_game *game)
{
	int	i;

	i = 0;
	while (i < 9)
		game->keys[i++] = false;
}
