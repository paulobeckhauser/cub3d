/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/07 15:51:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

void load_images_from_dir(t_game *game)
{
	game->north_texture = mlx_xpm_file_to_image(game->mlx_ptr, NORTH_TEXTURE, &game->img_x, &game->img_y);
	game->south_texture = mlx_xpm_file_to_image(game->mlx_ptr, SOUTH_TEXTURE, &game->img_x, &game->img_y);
	game->west_texture = mlx_xpm_file_to_image(game->mlx_ptr, WEST_TEXTURE, &game->img_x, &game->img_y);
	game->east_texture = mlx_xpm_file_to_image(game->mlx_ptr, EAST_TEXTURE, &game->img_x, &game->img_y);
}