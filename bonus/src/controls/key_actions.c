/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 22:13:10 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	close_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);
    exit(0);
}

void    rotate_player_left(t_game *game)
{
	game->ray_main_angle -= ROTATION_SPEED;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = ANGLE_MAX / ROTATION_SPEED - 1;
}

void    rotate_player_right(t_game *game)
{
	game->ray_main_angle += ROTATION_SPEED;
	if (game->ray_main_angle >= ANGLE_MAX)
		game->ray_main_angle -= ANGLE_MAX;
	++game->vec_idx;
	if (game->vec_idx == ANGLE_MAX / ROTATION_SPEED)
		game->vec_idx = 0;
}

//void    open_close_door(t_game *game)
//{
//	int x;
//	int y;
//
//	y = 0;
//	x = 0;
//	struct timeval  tv;
//	gettimeofday(&tv, NULL);
//	game->door_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
//	while (game->data->map_element[y])
//	{
//		x = 0;
//		while (game->data->map_element[y][x])
//		{
//			if (game->door_visible && game->closest_door_distance < DOOR_OPEN_DISTANCE)
//			{
//				if (game->data->map_element[y][x] == '2')
//				{
//					game->door_are_opening = true;
//					game->data->map_element[y][x] = '3';
//					game->keys[E] = false;
//					return ;
//				}
//				else if (game->data->map_element[y][x] == '3')
//				{
//					game->door_are_closing = true;
//					game->data->map_element[y][x] = '2';
//					game->keys[E] = false;
//					return ;
//				}
//			}
//			x++;
//		}
//		y++;
//	}
//}

void    open_close_door(t_game *game)
{
	int i;
	
	struct timeval tv;
	gettimeofday(&tv, NULL);
	game->door_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	i = 0;
	while (i < DOOR_MAX)
	{
		if (game->door[i].dist > 0 && game->door[i].dist < DOOR_OPEN_DISTANCE)
		{
			if (game->data->map_element[game->door[i].y][game->door[i].x] == '2')
			{
				game->door_are_opening = true;
				game->data->map_element[game->door[i].y][game->door[i].x] = '3';
				game->keys[E] = false;
				return ;
			}
			else
			{
				game->door_are_closing = true;
				game->data->map_element[game->door[i].y][game->door[i].x] = '2';
				game->keys[E] = false;
				return ;
			}
		}
		++i;
	}
}