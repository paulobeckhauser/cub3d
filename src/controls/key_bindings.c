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

// change degrees to radians
// radians = degrees * (math.pi / 180)

// calculate new coordinates after moving ray by some angle
// x' = x * cos(θ) - y * sin(θ) y' = x * sin(θ) + y * cos(θ)

int	keypress(int keysymbol, t_game *game)
{
	if (keysymbol == ESC)
        close_game(game);
    else if (keysymbol == A)
    {
    	game->ray_angle -= 10;
		if (game->ray_angle <= 0)
			game->ray_angle += 360;
    }
    else if (keysymbol == D)
    {
    	game->ray_angle += 10;
		if (game->ray_angle >= 360)
			game->ray_angle -= 360;
    }
    else if (keysymbol == W)
		game->player_y += 1;
    else if (keysymbol == S)
		game->player_y -= 1;
	double radians = game->ray_angle * (M_PI / 180);
	double shifted_x = game->ray_x - game->player_x;
	double shifted_y = game->ray_y - game->player_y;
	double new_x = shifted_x * cos(radians) - shifted_y * sin(radians);
	double new_y = shifted_x * sin(radians) + shifted_y * cos(radians);
	new_x += game->player_x;
	new_y += game->player_y;
	printf("new ray_x: %f\n", new_x);
	printf("new ray_y: %f\n", new_y);
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)new_x, (int)new_y, rgb_to_hex(255, 0, 0));
	return (0);
    // draw_map(game);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_player, (int)game->player_x, (int)game->player_y);
    return (0);
}