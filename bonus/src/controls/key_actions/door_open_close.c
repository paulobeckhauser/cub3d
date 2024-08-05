/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:43:52 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/04 23:53:11 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

void	open_close_door(t_game *game)
{
	int				i;
	
	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].dist >= 0 && game->door[i].dist < DOOR_OPEN_DISTANCE)
		{
			change_door_state(game, i);
			return ;
		}
		++i;
	}
}

void	change_door_state(t_game *game, int i)
{
	if (game->data.map_element[game->door[i].y][game->door[i].x]
		== '6' && game->enemy_count <= 0)
	{
		game->animation.door_are_opening = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '7';
	}
	else if (game->data.map_element[game->door[i].y][game->door[i].x] == '2')
	{
		game->animation.door_are_opening = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '3';
	}
	else if (game->data.map_element[game->door[i].y][game->door[i].x] == '7')
	{
		game->animation.door_are_closing = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '6';
	}
	else
	{
		game->animation.door_are_closing = true;
		game->data.map_element[game->door[i].y][game->door[i].x] = '2';
	}
}
