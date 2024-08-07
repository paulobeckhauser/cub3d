/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:29:18 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:47 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: update_hp_status
 * --------------------------
 * Updates the player's health point (HP) status based on the enemy's attack frame.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * enemy_frame: The current frame of the enemy's attack animation.
 * 
 * This function uses a static variable to keep track of the HP texture index. It updates
 * the HP texture to reflect damage taken when the enemy's attack animation reaches a
 * certain frame. It also sets the player's death state if HP drops to zero.
 */
void	update_hp_status(t_game *game, int enemy_frame)
{
	static int	i = ENEMY_FRAMES;

	if (enemy_frame == 0 && game->animation.hp_frame_updated)
		game->animation.hp_frame_updated = false;
	if (enemy_frame == 9 && !game->animation.hp_frame_updated)
	{
		if (i != 0)
			game->textures.hp_current_texture
				= game->textures.hp_texture[--i];
		game->animation.hp_frame_updated = true;
	}
	if (game->textures.hp_current_texture == game->textures.hp_texture[0]
		&& enemy_frame == 0)
		game->player_dead = true;
}

/* Function: animation_avatar
 * --------------------------
 * Animates the player's avatar based on time.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Uses a static start_time to track the beginning of the animation. Calculates the
 * current frame of the avatar animation based on the elapsed time. Once the animation
 * reaches the last frame, it resets the animation state and updates the avatar texture.
 */
void	animation_avatar(t_game *game)
{
	struct timeval	tv;
	static long		start_time = 0;
	long			current_time;
	int				avatar_frame;

	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	avatar_frame = (current_time - start_time)
		/ (AVATAR_FRAME_DURATION / AVATAR_FRAMES);
	if (avatar_frame < 0)
		avatar_frame = 0;
	if (avatar_frame >= AVATAR_FRAMES)
	{
		avatar_frame = AVATAR_FRAMES - 1;
		start_time = 0;
	}
	update_avatar_textures(game, avatar_frame);
}

/* Function: update_avatar_textures
 * --------------------------------
 * Updates the avatar texture based on the current frame of the avatar animation.
 * 
 * game: A pointer to the game structure.
 * avatar_frame: The current frame of the avatar animation.
 * 
 * Depending on the player's character, updates the current avatar texture to the
 * corresponding frame from the avatar animation textures.
 */
void	update_avatar_textures(t_game *game, int avatar_frame)
{
	if (game->player == PABECKHA)
	{
		if (avatar_frame == AVATAR_FRAMES / 2)
			game->textures.avatar_current = game->textures.avatar[1];
		else
			game->textures.avatar_current = game->textures.avatar[0];
	}
	else
	{
		if (avatar_frame == AVATAR_FRAMES / 2)
			game->textures.avatar_current = game->textures.avatar[3];
		else
			game->textures.avatar_current = game->textures.avatar[2];
	}
}
