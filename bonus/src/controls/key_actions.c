/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 21:57:01 by pabeckha         ###   ########.fr       */
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
	game->ray_main_angle -= 6;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = 59;
}

void    rotate_player_right(t_game *game)
{
	game->ray_main_angle += 6;
	if (game->ray_main_angle >= 360)
		game->ray_main_angle -= 360;
	++game->vec_idx;
	if (game->vec_idx == 60)
		game->vec_idx = 0;
}

void    move_player_forward(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].x * SPEED;
	game->data->player->y += game->vectors[game->vec_idx].y * SPEED;
	if (game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '1'
	    || game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '2')	{
		game->data->player->x -= game->vectors[game->vec_idx].x * SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].y * SPEED;
		return ;
	}
}

void    move_player_backward(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].x * SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].y * SPEED;
	if (game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '1'
	    || game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '2')	{
		game->data->player->x += game->vectors[game->vec_idx].x * SPEED;
		game->data->player->y += game->vectors[game->vec_idx].y * SPEED;
		return ;
	}
}

void    move_player_left(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].y * SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].x * SPEED;
	if (game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '1'
	    || game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '2')
	{
		game->data->player->x -= game->vectors[game->vec_idx].y * SPEED;
		game->data->player->y += game->vectors[game->vec_idx].x * SPEED;
		return ;
	}
}

void    move_player_right(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].y * SPEED;
	game->data->player->y += game->vectors[game->vec_idx].x * SPEED;
	if (game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '1'
		|| game->data->map_element[(int)(game->data->player->y / game->square_size)][(int)(game->data->player->x / game->square_size)] == '2')
	{
		game->data->player->x += game->vectors[game->vec_idx].y * SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].x * SPEED;
		return ;
	}
}

void    open_close_door(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	x = 0;
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	game->door_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	while (game->data->map_element[y])
	{
		x = 0;
		while (game->data->map_element[y][x])
		{
			if ((game->open_door_visible || game->closed_door_visible) && game->closest_door_distance < DOOR_OPEN_DISTANCE)
			{
				if (game->data->map_element[y][x] == '2')
				{
					game->door_are_opening = true;
					game->data->map_element[y][x] = '3';
					game->keys[E] = false;
					return ;
				}
				else if (game->data->map_element[y][x] == '3')
				{
					game->door_are_closing = true;
					game->data->map_element[y][x] = '2';
					game->keys[E] = false;
					return ;
				}
			}
			x++;
		}
		y++;
	}
}