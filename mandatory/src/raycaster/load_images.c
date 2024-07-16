/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/16 12:49:43 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	load_images_from_dir(t_game *game)
{
	game->north_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data->texture_north, &game->img_x, &game->img_y);
	game->south_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data->texture_south, &game->img_x, &game->img_y);
	game->west_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data->texture_west, &game->img_x, &game->img_y);
	game->east_texture = mlx_xpm_file_to_image(game->mlx_ptr,
			game->data->texture_east, &game->img_x, &game->img_y);
}
