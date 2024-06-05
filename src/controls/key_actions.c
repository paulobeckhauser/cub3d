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

void    rotate_player_left(t_game *game, t_image *image)
{
    change_angle_left(game);
    calc_new_ray_x_y(game);
    game->ray_main_x = game->ray_new_x;
    game->ray_main_y = game->ray_new_y;
    draw_map(game, image);
}

void    rotate_player_right(t_game *game, t_image *image)
{
    change_angle_right(game);
    calc_new_ray_x_y(game);
    game->ray_main_x = game->ray_new_x;
    game->ray_main_x = game->ray_new_y;
    draw_map(game, image);
}

/* Need to move player and also the ray so it doesn't lose it's length.
 First calculate direction (x,y) based on the ray angle
 Can modify speed by multiplying directions */
void move_player_forward(t_game *game, t_image *image)
{
    float  dir_x;
    float  dir_y;
    float  speed;

    dir_x = cos(to_radians(game->ray_angle));
    dir_y = sin(to_radians(game->ray_angle));
    speed = 40;
    game->player_x += dir_x * speed;
    game->player_y += dir_y * speed;
    game->ray_main_x += dir_x * speed;
    game->ray_main_y += dir_y * speed;
    draw_map(game, image);
}

/* Need to move player and also the ray so it doesn't lose it's length.
 First calculate direction (x,y) based on the ray angle
 Can modify speed by multiplying directions */
void move_player_backward(t_game *game, t_image *image)
{
    float  dir_x;
    float  dir_y;
    float  speed;

    dir_x = cos(to_radians(game->ray_angle));
    dir_y = sin(to_radians(game->ray_angle));
    speed = 40;
    game->player_x -= dir_x * speed;
    game->player_y -= dir_y * speed;
    game->ray_main_x -= dir_x * speed;
    game->ray_main_y -= dir_y * speed;
    draw_map(game, image);
}