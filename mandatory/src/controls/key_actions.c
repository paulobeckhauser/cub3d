/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 12:41:28 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
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
