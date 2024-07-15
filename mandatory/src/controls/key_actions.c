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

#include "../../incl/cub3d.h"

int	close_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);
    exit(0);
}

void    rotate_player_left(t_game *game)
{
	game->ray_main_angle -= 3;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = 119;
}

void    rotate_player_right(t_game *game)
{
	game->ray_main_angle += 3;
	if (game->ray_main_angle >= 360)
		game->ray_main_angle -= 360;
	++game->vec_idx;
	if (game->vec_idx == 120)
		game->vec_idx = 0;
}

void    move_player_forward(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].x * SPEED;
	game->data->player->y += game->vectors[game->vec_idx].y * SPEED;
	if (game->data->map_element[(int)game->data->player->y / SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0')
	{
		game->data->player->x -= game->vectors[game->vec_idx].x * SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].y * SPEED;
		return ;
	}
}

void move_player_backward(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].x * SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].y * SPEED;
	if (game->data->map_element[(int)game->data->player->y / SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0')
	{
		game->data->player->x += game->vectors[game->vec_idx].x * SPEED;
		game->data->player->y += game->vectors[game->vec_idx].y * SPEED;
		return ;
	}
}

void move_player_left(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].y * SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].x * SPEED;
	if (game->data->map_element[(int)game->data->player->y / SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0')
	{
		game->data->player->x -= game->vectors[game->vec_idx].y * SPEED;
		game->data->player->y += game->vectors[game->vec_idx].x * SPEED;
		return ;
	}
}

void move_player_right(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].y * SPEED;
	game->data->player->y += game->vectors[game->vec_idx].x * SPEED;
	if (game->data->map_element[(int)game->data->player->y / SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0')
	{
		game->data->player->x += game->vectors[game->vec_idx].y * SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].x * SPEED;
		return ;
	}
}
