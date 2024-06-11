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
}