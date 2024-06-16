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

#include "../../incl/raycaster.h"

void load_images_from_dir(t_game *game)
{
	game->north_texture = mlx_xpm_file_to_image(game->mlx_ptr, NORTH_TEXTURE, &game->img_x, &game->img_y);
	game->south_texture = mlx_xpm_file_to_image(game->mlx_ptr, SOUTH_TEXTURE, &game->img_x, &game->img_y);
	game->west_texture = mlx_xpm_file_to_image(game->mlx_ptr, WEST_TEXTURE, &game->img_x, &game->img_y);
	game->east_texture = mlx_xpm_file_to_image(game->mlx_ptr, EAST_TEXTURE, &game->img_x, &game->img_y);
	game->floor_texture = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_TEXTURE, &game->img_x, &game->img_y);
	game->wall_texture = mlx_xpm_file_to_image(game->mlx_ptr, WALL_TEXTURE, &game->img_x, &game->img_y);
	game->player_texture = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_TEXTURE, &game->img_x, &game->img_y);
	game->gun_texture = mlx_xpm_file_to_image(game->mlx_ptr, GUN_TEXTURE, &game->img_x, &game->img_y);
	game->door_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_4_4, &game->img_x, &game->img_y);
	game->door_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_3_4, &game->img_x, &game->img_y);
	game->door_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_2_4, &game->img_x, &game->img_y);
	game->door_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_1_4, &game->img_x, &game->img_y);
	game->door_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, DOOR_FRAME_0_4, &game->img_x, &game->img_y);
	game->door_current_texture = game->door_texture[0];
	game->dark_priest_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_0_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_1_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_2_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_3_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_4_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[5] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_5_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[6] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_6_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[7] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_7_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[8] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_8_9, &game->img_x, &game->img_y);
	game->dark_priest_texture[9] = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_9_9, &game->img_x, &game->img_y);
	game->dark_priest_current_texture = mlx_xpm_file_to_image(game->mlx_ptr, DARK_PRIEST_0_9, &game->img_x, &game->img_y);
}