/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 11:47:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/controls.h"
#include "../../incl/raycaster_test.h"
#include "../../incl/standard_libs.h"

int	close_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);
    exit(0);
}

void    rotate_player_left(t_game *game)
{
    change_angle_left(game);
    calculate_new_ray_x_y(game);
}

void    rotate_player_right(t_game *game)
{
    change_angle_right(game);
    calculate_new_ray_x_y(game);
}

void    change_angle_left(t_game *game)
{
    game->ray_angle -= 10;
    if (game->ray_angle <= 0)
        game->ray_angle += 360;
}

void    change_angle_right(t_game *game)
{
    game->ray_angle += 10;
    if (game->ray_angle >= 360)
        game->ray_angle -= 360;
}