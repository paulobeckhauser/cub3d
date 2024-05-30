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
	double dx = game->ray_x - game->player_x;
	double dy = game->ray_y - game->player_y;
	double ray_len = sqrt(dx * dx + dy * dy);
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
	double	radian_angle = game->player_angle * M_PI / 180.0;
	game->ray_x = game->player_x + cos(radian_angle) * ray_len;
	game->ray_y = game->player_y + sin(radian_angle) * ray_len;
	printf("new ray_x: %f\n", game->ray_x);
	printf("new ray_y: %f\n", game->ray_y);
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)game->ray_x, (int)game->ray_y, rgb_to_hex(255, 0, 0));
	while (game->ray_x < 100)
	return (0);
    draw_map(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_player, (int)game->player_x, (int)game->player_y);
    return (0);
}