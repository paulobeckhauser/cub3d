/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:33:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 11:40:28 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

int	keypress(const int keysymbol, t_game *game)
{
	if (keysymbol == 65307)
		game->keys[ESC] = true;
	if (keysymbol == 119)
		game->keys[W] = true;
	if (keysymbol == 115)
		game->keys[S] = true;
	if (keysymbol == 97)
		game->keys[A] = true;
	if (keysymbol == 100)
		game->keys[D] = true;
	if (keysymbol == 65361)
		game->keys[LEFT_ARROW] = true;
	if (keysymbol == 65363)
		game->keys[RIGHT_ARROW] = true;
	if (keysymbol == 101)
		game->keys[E] = true;
	return (0);
}

int keyrelease(const int keysymbol, t_game *game)
{
	if (keysymbol == 65307)
		game->keys[ESC] = false;
	if (keysymbol == 119)
		game->keys[W] = false;
	if (keysymbol == 115)
		game->keys[S] = false;
	if (keysymbol == 97)
		game->keys[A] = false;
	if (keysymbol == 100)
		game->keys[D] = false;
	if (keysymbol == 65361)
		game->keys[LEFT_ARROW] = false;
	if (keysymbol == 65363)
		game->keys[RIGHT_ARROW] = false;
	return (0);
}

int mouse_move(int x, int y, t_game *game)
{
	game->mouse_x = x;
	(void)y;
	return (0);
}

int	loop_hook(t_game *game)
{
	int dir_x;

	dir_x = game->mouse_x - SCREEN_WIDTH / 2;
	if (dir_x < 0)
		rotate_player_left(game);
	else if (dir_x > 0)
		rotate_player_right(game);
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	if (game->keys[W])
		move_player_forward(game);
	if (game->keys[S])
		move_player_backward(game);
	if (game->keys[A])
		move_player_left(game);
	if (game->keys[D])
		move_player_right(game);
	if (game->keys[LEFT_ARROW])
		rotate_player_left(game);
	if (game->keys[RIGHT_ARROW])
		rotate_player_right(game);
	if (game->keys[E] && !game->door_are_closing && !game->door_are_opening)
		open_close_door(game);
	if (game->keys[ESC])
		close_game(game);
	if (game->door_are_opening)
	{
		struct timeval  tv;
		gettimeofday(&tv, NULL);
		long    current_time = tv.tv_sec * 1000000 + tv.tv_usec;
		long    elapsed_time = current_time - game->door_animation_start_time;
		int door_frame = elapsed_time / (DOOR_FRAME_DURATION / DOOR_FRAMES);
		if (door_frame < 0)
			door_frame = 0;
		if (door_frame >= DOOR_FRAMES)
		{
			game->door_are_opening = false;
			door_frame = DOOR_FRAMES - 1;
		}
		game->door_current_texture = game->door_texture[door_frame];
	}
	if (game->door_are_closing)
	{
		struct timeval  tv;
		gettimeofday(&tv, NULL);
		long    current_time = tv.tv_sec * 1000000 + tv.tv_usec;
		long    elapsed_time = current_time - game->door_animation_start_time;
		int door_frame = DOOR_FRAMES - 1 - elapsed_time / (DOOR_FRAME_DURATION / DOOR_FRAMES);
		if (door_frame >= DOOR_FRAMES)
			door_frame = DOOR_FRAMES - 1;
		if (door_frame <= 0)
		{
			game->door_are_closing = false;
			door_frame = 0;
		}
		game->door_current_texture = game->door_texture[door_frame];
	}
	render_map(game);
	return (0);
}