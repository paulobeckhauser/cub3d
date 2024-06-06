/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:33:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 11:40:28 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

int	keypress(const int keysymbol, t_game *game)
{
	if (keysymbol == W || keysymbol == A || keysymbol == S || keysymbol == D)
		game->keys[keysymbol] = true;
	if (keysymbol == 65307)
		game->keys[ESC] = true;
	return (0);
}

int keyrelease(const int keysymbol, t_game *game)
{
	if (keysymbol == W || keysymbol == A || keysymbol == S || keysymbol == D || keysymbol == ESC)
		game->keys[keysymbol] = false;
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->keys[W])
		move_player_forward(game);
	if (game->keys[S])
		move_player_backward(game);
	if (game->keys[A])
		rotate_player_left(game);
	if (game->keys[D])
		rotate_player_right(game);
	if (game->keys[ESC])
		close_game(game);
	draw_map(game);
	return (0);
}
