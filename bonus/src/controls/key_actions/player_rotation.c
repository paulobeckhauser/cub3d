/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/04 23:53:18 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

void	rotate_player_left(t_game *game)
{
	game->ray_main_angle -= ROTATION_SPEED;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = ANGLE_MAX / ROTATION_SPEED - 1;
}

void	rotate_player_right(t_game *game)
{
	game->ray_main_angle += ROTATION_SPEED;
	if (game->ray_main_angle >= ANGLE_MAX)
		game->ray_main_angle -= ANGLE_MAX;
	++game->vec_idx;
	if (game->vec_idx == ANGLE_MAX / ROTATION_SPEED)
		game->vec_idx = 0;
}

void	rotate_player_mouse(t_game *game)
{
	int	dir_x;

	dir_x = game->mouse_x - SCREEN_WIDTH / 2;
	if (dir_x < 0)
		rotate_player_left(game);
	else if (dir_x > 0)
		rotate_player_right(game);
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT
		/ 2);
}
