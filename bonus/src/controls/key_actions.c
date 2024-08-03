/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 12:56:57 by sfrankie         ###   ########.fr       */
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
	if (game->data->map_element[game->door[i].y][game->door[i].x]
		== '6' && game->enemy_count <= 0)
	{
		game->door_are_opening = true;
		game->data->map_element[game->door[i].y][game->door[i].x] = '7';
	}
	else if (game->data->map_element[game->door[i].y][game->door[i].x] == '2')
	{
		game->door_are_opening = true;
		game->data->map_element[game->door[i].y][game->door[i].x] = '3';
	}
	else if (game->data->map_element[game->door[i].y][game->door[i].x] == '7')
	{
		game->door_are_closing = true;
		game->data->map_element[game->door[i].y][game->door[i].x] = '6';
	}
	else
	{
		game->door_are_closing = true;
		game->data->map_element[game->door[i].y][game->door[i].x] = '2';
	}
}
