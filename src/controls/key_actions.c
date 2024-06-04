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

#include "../../incl/raycaster.h"

int	close_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);
    exit(0);
}

void    rotate_player_left(t_game *game)
{
    change_angle_left(game);
    calc_new_ray_x_y(game);
    game->ray_x = game->ray_new_x;
    game->ray_y = game->ray_new_y;
    draw_map(game);
}

void    rotate_player_right(t_game *game)
{
    change_angle_right(game);
    calc_new_ray_x_y(game);
    game->ray_x = game->ray_new_x;
    game->ray_y = game->ray_new_y;
    draw_map(game);
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

// Need to move player and also the ray so it doesn't lose it's length.
// First calculate direction (x,y) based on the ray angle
// Can modify speed by multiplying directions

void move_player_forward(t_game *game)
{
    double  dir_x;
    double  dir_y;
    double  speed;

    dir_x = cos(to_radians(game->ray_angle));
    dir_y = sin(to_radians(game->ray_angle));
    speed = 5;
    game->player_x += dir_x * speed;
    game->player_y += dir_y * speed;
    game->ray_x += dir_x * speed;
    game->ray_y += dir_y * speed;
    draw_map(game);
}

// Need to move player and also the ray so it doesn't lose it's length.
// First calculate direction (x,y) based on the ray angle
// Can modify speed by multiplying directions

void move_player_backward(t_game *game)
{
    double  dir_x;
    double  dir_y;
    double  speed;

    dir_x = cos(to_radians(game->ray_angle));
    dir_y = sin(to_radians(game->ray_angle));
    speed = 5;
    game->player_x -= dir_x * speed;
    game->player_y -= dir_y * speed;
    game->ray_x -= dir_x * speed;
    game->ray_y -= dir_y * speed;
    draw_map(game);
}