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

int	keypress(int keysymbol, const t_mlx *mlx)
{
    if (keysymbol == ESC)
        close_game(mlx);
    if (keysymbol == A)
    {
        // handle rotating left
    }
    if (keysymbol == D)
    {
        // handle rotating right
    }
    if (keysymbol == W)
    {
        // handle moving forward
    }
    if (keysymbol == S)
    {
		// handle moving backward
    }
    return (0);
}