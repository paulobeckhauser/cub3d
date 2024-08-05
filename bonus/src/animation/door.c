/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:51:10 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/04 23:53:57 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	animation_close_door(t_game *game)
{
	struct timeval	tv;
	static long		start_time = 0;
	long			current_time;
	int				door_frame;
	
	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	door_frame = DOOR_FRAMES - 1 - (current_time - start_time)
								   / (DOOR_FRAME_DURATION / DOOR_FRAMES);
	if (door_frame >= DOOR_FRAMES)
		door_frame = DOOR_FRAMES - 1;
	if (door_frame <= 0)
	{
		game->animation.door_are_closing = false;
		door_frame = 0;
		start_time = 0;
	}
	update_door_close_textures(game, door_frame);
}

void	update_door_close_textures(t_game *game, int door_frame)
{
	int	i;
	
	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].dist > 0
			&& game->door[i].dist < DOOR_OPEN_DISTANCE)
		{
			if (game->data.map_element[game->door[i].y][game->door[i].x]
				== '6')
				game->door[i].texture = game->textures.exit[door_frame];
			else
				game->door[i].texture
						= game->textures.door_texture[door_frame];
			break ;
		}
		++i;
	}
}

void	animation_open_door(t_game *game)
{
	struct timeval	tv;
	static long		start_time = 0;
	long			current_time;
	int				door_frame;
	
	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	door_frame = (current_time - start_time)
				 / (DOOR_FRAME_DURATION / DOOR_FRAMES);
	if (door_frame < 0)
		door_frame = 0;
	if (door_frame >= DOOR_FRAMES)
	{
		game->animation.door_are_opening = false;
		door_frame = DOOR_FRAMES - 1;
		start_time = 0;
	}
	update_door_open_textures(game, door_frame);
}

void	update_door_open_textures(t_game *game,	int door_frame)
{
	int	i;
	
	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].dist > 0
			&& game->door[i].dist < DOOR_OPEN_DISTANCE)
		{
			if (game->data.map_element[game->door[i].y][game->door[i].x]
				== '7')
				game->door[i].texture = game->textures.exit[door_frame];
			else
				game->door[i].texture
						= game->textures.door_texture[door_frame];
			break ;
		}
		++i;
	}
}
