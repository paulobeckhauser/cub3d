/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:40:21 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/31 12:54:28 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	move_player_forward(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	game->data->player->y += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '5')
	{
		game->data->player->x -= game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
		return ;
	}
}

void	move_player_backward(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '5')
	{
		game->data->player->x += game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
		game->data->player->y += game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
		return ;
	}
}

void	move_player_left(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '5')
	{
		game->data->player->x -= game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
		game->data->player->y += game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
		return ;
	}
}

void	move_player_right(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	game->data->player->y += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
		return ;
	}
	if (game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3'
		&& game->data->map_element[(int)game->data->player->y
		/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '5')
	{
		game->data->player->x += game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
		return ;
	}
}
