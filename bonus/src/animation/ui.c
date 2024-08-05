/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:29:18 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 00:29:20 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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
