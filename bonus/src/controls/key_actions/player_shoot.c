/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:40:22 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 00:40:23 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

void	action_mouse_left_click(t_game *game)
{
	game->animation.animation_gun = true;
	if (game->player == PABECKHA)
		animation_gun_shoot(game, SHOTGUN_FRAME_DURATION, SHOTGUN_FRAMES,
							game->textures.shotgun);
	else
		animation_gun_shoot(game, DESERT_EAGLE_FRAME_DURATION,
							DESERT_EAGLE_FRAMES, game->textures.desert_eagle);
}
