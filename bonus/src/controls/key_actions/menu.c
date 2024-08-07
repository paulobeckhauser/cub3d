/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:45:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

/* Function: close_game
 * --------------------
 * Destroys the game window and frees allocated resources before exiting the program.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function is typically called when the game is being closed, ensuring that all
 * resources allocated by the MiniLibX library (used for window management and graphics
 * in this game) are properly freed and that the program exits cleanly.
 */
int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	exit(0);
}

/* Function: action_main_menu
 * --------------------------
 * Handles player input in the main menu, allowing the player to select between different
 * options using the left and right arrow keys, and to start the game by pressing enter.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * When the left arrow key is pressed, the player character is set to PABECKHA, and the
 * corresponding textures for the main menu, avatar, and gun are updated. Similarly, pressing
 * the right arrow key selects SFRANKIE as the player character, with appropriate texture updates.
 * Pressing the enter key exits the main menu, allowing the game to proceed to the gameplay phase.
 */
void	action_main_menu(t_game *game)
{
	if (game->keys[LEFT_ARROW])
	{
		game->player = PABECKHA;
		game->textures.main_menu_current = game->textures.main_menu[0];
		game->textures.avatar_current = game->textures.avatar[0];
		game->textures.gun_current_texture = game->textures.shotgun[0];
	}
	if (game->keys[RIGHT_ARROW])
	{
		game->player = SFRANKIE;
		game->textures.main_menu_current = game->textures.main_menu[1];
		game->textures.avatar_current = game->textures.avatar[2];
		game->textures.gun_current_texture = game->textures.desert_eagle[0];
	}
	if (game->keys[ENTER])
	{
		game->main_menu = false;
	}
}
