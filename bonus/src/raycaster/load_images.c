/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 16:33:21 by sfrankie         ###   ########.fr       */
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
	game->textures->gun_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, GUN_0_4, &game->img_x, &game->img_y);
	game->textures->gun_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, GUN_1_4, &game->img_x, &game->img_y);
	game->textures->gun_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, GUN_2_4, &game->img_x, &game->img_y);
	game->textures->gun_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, GUN_3_4, &game->img_x, &game->img_y);
	game->textures->gun_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, GUN_4_4, &game->img_x, &game->img_y);
	game->textures->gun_current_texture = mlx_xpm_file_to_image(game->mlx_ptr, GUN_0_4, &game->img_x, &game->img_y);
	game->textures->door_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_4_4, &game->img_x, &game->img_y);
	game->textures->door_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_3_4, &game->img_x, &game->img_y);
	game->textures->door_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_2_4, &game->img_x, &game->img_y);
	game->textures->door_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_1_4, &game->img_x, &game->img_y);
	game->textures->door_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_0_4, &game->img_x, &game->img_y);
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
	game->textures->dark_priest_current_texture = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_0_9, &game->img_x, &game->img_y);
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
}