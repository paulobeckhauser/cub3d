/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:33:46 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:20:58 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	animation(t_game *game)
{
	if (!game->animation.animation_gun && !game->keys[MOUSE_LEFT_CLICK]
		&& game->player == SFRANKIE)
		game->textures.gun_current_texture
			= game->textures.desert_eagle[0];
	else if (!game->animation.animation_gun && !game->keys[MOUSE_LEFT_CLICK]
		&& game->player == PABECKHA)
		game->textures.gun_current_texture = game->textures.shotgun[0];
	if (game->animation.door_are_opening)
		animation_open_door(game);
	if (game->animation.door_are_closing)
		animation_close_door(game);
	if (game->enemy_visible)
		animation_enemy_cast(game);
	animation_enemy_death(game);
	animation_avatar(game);
	animation_gun_running(game);
}
