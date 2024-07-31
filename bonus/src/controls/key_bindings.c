/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:33:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 13:38:53 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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
	if (keysymbol == 65293)
		game->keys[ENTER] = true;
	return (0);
}

int	keyrelease(const int keysymbol, t_game *game)
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
	if (keysymbol == 101)
		game->keys[E] = false;
	if (keysymbol == 65293)
		game->keys[ENTER] = false;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	game->mouse_x = x;
	(void)y;
	return (0);
}

int	mouse_press(int button, int x, int y, t_game *game)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	(void)x;
	(void)y;
	if (button == 1)
	{
		i = 0;
		while (i < ENEMY_MAX)
		{
			if (game->enemy[i].hit_body[SCREEN_WIDTH / 2])
			{
				game->data->map_element[game->enemy[i].y][game->enemy[i].x]
					= '5';
				--game->enemy_count;
				break ;
			}
			++i;
		}
		game->gun_animation_start_time = tv.tv_sec * 1000000 + tv.tv_usec;
		game->keys[MOUSE_LEFT_CLICK] = true;
	}
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->keys[ESC])
		close_game(game);
	if (game->main_menu && !game->won_game)
		action_main_menu(game);
	else if (!game->main_menu && !game->won_game)
		action_game(game);
	render_game(game);
	animation(game);
	return (0);
}

void	action_game(t_game *game)
{
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
	rotate_player_mouse(game);
	if (game->keys[E] && !game->door_are_closing && !game->door_are_opening)
		open_close_door(game);
	if (game->keys[MOUSE_LEFT_CLICK])
		action_mouse_left_click(game);
}

void	animation(t_game *game)
{
	if (!game->animation_gun && !game->keys[MOUSE_LEFT_CLICK]
		&& game->player == SFRANKIE)
		game->textures->gun_current_texture
			= game->textures->desert_eagle[0];
	else if (!game->animation_gun && !game->keys[MOUSE_LEFT_CLICK]
		&& game->player == PABECKHA)
		game->textures->gun_current_texture = game->textures->shotgun[0];
	animation_open_door(game);
	animation_close_door(game);
	if (game->enemy_visible)
		animation_enemy_cast(game);
	animation_enemy_death(game);
	animation_avatar(game);
	animation_gun_running(game);
}

void	action_main_menu(t_game *game)
{
	if (game->keys[LEFT_ARROW])
	{
		game->player = PABECKHA;
		game->textures->main_menu_current = game->textures->main_menu[0];
		game->textures->avatar_current = game->textures->avatar[0];
		game->textures->gun_current_texture = game->textures->shotgun[0];
	}
	if (game->keys[RIGHT_ARROW])
	{
		game->player = SFRANKIE;
		game->textures->main_menu_current = game->textures->main_menu[1];
		game->textures->avatar_current = game->textures->avatar[2];
		game->textures->gun_current_texture = game->textures->desert_eagle[0];
	}
	if (game->keys[ENTER])
	{
		game->main_menu = false;
	}
}

void	action_mouse_left_click(t_game *game)
{
	if (game->player == PABECKHA)
		animation_gun_shoot(game, SHOTGUN_FRAME_DURATION, SHOTGUN_FRAMES);
	else
		animation_gun_shoot(game, DESERT_EAGLE_FRAME_DURATION,
			DESERT_EAGLE_FRAMES);
}

void	animation_gun_shoot(t_game *game, int frame_duration, int frames)
{
	struct timeval	tv;
	long			current_time;
	long			elapsed_time;
	int				gun_frame;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed_time = current_time - game->gun_animation_start_time;
	gun_frame = elapsed_time / (frame_duration / frames);
	if (gun_frame < 0)
		gun_frame = 0;
	if (gun_frame >= frames)
	{
		game->keys[MOUSE_LEFT_CLICK] = false;
		gun_frame = 0;
	}
	if (game->player == PABECKHA)
		game->textures->gun_current_texture
			= game->textures->shotgun[gun_frame];
	else
		game->textures->gun_current_texture
			= game->textures->desert_eagle[gun_frame];
}

void	animation_enemy_death(t_game *game)
{
	int	j;

	j = 0;
	while (j < ENEMY_MAX)
	{
		if (game->data->map_element[game->enemy[j].y][game->enemy[j].x] == '5'
			&& !game->enemy[j].dead)
			update_death_textures(game, j);
		++j;
	}
}

void	update_death_textures(t_game *game, int j)
{
	long			current_time;
	long			elapsed_time;
	int				blood_frame;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed_time = current_time - game->enemy_animation_start_time * 2
		* -1;
	blood_frame = (elapsed_time / (BLOOD_FRAME_DURATION / BLOOD_FRAMES))
		% BLOOD_FRAMES;
	if (blood_frame < 0)
		blood_frame = 0;
	if (blood_frame >= BLOOD_FRAMES - 1)
	{
		game->enemy[j].texture
			= game->textures->dark_priest_texture[ENEMY_FRAMES - 1];
		game->enemy[j].dead = true;
		return ;
	}
	game->enemy[j].texture = game->textures->blood[blood_frame];
}

void	animation_enemy_cast(t_game *game)
{
	int				j;

	j = 0;
	while (j < ENEMY_MAX)
	{
		if (game->enemy[j].visible && !game->enemy[j].dead)
			update_enemy_cast_textures(game, j);
		++j;
	}
}

void	update_enemy_cast_textures(t_game *game, int j)
{
	struct timeval	tv;
	long			current_time;
	long			elapsed_time;
	int				enemy_frame;
	static int		i = ENEMY_FRAMES;

	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed_time = current_time - game->enemy_animation_start_time * -2;
	enemy_frame = (elapsed_time / (ENEMY_FRAME_DURATION / ENEMY_FRAMES))
		% ENEMY_FRAMES;
	if (enemy_frame == 0 && game->hp_frame_updated)
		game->hp_frame_updated = false;
	if (enemy_frame < 0)
		enemy_frame = 0;
	if (enemy_frame != 10)
		game->enemy[j].texture
			= game->textures->dark_priest_texture[enemy_frame];
	game->enemy[j].visible = false;
	update_hp_status(game, enemy_frame, &i);
}

void	update_hp_status(t_game *game, int enemy_frame, int *i)
{
	if (enemy_frame == 9 && !game->hp_frame_updated)
	{
		if (i != 0)
			game->textures->hp_current_texture
				= game->textures->hp_texture[--(*i)];
		game->hp_frame_updated = true;
	}
	if (game->textures->hp_current_texture == game->textures->hp_texture[0]
		&& enemy_frame == 0)
		game->player_dead = true;
}

void	animation_close_door(t_game *game)
{
	struct timeval	tv;
	long			current_time;
	long			elapsed_time;
	int				door_frame;

	if (game->door_are_closing)
	{
		gettimeofday(&tv, NULL);
		current_time = tv.tv_sec * 1000000 + tv.tv_usec;
		elapsed_time = current_time - game->door_animation_start_time;
		door_frame = DOOR_FRAMES - 1 - elapsed_time / (DOOR_FRAME_DURATION
				/ DOOR_FRAMES);
		if (door_frame >= DOOR_FRAMES)
			door_frame = DOOR_FRAMES - 1;
		if (door_frame <= 0)
		{
			game->door_are_closing = false;
			door_frame = 0;
		}
		update_door_close_textures(game, door_frame);
	}
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
			if (game->data->map_element[game->door[i].y][game->door[i].x]
				== '6')
				game->door[i].texture = game->textures->exit[door_frame];
			else
				game->door[i].texture
					= game->textures->door_texture[door_frame];
			break ;
		}
		++i;
	}
}

void	animation_open_door(t_game *game)
{
	struct timeval	tv;
	long			current_time;
	long			elapsed_time;
	int				door_frame;

	if (game->door_are_opening)
	{
		gettimeofday(&tv, NULL);
		current_time = tv.tv_sec * 1000000 + tv.tv_usec;
		elapsed_time = current_time - game->door_animation_start_time;
		door_frame = elapsed_time / (DOOR_FRAME_DURATION / DOOR_FRAMES);
		if (door_frame < 0)
			door_frame = 0;
		if (door_frame >= DOOR_FRAMES)
		{
			game->door_are_opening = false;
			door_frame = DOOR_FRAMES - 1;
		}
		update_door_open_textures(game, door_frame);
	}
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
			if (game->data->map_element[game->door[i].y][game->door[i].x]
				== '7')
				game->door[i].texture = game->textures->exit[door_frame];
			else
				game->door[i].texture
					= game->textures->door_texture[door_frame];
			break ;
		}
		++i;
	}
}

void	animation_avatar(t_game *game)
{
	struct timeval	tv;
	long			start_time;
	long			current_time;
	long			elapsed_time;
	int				avatar_frame;

	gettimeofday(&tv, NULL);
	start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	elapsed_time = current_time - start_time * -2;
	avatar_frame = (elapsed_time / (AVATAR_FRAME_DURATION / AVATAR_FRAMES))
		% AVATAR_FRAMES;
	if (avatar_frame < 0)
		avatar_frame = 0;
	if (avatar_frame >= AVATAR_FRAMES)
		avatar_frame = AVATAR_FRAMES - 1;
	update_avatar_textures(game, avatar_frame);
}

void	update_avatar_textures(t_game *game, int avatar_frame)
{
	if (game->player == PABECKHA)
	{
		if (avatar_frame == AVATAR_FRAMES / 2)
			game->textures->avatar_current = game->textures->avatar[1];
		else
			game->textures->avatar_current = game->textures->avatar[0];
	}
	else
	{
		if (avatar_frame == AVATAR_FRAMES / 2)
			game->textures->avatar_current = game->textures->avatar[3];
		else
			game->textures->avatar_current = game->textures->avatar[2];
	}
}

void	animation_gun_running(t_game *game)
{
	struct timeval	tv;
	long			start_time;
	long			current_time;
	long			elapsed_time;
	int				gun_frame;

	if (!game->keys[MOUSE_LEFT_CLICK] && (game->keys[W] || game->keys[S]
			|| game->keys[A] || game->keys[S]))
	{
		game->animation_gun = true;
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
		gettimeofday(&tv, NULL);
		current_time = tv.tv_sec * 1000000 + tv.tv_usec;
		elapsed_time = current_time - start_time * -2;
		gun_frame = (elapsed_time / (GUN_RUN_FRAME_DURATION / GUN_RUN_FRAMES)
				% GUN_RUN_FRAMES);
		if (gun_frame < 0)
			gun_frame = 0;
		if (gun_frame >= GUN_RUN_FRAMES)
			gun_frame = GUN_RUN_FRAMES - 1;
		update_gun_running_textures(game, gun_frame);
		game->animation_gun = false;
	}
}

void	update_gun_running_textures(t_game *game, int gun_frame)
{
	if (game->player == PABECKHA)
		game->textures->gun_current_texture
			= game->textures->shotgun_run[gun_frame];
	else
		game->textures->gun_current_texture
			= game->textures->desert_eagle_run[gun_frame];
}
