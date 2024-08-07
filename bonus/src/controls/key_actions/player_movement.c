/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:40:21 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:28 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: move_player_forward
 * -----------------------------
 * Moves the player forward based on the current direction vector and checks for collisions.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function updates the player's position by adding the direction vector scaled by the
 * movement speed to the player's current position. It then checks if the new position is a
 * collision with a wall ('4'), a win condition ('7'), or other non-walkable elements. If a
 * collision is detected, the player's position is reverted.
 */
void	move_player_forward(t_game *game)
{
	game->data.player->x += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	game->data.player->y += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '0'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '3'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '5')
	{
		game->data.player->x -= game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
		game->data.player->y -= game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
	}
}

/* Function: move_player_backward
 * ------------------------------
 * Moves the player backward by reversing the direction vector and checks for collisions.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Similar to move_player_forward, but the direction vector is subtracted from the player's
 * position. Collision detection and handling are the same as in move_player_forward.
 */
void	move_player_backward(t_game *game)
{
	game->data.player->x -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	game->data.player->y -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '0'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '3'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '5')
	{
		game->data.player->x += game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
		game->data.player->y += game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
	}
}

/* Function: move_player_left
 * --------------------------
 * Moves the player to the left by adjusting the direction vector and checks for collisions.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function adjusts the player's position by adding the perpendicular vector (to simulate
 * left movement) scaled by the movement speed. Collision detection and handling are consistent
 * with move_player_forward.
 */
void	move_player_left(t_game *game)
{
	game->data.player->x += game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	game->data.player->y -= game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '0'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '3'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '5')
	{
		game->data.player->x -= game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
		game->data.player->y += game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
	}
}

/* Function: move_player_right
 * ---------------------------
 * Moves the player to the right by adjusting the direction vector and checks for collisions.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function adjusts the player's position by subtracting the perpendicular vector (to simulate
 * right movement) scaled by the movement speed. Collision detection and handling are consistent
 * with move_player_forward.
 */
void	move_player_right(t_game *game)
{
	game->data.player->x -= game->vectors[game->vec_idx].y * MOVEMENT_SPEED;
	game->data.player->y += game->vectors[game->vec_idx].x * MOVEMENT_SPEED;
	if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '4')
	{
		game->player_dead = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] == '7')
	{
		game->won_game = true;
	}
	else if (game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '0'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '3'
		&& game->data.map_element[(int)game->data.player->y
			/ SQUARE_SIZE][(int)game->data.player->x / SQUARE_SIZE] != '5')
	{
		game->data.player->x += game->vectors[game->vec_idx].y
			* MOVEMENT_SPEED;
		game->data.player->y -= game->vectors[game->vec_idx].x
			* MOVEMENT_SPEED;
	}
}
