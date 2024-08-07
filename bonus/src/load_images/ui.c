/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:04:07 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:37 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: load_images_minimap
 * ------------------------------
 * Loads minimap-related textures into the game from specified image files.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads textures for the minimap, including the door, skull, and player textures from their respective XPM files.
 */
void	load_images_minimap(t_game *game)
{
    game->textures.door_minimap = mlx_xpm_file_to_image(game->mlx_ptr,
	    DOOR_MINIMAP, &game->img_x, &game->img_y);
    game->textures.skull = mlx_xpm_file_to_image(game->mlx_ptr, SKULL,
	    &game->img_x, &game->img_y);
    game->textures.player_texture = mlx_xpm_file_to_image(game->mlx_ptr,
	    PLAYER_TEXTURE, &game->img_x, &game->img_y);
}

/* Function: load_images_hp
 * -------------------------
 * Loads health point (HP) bar textures into the game from specified image files.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads textures for different levels of the player's health points from their respective XPM files, including a texture for the current HP level.
 */
void	load_images_hp(t_game *game)
{
    game->textures.hp_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, HP_0,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, HP_10,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, HP_20,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, HP_30,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, HP_40,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[5] = mlx_xpm_file_to_image(game->mlx_ptr, HP_50,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[6] = mlx_xpm_file_to_image(game->mlx_ptr, HP_60,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[7] = mlx_xpm_file_to_image(game->mlx_ptr, HP_70,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[8] = mlx_xpm_file_to_image(game->mlx_ptr, HP_80,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[9] = mlx_xpm_file_to_image(game->mlx_ptr, HP_90,
	    &game->img_x, &game->img_y);
    game->textures.hp_texture[10] = mlx_xpm_file_to_image(game->mlx_ptr,
	    HP_100, &game->img_x, &game->img_y);
    game->textures.hp_current_texture = mlx_xpm_file_to_image(game->mlx_ptr,
	    HP_100, &game->img_x, &game->img_y);
}

/* Function: load_images_menu
 * ---------------------------
 * Loads menu and end-game screen textures into the game from specified image files.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads textures for the main menu, game over screen, and win screen from their respective XPM files. It also sets the current menu texture.
 */
void	load_images_menu(t_game *game)
{
    game->textures.main_menu[0] = mlx_xpm_file_to_image(game->mlx_ptr,
	    MAIN_MENU_PABECKHA, &game->img_x, &game->img_y);
    game->textures.main_menu[1] = mlx_xpm_file_to_image(game->mlx_ptr,
	    MAIN_MENU_SFRANKIE, &game->img_x, &game->img_y);
    game->textures.main_menu_current = mlx_xpm_file_to_image(game->mlx_ptr,
	    MAIN_MENU_PABECKHA, &game->img_x, &game->img_y);
    game->textures.game_over_texture = mlx_xpm_file_to_image(game->mlx_ptr,
	    GAME_OVER, &game->img_x, &game->img_y);
    game->textures.win_screen = mlx_xpm_file_to_image(game->mlx_ptr,
	    WIN_SCREEN, &game->img_x, &game->img_y);
}

/* Function: load_images_avatar
 * -----------------------------
 * Loads avatar textures into the game from specified image files.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads textures for different avatars from their respective XPM files and sets the current avatar texture.
 */
void	load_images_avatar(t_game *game)
{
    game->textures.avatar[0] = mlx_xpm_file_to_image(game->mlx_ptr,
	    AVATAR_PAULO_0_1, &game->img_x, &game->img_y);
    game->textures.avatar[1] = mlx_xpm_file_to_image(game->mlx_ptr,
	    AVATAR_PAULO_1_1, &game->img_x, &game->img_y);
    game->textures.avatar[2] = mlx_xpm_file_to_image(game->mlx_ptr,
	    AVATAR_SZYMON_0_1, &game->img_x, &game->img_y);
    game->textures.avatar[3] = mlx_xpm_file_to_image(game->mlx_ptr,
	    AVATAR_SZYMON_1_1, &game->img_x, &game->img_y);
    game->textures.avatar_current = game->textures.avatar[0];
}
