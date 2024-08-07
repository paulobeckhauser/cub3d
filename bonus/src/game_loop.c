/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:11:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:58:36 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* Function: init_hooks
Initializes all the necessary hooks for the game window.
game: A pointer to the game structure containing all game information and state.
This function sets up hooks for key presses, key releases, mouse movements, mouse button presses, and the main loop of the game. These hooks allow for interactive control over the game, such as moving the player, shooting, and closing the game. */
void	init_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 02, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, keyrelease, game);
	mlx_hook(game->win_ptr, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
	mlx_mouse_hook(game->win_ptr, mouse_press, game);
	mlx_loop_hook(game->mlx_ptr, loop_hook, game);
}

/* Function: loop_hook
The main game loop that updates the game state and renders the game.
game: A pointer to the game structure containing all game information and state.
This function checks if the escape key is pressed to close the game, updates the game state based on whether the main menu is active or the game has been won, and then renders the game. It also handles animations within the game. */
int	loop_hook(t_game *game)
{
	if (game->keys[ESC])
		close_game(game);
	if (game->main_menu && !game->won_game)
		action_main_menu(game);
	else if (!game->main_menu && !game->won_game)
		action_game(game);
	render_game(game);
	animation(game);
	return (0);
}
