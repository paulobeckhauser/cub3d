/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:56:30 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:31 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: load_images_desert_eagle
 * -----------------------------------
 * Loads the textures for the Desert Eagle gun into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads each frame of the Desert Eagle's animation from XPM files into the game's texture array for later use.
 */
void	load_images_desert_eagle(t_game *game)
{
    game->textures.desert_eagle[0] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_0_4, &game->img_x, &game->img_y);
    game->textures.desert_eagle[1] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_1_4, &game->img_x, &game->img_y);
    game->textures.desert_eagle[2] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_2_4, &game->img_x, &game->img_y);
    game->textures.desert_eagle[3] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_3_4, &game->img_x, &game->img_y);
    game->textures.desert_eagle[4] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_4_4, &game->img_x, &game->img_y);
    game->textures.desert_eagle_run[0] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_RUN_0_1, &game->img_x, &game->img_y);
    game->textures.desert_eagle_run[1] = mlx_xpm_file_to_image(game->mlx_ptr,
	    DESERT_EAGLE_RUN_1_1, &game->img_x, &game->img_y);
}

/* Function: load_images_shotgun_1_2
 * ----------------------------------
 * Loads the first half of the textures for the shotgun into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads the first half of the shotgun's animation frames from XPM files into the game's texture array for later use.
 */
void	load_images_shotgun_1_2(t_game *game)
{
    game->textures.shotgun[0] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_0_14, &game->img_x, &game->img_y);
    game->textures.shotgun[1] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_1_14, &game->img_x, &game->img_y);
    game->textures.shotgun[2] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_2_14, &game->img_x, &game->img_y);
    game->textures.shotgun[3] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_3_14, &game->img_x, &game->img_y);
    game->textures.shotgun[4] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_4_14, &game->img_x, &game->img_y);
    game->textures.shotgun[5] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_5_14, &game->img_x, &game->img_y);
    game->textures.shotgun[6] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_6_14, &game->img_x, &game->img_y);
    game->textures.shotgun[7] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_7_14, &game->img_x, &game->img_y);
    game->textures.shotgun[8] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_8_14, &game->img_x, &game->img_y);
}

/* Function: load_images_shotgun_2_2
 * ----------------------------------
 * Loads the second half of the textures for the shotgun into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads the second half of the shotgun's animation frames from XPM files into the game's texture array for later use.
 * It also sets the current gun texture to the first frame of the shotgun for immediate use.
 */
void	load_images_shotgun_2_2(t_game *game)
{
    game->textures.shotgun[9] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_9_14, &game->img_x, &game->img_y);
    game->textures.shotgun[10] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_10_14, &game->img_x, &game->img_y);
    game->textures.shotgun[11] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_11_14, &game->img_x, &game->img_y);
    game->textures.shotgun[12] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_12_14, &game->img_x, &game->img_y);
    game->textures.shotgun[13] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_13_14, &game->img_x, &game->img_y);
    game->textures.shotgun[14] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_14_14, &game->img_x, &game->img_y);
    game->textures.shotgun_run[0] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_RUN_0_1, &game->img_x, &game->img_y);
    game->textures.shotgun_run[1] = mlx_xpm_file_to_image(game->mlx_ptr,
	    SHOTGUN_RUN_1_1, &game->img_x, &game->img_y);
    game->textures.gun_current_texture = game->textures.shotgun[0];
}
