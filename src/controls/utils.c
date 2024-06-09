/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:37:08 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:37:12 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

void change_angle_left(t_game *game)
{
	game->ray_angle -= 10;
	if (game->ray_angle <= 0)
		game->ray_angle += 360;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = 35;
	game->dir_x = cos(to_radians(game->ray_angle));
	game->dir_y = sin(to_radians(game->ray_angle));
	game->plane_x = game->dir_y;
	game->plane_y = -game->dir_x;
}

void change_angle_right(t_game *game)
{
	game->ray_angle += 10;
	if (game->ray_angle >= 360)
		game->ray_angle -= 360;
	++game->vec_idx;
	if (game->vec_idx == 36)
		game->vec_idx = 0;
	game->dir_x = cos(to_radians(game->ray_angle));
	game->dir_y = sin(to_radians(game->ray_angle));
	game->plane_x = game->dir_y;
	game->plane_y = -game->dir_x;
}

//void    change_angle_left(t_game *game)
//{
//	--game->vec_idx;
//	if (game->vec_idx == -1)
//		game->vec_idx = 35;
//}
//
//void    change_angle_right(t_game *game)
//{
//	++game->vec_idx;
//	if (game->vec_idx == 36)
//		game->vec_idx = 0;
//}