/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 11:47:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

int	close_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);
    exit(0);
}

void    rotate_player_left(t_game *game)
{
	game->ray_main_angle -= 10;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = 35;
    render_map(game);
}

void    rotate_player_right(t_game *game)
{
	game->ray_main_angle += 10;
	if (game->ray_main_angle >= 360)
		game->ray_main_angle -= 360;
	++game->vec_idx;
	if (game->vec_idx == 36)
		game->vec_idx = 0;
    render_map(game);
}

void    move_player_forward(t_game *game)
{
	game->player_x += game->vectors[game->vec_idx].x * SPEED;
	game->player_y += game->vectors[game->vec_idx].y * SPEED;
	if (game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '1'
	    || game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '2')	{
		game->player_x -= game->vectors[game->vec_idx].x * SPEED;
		game->player_y -= game->vectors[game->vec_idx].y * SPEED;
		return ;
	}
	render_map(game);
}

void    move_player_backward(t_game *game)
{
	game->player_x -= game->vectors[game->vec_idx].x * SPEED;
	game->player_y -= game->vectors[game->vec_idx].y * SPEED;
	if (game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '1'
	    || game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '2')	{
		game->player_x += game->vectors[game->vec_idx].x * SPEED;
		game->player_y += game->vectors[game->vec_idx].y * SPEED;
		return ;
	}
	render_map(game);
}

void    move_player_left(t_game *game)
{
	game->player_x += game->vectors[game->vec_idx].y * SPEED;
	game->player_y -= game->vectors[game->vec_idx].x * SPEED;
	if (game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '1'
	    || game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '2')
	{
		game->player_x -= game->vectors[game->vec_idx].y * SPEED;
		game->player_y += game->vectors[game->vec_idx].x * SPEED;
		return ;
	}
	render_map(game);
}

void    move_player_right(t_game *game)
{
	game->player_x -= game->vectors[game->vec_idx].y * SPEED;
	game->player_y += game->vectors[game->vec_idx].x * SPEED;
	if (game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '1'
		|| game->map[(int)(game->player_y / game->square_size)][(int)(game->player_x / game->square_size)] == '2')
	{
		game->player_x += game->vectors[game->vec_idx].y * SPEED;
		game->player_y -= game->vectors[game->vec_idx].x * SPEED;
		return ;
	}
	render_map(game);
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
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ((game->open_door_visible || game->closed_door_visible) && game->closest_door_distance < DOOR_OPEN_DISTANCE)
			{
				if (game->map[y][x] == '2')
				{
					game->door_are_opening = true;
					game->map[y][x] = '3';
					game->keys[E] = false;
					return ;
				}
				else if (game->map[y][x] == '3')
				{
					game->door_are_closing = true;
					game->map[y][x] = '2';
					game->keys[E] = false;
					return ;
				}
			}
			x++;
		}
		y++;
	}
}