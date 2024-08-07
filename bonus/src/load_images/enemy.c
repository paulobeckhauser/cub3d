/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:59:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:29 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: load_images_enemy_1_2
 * --------------------------------
 * Loads the first half of the dark priest textures into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads textures for the dark priest enemy from files named DARK_PRIEST_0_9 to DARK_PRIEST_4_9.
 * Each texture is loaded into a specific index of the dark_priest_texture array within the game structure.
 */
void	load_images_enemy_1_2(t_game *game)
{
    game->textures.dark_priest_texture[0]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_0_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[1]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_1_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[2]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_2_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[3]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_3_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[4]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_4_9, &game->img_x, &game->img_y);
}

/* Function: load_images_enemy_2_2
 * --------------------------------
 * Loads the second half of the dark priest textures into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function continues loading textures for the dark priest enemy, covering files named DARK_PRIEST_5_9 to DARK_PRIEST_9_9,
 * and includes the DARK_PRIEST_CORPSE texture. Each texture is loaded into the subsequent index of the dark_priest_texture array.
 */
void	load_images_enemy_2_2(t_game *game)
{
    game->textures.dark_priest_texture[5]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_5_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[6]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_6_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[7]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_7_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[8]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_8_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[9]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_9_9, &game->img_x, &game->img_y);
    game->textures.dark_priest_texture[10]
	= mlx_xpm_file_to_image(game->mlx_ptr,
	    DARK_PRIEST_CORPSE, &game->img_x, &game->img_y);
}

/* Function: load_images_blood_1_3
 * --------------------------------
 * Loads the first third of the blood textures into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function loads textures for blood effects from files named BLOOD_0_29 to BLOOD_10_29.
 * Each texture is loaded into a specific index of the blood texture array within the game structure.
 */
void	load_images_blood_1_3(t_game *game)
{
    game->textures.blood[0] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_0_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[1] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_1_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[2] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_2_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[3] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_3_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[4] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_4_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[5] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_5_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[6] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_6_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[7] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_7_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[8] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_8_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[9] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_9_29,
	    &game->img_x, &game->img_y);
    game->textures.blood[10] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_10_29, &game->img_x, &game->img_y);
}

/* Function: load_images_blood_2_3
 * --------------------------------
 * Loads the second third of the blood textures into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function continues loading textures for blood effects, covering files named BLOOD_11_29 to BLOOD_20_29.
 * Each texture is loaded into the subsequent index of the blood texture array within the game structure.
 */
void	load_images_blood_2_3(t_game *game)
{
    game->textures.blood[11] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_11_29, &game->img_x, &game->img_y);
    game->textures.blood[12] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_12_29, &game->img_x, &game->img_y);
    game->textures.blood[13] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_13_29, &game->img_x, &game->img_y);
    game->textures.blood[14] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_14_29, &game->img_x, &game->img_y);
    game->textures.blood[15] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_15_29, &game->img_x, &game->img_y);
    game->textures.blood[16] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_16_29, &game->img_x, &game->img_y);
    game->textures.blood[17] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_17_29, &game->img_x, &game->img_y);
    game->textures.blood[18] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_18_29, &game->img_x, &game->img_y);
    game->textures.blood[19] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_19_29, &game->img_x, &game->img_y);
    game->textures.blood[20] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_20_29, &game->img_x, &game->img_y);
}

/* Function: load_images_blood_3_3
 * --------------------------------
 * Loads the final third of the blood textures into the game's texture array.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * This function completes the loading of textures for blood effects, covering files named BLOOD_21_29 to BLOOD_29_29.
 * Each texture is loaded into the final indexes of the blood texture array within the game structure.
 */
void	load_images_blood_3_3(t_game *game)
{
    game->textures.blood[21] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_21_29, &game->img_x, &game->img_y);
    game->textures.blood[22] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_22_29, &game->img_x, &game->img_y);
    game->textures.blood[23] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_23_29, &game->img_x, &game->img_y);
    game->textures.blood[24] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_24_29, &game->img_x, &game->img_y);
    game->textures.blood[25] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_25_29, &game->img_x, &game->img_y);
    game->textures.blood[26] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_26_29, &game->img_x, &game->img_y);
    game->textures.blood[27] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_27_29, &game->img_x, &game->img_y);
    game->textures.blood[28] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_28_29, &game->img_x, &game->img_y);
    game->textures.blood[29] = mlx_xpm_file_to_image(game->mlx_ptr,
	    BLOOD_29_29, &game->img_x, &game->img_y);
}
