/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/16 13:52:48 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->north_texture);
	mlx_destroy_image(game->mlx_ptr, game->south_texture);
	mlx_destroy_image(game->mlx_ptr, game->west_texture);
	mlx_destroy_image(game->mlx_ptr, game->east_texture);
	mlx_destroy_image(game->mlx_ptr, game->image->img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	free(game->data->player);
	free(game->data->texture_north);
	free(game->data->texture_south);
	free(game->data->texture_west);
	free(game->data->texture_east);
	free_2d_array(game->data->map_element);
	free_2d_array(game->data->cub_file);
	exit(0);
}

void	rotate_player_left(t_game *game)
{
	game->ray_main_angle -= 3;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = 119;
}

void	rotate_player_right(t_game *game)
{
	game->ray_main_angle += 3;
	if (game->ray_main_angle >= 360)
		game->ray_main_angle -= 360;
	++game->vec_idx;
	if (game->vec_idx == 120)
		game->vec_idx = 0;
}
