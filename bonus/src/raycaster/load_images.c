/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/30 17:23:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void load_images_from_dir(t_game *game)
{
	game->textures->north_texture = mlx_xpm_file_to_image(game->mlx_ptr, game->data->texture_north, &game->img_x, &game->img_y);
	game->textures->south_texture = mlx_xpm_file_to_image(game->mlx_ptr, game->data->texture_south, &game->img_x, &game->img_y);
	game->textures->west_texture = mlx_xpm_file_to_image(game->mlx_ptr, game->data->texture_west, &game->img_x, &game->img_y);
	game->textures->east_texture = mlx_xpm_file_to_image(game->mlx_ptr, game->data->texture_east, &game->img_x, &game->img_y);
	game->textures->door_minimap = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_MINIMAP, &game->img_x, &game->img_y);
	game->textures->skull = mlx_xpm_file_to_image(game->mlx_ptr, SKULL, &game->img_x, &game->img_y);
	game->textures->player_texture = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_TEXTURE, &game->img_x, &game->img_y);
	game->textures->desert_eagle[0] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_0_4, &game->img_x, &game->img_y);
	game->textures->desert_eagle[1] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_1_4, &game->img_x, &game->img_y);
	game->textures->desert_eagle[2] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_2_4, &game->img_x, &game->img_y);
	game->textures->desert_eagle[3] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_3_4, &game->img_x, &game->img_y);
	game->textures->desert_eagle[4] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_4_4, &game->img_x, &game->img_y);
	game->textures->desert_eagle_run[0] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_RUN_0_1, &game->img_x, &game->img_y);
	game->textures->desert_eagle_run[1] = mlx_xpm_file_to_image(game->mlx_ptr, DESERT_EAGLE_RUN_1_1, &game->img_x, &game->img_y);
	game->textures->shotgun[0] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_0_14, &game->img_x, &game->img_y);
	game->textures->shotgun[1] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_1_14, &game->img_x, &game->img_y);
	game->textures->shotgun[2] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_2_14, &game->img_x, &game->img_y);
	game->textures->shotgun[3] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_3_14, &game->img_x, &game->img_y);
	game->textures->shotgun[4] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_4_14, &game->img_x, &game->img_y);
	game->textures->shotgun[5] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_5_14, &game->img_x, &game->img_y);
	game->textures->shotgun[6] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_6_14, &game->img_x, &game->img_y);
	game->textures->shotgun[7] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_7_14, &game->img_x, &game->img_y);
	game->textures->shotgun[8] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_8_14, &game->img_x, &game->img_y);
	game->textures->shotgun[9] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_9_14, &game->img_x, &game->img_y);
	game->textures->shotgun[10] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_10_14, &game->img_x, &game->img_y);
	game->textures->shotgun[11] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_11_14, &game->img_x, &game->img_y);
	game->textures->shotgun[12] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_12_14, &game->img_x, &game->img_y);
	game->textures->shotgun[13] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_13_14, &game->img_x, &game->img_y);
	game->textures->shotgun[14] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_14_14, &game->img_x, &game->img_y);
	game->textures->shotgun_run[0] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_RUN_0_1, &game->img_x, &game->img_y);
	game->textures->shotgun_run[1] = mlx_xpm_file_to_image(game->mlx_ptr, SHOTGUN_RUN_1_1, &game->img_x, &game->img_y);
	game->textures->gun_current_texture = game->textures->shotgun[0];
	game->textures->door_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_4_4, &game->img_x, &game->img_y);
	game->textures->door_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_3_4, &game->img_x, &game->img_y);
	game->textures->door_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_2_4, &game->img_x, &game->img_y);
	game->textures->door_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_1_4, &game->img_x, &game->img_y);
	game->textures->door_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_0_4, &game->img_x, &game->img_y);
	game->textures->exit[0] = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_4_4, &game->img_x, &game->img_y);
	game->textures->exit[1] = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_3_4, &game->img_x, &game->img_y);
	game->textures->exit[2] = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_2_4, &game->img_x, &game->img_y);
	game->textures->exit[3] = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_1_4, &game->img_x, &game->img_y);
	game->textures->exit[4] = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_0_4, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_0_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_1_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_2_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_3_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_4_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[5] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_5_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[6] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_6_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[7] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_7_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[8] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_8_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[9] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_9_9, &game->img_x, &game->img_y);
	game->textures->dark_priest_texture[10] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_CORPSE, &game->img_x, &game->img_y);
	game->textures->dark_priest_current_texture = game->textures->dark_priest_texture[0];
	game->textures->hp_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, HP_0, &game->img_x, &game->img_y);
	game->textures->hp_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, HP_10, &game->img_x, &game->img_y);
	game->textures->hp_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, HP_20, &game->img_x, &game->img_y);
	game->textures->hp_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, HP_30, &game->img_x, &game->img_y);
	game->textures->hp_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, HP_40, &game->img_x, &game->img_y);
	game->textures->hp_texture[5] = mlx_xpm_file_to_image(game->mlx_ptr, HP_50, &game->img_x, &game->img_y);
	game->textures->hp_texture[6] = mlx_xpm_file_to_image(game->mlx_ptr, HP_60, &game->img_x, &game->img_y);
	game->textures->hp_texture[7] = mlx_xpm_file_to_image(game->mlx_ptr, HP_70, &game->img_x, &game->img_y);
	game->textures->hp_texture[8] = mlx_xpm_file_to_image(game->mlx_ptr, HP_80, &game->img_x, &game->img_y);
	game->textures->hp_texture[9] = mlx_xpm_file_to_image(game->mlx_ptr, HP_90, &game->img_x, &game->img_y);
	game->textures->hp_texture[10] = mlx_xpm_file_to_image(game->mlx_ptr, HP_100, &game->img_x, &game->img_y);
	game->textures->hp_current_texture = mlx_xpm_file_to_image(game->mlx_ptr, HP_100, &game->img_x, &game->img_y);
	game->textures->game_over_texture = mlx_xpm_file_to_image(game->mlx_ptr, GAME_OVER, &game->img_x, &game->img_y);
	game->textures->win_screen = mlx_xpm_file_to_image(game->mlx_ptr, WIN_SCREEN, &game->img_x, &game->img_y);
	game->textures->blood[0] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_0_29, &game->img_x, &game->img_y);
	game->textures->blood[1] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_1_29, &game->img_x, &game->img_y);
	game->textures->blood[2] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_2_29, &game->img_x, &game->img_y);
	game->textures->blood[3] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_3_29, &game->img_x, &game->img_y);
	game->textures->blood[4] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_4_29, &game->img_x, &game->img_y);
	game->textures->blood[5] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_5_29, &game->img_x, &game->img_y);
	game->textures->blood[6] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_6_29, &game->img_x, &game->img_y);
	game->textures->blood[7] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_7_29, &game->img_x, &game->img_y);
	game->textures->blood[8] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_8_29, &game->img_x, &game->img_y);
	game->textures->blood[9] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_9_29, &game->img_x, &game->img_y);
	game->textures->blood[10] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_10_29, &game->img_x, &game->img_y);
	game->textures->blood[11] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_11_29, &game->img_x, &game->img_y);
	game->textures->blood[12] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_12_29, &game->img_x, &game->img_y);
	game->textures->blood[13] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_13_29, &game->img_x, &game->img_y);
	game->textures->blood[14] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_14_29, &game->img_x, &game->img_y);
	game->textures->blood[15] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_15_29, &game->img_x, &game->img_y);
	game->textures->blood[16] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_16_29, &game->img_x, &game->img_y);
	game->textures->blood[17] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_17_29, &game->img_x, &game->img_y);
	game->textures->blood[18] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_18_29, &game->img_x, &game->img_y);
	game->textures->blood[19] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_19_29, &game->img_x, &game->img_y);
	game->textures->blood[20] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_20_29, &game->img_x, &game->img_y);
	game->textures->blood[21] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_21_29, &game->img_x, &game->img_y);
	game->textures->blood[22] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_22_29, &game->img_x, &game->img_y);
	game->textures->blood[23] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_23_29, &game->img_x, &game->img_y);
	game->textures->blood[24] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_24_29, &game->img_x, &game->img_y);
	game->textures->blood[25] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_25_29, &game->img_x, &game->img_y);
	game->textures->blood[26] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_26_29, &game->img_x, &game->img_y);
	game->textures->blood[27] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_27_29, &game->img_x, &game->img_y);
	game->textures->blood[28] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_28_29, &game->img_x, &game->img_y);
	game->textures->blood[29] = mlx_xpm_file_to_image(game->mlx_ptr, BLOOD_29_29, &game->img_x, &game->img_y);
	game->textures->avatar[0] = mlx_xpm_file_to_image(game->mlx_ptr, AVATAR_PAULO_0_1, &game->img_x, &game->img_y);
	game->textures->avatar[1] = mlx_xpm_file_to_image(game->mlx_ptr, AVATAR_PAULO_1_1, &game->img_x, &game->img_y);
	game->textures->avatar[2] = mlx_xpm_file_to_image(game->mlx_ptr, AVATAR_SZYMON_0_1, &game->img_x, &game->img_y);
	game->textures->avatar[3] = mlx_xpm_file_to_image(game->mlx_ptr, AVATAR_SZYMON_1_1, &game->img_x, &game->img_y);
	game->textures->avatar_current = game->textures->avatar[0];
	game->textures->main_menu[0] = mlx_xpm_file_to_image(game->mlx_ptr, MAIN_MENU_PABECKHA, &game->img_x, &game->img_y);
	game->textures->main_menu[1] = mlx_xpm_file_to_image(game->mlx_ptr, MAIN_MENU_SFRANKIE, &game->img_x, &game->img_y);
	game->textures->main_menu_current = mlx_xpm_file_to_image(game->mlx_ptr, MAIN_MENU_PABECKHA, &game->img_x, &game->img_y);
}
