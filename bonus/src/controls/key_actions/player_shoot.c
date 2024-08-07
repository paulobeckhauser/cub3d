/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:40:22 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:33 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: action_mouse_left_click
 * ---------------------------------
 * Handles the action triggered by the left click of the mouse, which is shooting.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function sets the animation_gun flag to true, indicating that a shooting animation
 * should be played. It then checks the type of player to determine which gun animation to play.
 * If the player is PABECKHA, it plays the shotgun animation; otherwise, it plays the desert eagle
 * animation. The function uses animation_gun_shoot to trigger the appropriate animation, passing
 * in the frame duration, number of frames, and the texture to use for the animation.
 */
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
