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

int	keypress(int keysymbol, t_game *game)
{
	double	old_ray_x, old_ray_y, new_ray_x, new_ray_y;
	double	radian_angle;
    if (keysymbol == ESC)
        close_game(game);
    else if (keysymbol == A)
		game->player_angle -= 10;
    else if (keysymbol == D)
		game->player_angle += 10;
    else if (keysymbol == W)
		game->player_y += 1;
    else if (keysymbol == S)
		game->player_y -= 1;
	radian_angle = game->player_angle * M_PI / 180.0;
	old_ray_x = game->ray_x - game->player_x;
	old_ray_y = game->ray_y - game->player_y;
	new_ray_x = cos(radian_angle) * old_ray_x - sin(radian_angle) * old_ray_y + game->player_x;
	new_ray_y = sin(radian_angle) * old_ray_x + cos(radian_angle) * old_ray_y + game->player_y;
	game->ray_x = new_ray_x;
	game->ray_y = new_ray_y;
    draw_map(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_player, (int)game->player_x, (int)game->player_y);
	draw_ray(game);
    return (0);
}