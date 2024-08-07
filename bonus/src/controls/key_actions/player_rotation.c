/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:31 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: rotate_player_left
 * ----------------------------
 * Rotates the player to the left by decreasing the main angle and adjusting the vector index.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function decreases the player's main angle by a predefined rotation speed. If the angle
 * becomes negative, it's adjusted to maintain a valid range. The vector index, which represents
 * the direction of the player, is also decreased to simulate rotation. If the index becomes
 * negative, it's wrapped around to the maximum index value to maintain continuity.
 */
void	rotate_player_left(t_game *game)
{
	game->ray_main_angle -= ROTATION_SPEED;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = ANGLE_MAX / ROTATION_SPEED - 1;
}

/* Function: rotate_player_right
 * -----------------------------
 * Rotates the player to the right by increasing the main angle and adjusting the vector index.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function increases the player's main angle by a predefined rotation speed. If the angle
 * exceeds the maximum angle, it's adjusted to maintain a valid range. The vector index, which
 * represents the direction of the player, is also increased to simulate rotation. If the index
 * exceeds the maximum index value, it's wrapped around to 0 to maintain continuity.
 */
void	rotate_player_right(t_game *game)
{
	game->ray_main_angle += ROTATION_SPEED;
	if (game->ray_main_angle >= ANGLE_MAX)
		game->ray_main_angle -= ANGLE_MAX;
	++game->vec_idx;
	if (game->vec_idx == ANGLE_MAX / ROTATION_SPEED)
		game->vec_idx = 0;
}

/* Function: rotate_player_mouse
 * -----------------------------
 * Rotates the player based on mouse movement by determining the direction of rotation.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function calculates the direction of mouse movement relative to the screen center. If the
 * mouse moves to the left of the center, the player is rotated left. If the mouse moves to the
 * right, the player is rotated right. After rotation, the mouse cursor is recentered on the screen
 * to allow for continuous rotation without the cursor leaving the game window.
 */
void	rotate_player_mouse(t_game *game)
{
	int	dir_x;

	dir_x = game->mouse_x - SCREEN_WIDTH / 2;
	if (dir_x < 0)
		rotate_player_left(game);
	else if (dir_x > 0)
		rotate_player_right(game);
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT
		/ 2);
}
