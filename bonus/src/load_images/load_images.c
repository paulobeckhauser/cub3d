/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:33 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: load_images_from_dir
 * -------------------------------
 * Loads all game-related images from their respective directories.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function sequentially calls other functions responsible for loading different categories of images (walls, minimap, weapons, etc.)
 * into the game's memory. It ensures that all visual assets are loaded before the game starts.
 */
void	load_images_from_dir(t_game *game)
{
	load_images_wall(game);
	load_images_minimap(game);
	load_images_desert_eagle(game);
	load_images_shotgun_1_2(game);
	load_images_shotgun_2_2(game);
	load_images_door(game);
	load_images_hp(game);
	load_images_blood_1_3(game);
	load_images_blood_2_3(game);
	load_images_blood_3_3(game);
	load_images_menu(game);
	load_images_avatar(game);
	load_images_enemy_1_2(game);
	load_images_enemy_2_2(game);
}
