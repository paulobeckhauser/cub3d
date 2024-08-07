/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:39:09 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:24 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: action_game
 * ---------------------
 * Processes player actions based on the current state of input keys.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function checks the state of each relevant input key (W, S, A, D for movement,
 * LEFT_ARROW and RIGHT_ARROW for rotation, E for interacting with doors, and MOUSE_LEFT_CLICK
 * for an action triggered by clicking the left mouse button). Depending on which keys are
 * currently pressed, it calls the appropriate function to handle the player's action.
 * Movement and rotation actions are processed directly if their respective keys are pressed.
 * Door interaction is only processed if no door animations are currently happening.
 * The mouse left click action is processed through its own dedicated function.
 */
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
	if (game->keys[E] && !game->animation.door_are_closing
		&& !game->animation.door_are_opening)
		open_close_door(game);
	if (game->keys[MOUSE_LEFT_CLICK])
		action_mouse_left_click(game);
}
