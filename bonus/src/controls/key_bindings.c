/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:33:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:18 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: keypress
 * ------------------
 * Handles key press events by setting the corresponding game key state to true.
 * 
 * keysymbol: The keycode of the pressed key.
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function updates the game's key state array based on the keycode of the pressed key.
 * It sets the state to true for the pressed key, indicating that the key is currently being pressed.
 */
int	keypress(const int keysymbol, t_game *game)
{
	if (keysymbol == 65307)
		game->keys[ESC] = true;
	if (keysymbol == 119)
		game->keys[W] = true;
	if (keysymbol == 115)
		game->keys[S] = true;
	if (keysymbol == 97)
		game->keys[A] = true;
	if (keysymbol == 100)
		game->keys[D] = true;
	if (keysymbol == 65361)
		game->keys[LEFT_ARROW] = true;
	if (keysymbol == 65363)
		game->keys[RIGHT_ARROW] = true;
	if (keysymbol == 101)
		game->keys[E] = true;
	if (keysymbol == 65293)
		game->keys[ENTER] = true;
	return (0);
}

/* Function: keyrelease
 * --------------------
 * Handles key release events by setting the corresponding game key state to false.
 * 
 * keysymbol: The keycode of the released key.
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function updates the game's key state array based on the keycode of the released key.
 * It sets the state to false for the released key, indicating that the key is no longer being pressed.
 */
int	keyrelease(const int keysymbol, t_game *game)
{
	if (keysymbol == 65307)
		game->keys[ESC] = false;
	if (keysymbol == 119)
		game->keys[W] = false;
	if (keysymbol == 115)
		game->keys[S] = false;
	if (keysymbol == 97)
		game->keys[A] = false;
	if (keysymbol == 100)
		game->keys[D] = false;
	if (keysymbol == 65361)
		game->keys[LEFT_ARROW] = false;
	if (keysymbol == 65363)
		game->keys[RIGHT_ARROW] = false;
	if (keysymbol == 101)
		game->keys[E] = false;
	if (keysymbol == 65293)
		game->keys[ENTER] = false;
	return (0);
}

/* Function: mouse_move
 * --------------------
 * Handles mouse movement events by updating the game's mouse position state.
 * 
 * x: The x-coordinate of the mouse position.
 * y: The y-coordinate of the mouse position (unused in this function).
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function updates the game's mouse_x state with the current x-coordinate of the mouse.
 * The y-coordinate is not used in this function, hence it's cast to void to avoid unused variable warnings.
 */
int	mouse_move(int x, int y, t_game *game)
{
	game->mouse_x = x;
	(void)y;
	return (0);
}

/* Function: mouse_press
 * ---------------------
 * Handles mouse button press events, specifically the left mouse button for shooting.
 * 
 * button: The button code of the pressed mouse button.
 * x: The x-coordinate of the mouse position at the time of the press (unused).
 * y: The y-coordinate of the mouse position at the time of the press (unused).
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function checks if the left mouse button is pressed and if the shooting animation is not already playing.
 * If these conditions are met, it iterates through the enemies to check if any are hit by the shot.
 * If an enemy is hit, it's marked as '5' on the map, effectively removing it from the game, and the enemy count is decreased.
 * The function also sets the MOUSE_LEFT_CLICK key state to true, indicating that the left mouse button has been pressed.
 */
int	mouse_press(int button, int x, int y, t_game *game)
{
	int				i;

	(void)x;
	(void)y;
	if (button == 1 && !game->animation.animation_gun)
	{
		i = 0;
		while (i < ENEMY_MAX)
		{
			if (game->enemy[i].hit_body[SCREEN_WIDTH / 2])
			{
				game->data.map_element[game->enemy[i].y][game->enemy[i].x]
					= '5';
				--game->enemy_count;
				break ;
			}
			++i;
		}
		game->keys[MOUSE_LEFT_CLICK] = true;
	}
	return (0);
}
