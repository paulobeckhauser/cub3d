/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:40:21 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 12:46:06 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	move_player_forward(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	game->data->player->y += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
			&& game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3')
	{
		game->data->player->x -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
		return ;
	}
}

void	move_player_backward(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
			&& game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3')
	{
		game->data->player->x += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
		game->data->player->y += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
		return ;
	}
}

void	move_player_left(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
			&& game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3')
	{
		game->data->player->x -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
		game->data->player->y += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
		return ;
	}
}

void	move_player_right(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	game->data->player->y += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	if (game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '0'
			&& game->data->map_element[(int)game->data->player->y
			/ SQUARE_SIZE][(int)game->data->player->x / SQUARE_SIZE] != '3')
	{
		game->data->player->x += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
		game->data->player->y -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
		return ;
	}
}
