/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:18:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:18:02 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

void	mark_player(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
			{
				game->player_x = x * game->square_width + game->square_width / 2;
				game->player_y = y * game->square_height + game->square_height / 2;
				return ;
			}
			x++;
		}
		y++;
	}
	
}

float	to_radians(float degrees)
{
	return (degrees * (M_PI / 180));
}

void    calc_directions(t_raycaster *raycaster, t_game *game)
{
	raycaster->dir_x = game->ray_new_x - game->player_x;
	raycaster->dir_y = game->ray_new_y - game->player_y;
	raycaster->len = sqrt(raycaster->dir_x * raycaster->dir_x + raycaster->dir_y * raycaster->dir_y);
	raycaster->dir_x /= raycaster->len;
	raycaster->dir_y /= raycaster->len;
}

bool    is_ray_on_square_edge(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->x_iterator % (int)game->square_width == 0
		|| (int)raycaster->y_iterator % (int)game->square_height == 0)
		return (true);
	return (false);
}
