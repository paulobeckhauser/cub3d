/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:00:43 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:02:50 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	load_images_wall(t_game *game)
{
	game->textures.north_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data.texture_north, &game->img_x, &game->img_y);
	game->textures.south_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data.texture_south, &game->img_x, &game->img_y);
	game->textures.west_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data.texture_west, &game->img_x, &game->img_y);
	game->textures.east_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data.texture_east, &game->img_x, &game->img_y);
}

void	load_images_door(t_game *game)
{
	game->textures.door_texture[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			DOOR_FRAME_4_4, &game->img_x, &game->img_y);
	game->textures.door_texture[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			DOOR_FRAME_3_4, &game->img_x, &game->img_y);
	game->textures.door_texture[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			DOOR_FRAME_2_4, &game->img_x, &game->img_y);
	game->textures.door_texture[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			DOOR_FRAME_1_4, &game->img_x, &game->img_y);
	game->textures.door_texture[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			DOOR_FRAME_0_4, &game->img_x, &game->img_y);
	game->textures.exit[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_4_4, &game->img_x, &game->img_y);
	game->textures.exit[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_3_4, &game->img_x, &game->img_y);
	game->textures.exit[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_2_4, &game->img_x, &game->img_y);
	game->textures.exit[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_1_4, &game->img_x, &game->img_y);
	game->textures.exit[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_0_4, &game->img_x, &game->img_y);
}
