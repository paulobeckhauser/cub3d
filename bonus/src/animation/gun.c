/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:30:08 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:45 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: animation_gun_shoot
 * -----------------------------
 * Animates the shooting action of the gun.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * frame_duration: The duration of each frame in the animation.
 * frames: The total number of frames in the animation.
 * gun_type: An array of textures representing different frames of the gun shooting animation.
 * 
 * Uses a static start_time to track the beginning of the animation. Calculates the
 * current frame of the shooting animation based on the elapsed time. Once the animation
 * reaches the last frame, it resets the animation state and updates the current gun texture.
 */
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

/* Function: animation_gun_running
 * -------------------------------
 * Animates the gun movement when the player is running.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Checks if the player is moving without shooting. If so, it triggers the running
 * animation for the gun by calculating the current frame based on elapsed time and
 * updates the gun's texture accordingly.
 */
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

/* Function: update_gun_running_textures
 * -------------------------------------
 * Updates the gun texture based on the current frame of the running animation.
 * 
 * game: A pointer to the game structure.
 * gun_frame: The current frame of the gun running animation.
 * 
 * Depending on the player's character, updates the current gun texture to the
 * corresponding frame from the running animation textures.
 */
void	update_gun_running_textures(t_game *game, int gun_frame)
{
	if (game->player == PABECKHA)
		game->textures.gun_current_texture
			= game->textures.shotgun_run[gun_frame];
	else
		game->textures.gun_current_texture
			= game->textures.desert_eagle_run[gun_frame];
}
