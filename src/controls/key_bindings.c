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

#include "../../incl/controls.h"
#include "../../incl/defines.h"
#include "../../incl/raycaster_test.h"
#include "../../incl/standard_libs.h"
#include "../../incl/defines.h"
#include "../../incl/cub3d.h"

int	keypress(int keysymbol, t_game *game)
{
	if (keysymbol == ESC)
        close_game(game);
    else if (keysymbol == A)
	{
        rotate_player_left(game);
	}
    else if (keysymbol == D)
	{
		rotate_player_right(game);
	}
	else if (keysymbol == S)
	{
		move_player_forward(game);
	}
	else if (keysymbol == W)
	{
		move_player_backward(game);
	}
	draw_map(game);
    return (0);
}