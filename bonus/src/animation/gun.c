/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:30:08 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 00:30:09 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	animation_gun_shoot(t_game *game, int frame_duration, int frames,
							void **gun_type)
{
	struct timeval	tv;
	static long		start_time = 0;
	long			current_time;
	int				gun_frame;

	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	gun_frame = (current_time - start_time) / (frame_duration / frames);
	if (gun_frame >= frames || gun_frame < 0)
	{
		game->keys[MOUSE_LEFT_CLICK] = false;
		gun_frame = 0;
		start_time = 0;
		game->animation.animation_gun = false;
	}
	game->textures.gun_current_texture = gun_type[gun_frame];
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
		game->animation.animation_gun = true;
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
		game->animation.animation_gun = false;
	}
}

void	update_gun_running_textures(t_game *game, int gun_frame)
{
	if (game->player == PABECKHA)
		game->textures.gun_current_texture
			= game->textures.shotgun_run[gun_frame];
	else
		game->textures.gun_current_texture
			= game->textures.desert_eagle_run[gun_frame];
}
