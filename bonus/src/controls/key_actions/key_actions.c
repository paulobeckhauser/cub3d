/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:39:09 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:21:04 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

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
