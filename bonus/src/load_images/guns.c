/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:56:30 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 00:58:03 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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
