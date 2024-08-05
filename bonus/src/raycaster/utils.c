/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:18:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:40:35 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

float	to_radians(float degrees)
{
	return (degrees * (M_PI / (ANGLE_MAX / 2)));
}

float	fix_angle_overflow(float angle_iter)
{
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	return (angle_iter);
}

int	find_enemy(t_game *game)
{
	int	i;

	i = ENEMY_MAX - 1;
	while (i >= 0)
	{
		if (game->depth[game->depth_lvl].colis_x == game->enemy[i].x
			&& game->depth[game->depth_lvl].colis_y == game->enemy[i].y)
		{
			if (game->depth_lvl == 0)
				game->enemy_visible = true;
			return (i);
		}
		--i;
	}
	return (i);
}

void	calc_enemy_data_relative_to_player(t_game *game, float ray_angle, int i)
{
	int	y;

	game->enemy[i].x_start = game->dist_idx;
	game->enemy[i].x_end = find_enemy_end(game, ray_angle, i);
	game->enemy[i].size = game->enemy[i].x_end - game->enemy[i].x_start;
	game->enemy[i].visible = true;
	if (game->enemy[i].x_start < 0)
	{
		y = 0;
		while (y < game->enemy[i].x_start * -1)
		{
			game->enemy[i].tex_x += (float)TEXTURE_SIZE_DEFAULT
				/ (float)game->enemy[i].size;
			++y;
		}
	}
}

bool	is_direction_in_range(t_raycaster *raycaster, t_game *game)
{
	if (((raycaster->dir_x >= 0 && raycaster->x_iterator <= game->ray_new_x)
			|| (raycaster->dir_x < 0 && raycaster->x_iterator
				>= game->ray_new_x))
		&& ((raycaster->dir_y >= 0 && raycaster->y_iterator <= game->ray_new_y)
			|| (raycaster->dir_y < 0
				&& raycaster->y_iterator >= game->ray_new_y)))
		return (true);
	return (false);
}
