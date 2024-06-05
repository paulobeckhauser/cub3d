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

int	keypress(const int keysymbol, t_game *game, t_image *image)
{
	if (keysymbol == ESC)
        close_game(game);
    else if (keysymbol == A)
        rotate_player_left(game, image);
    else if (keysymbol == D)
		rotate_player_right(game, image);
	else if (keysymbol == W)
		move_player_forward(game, image);
	else if (keysymbol == S)
		move_player_backward(game, image);
    return (0);
}