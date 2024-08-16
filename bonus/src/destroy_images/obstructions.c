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

void	destroy_images_obstructions(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx_ptr, game->textures.north_texture);
	mlx_destroy_image(game->mlx_ptr, game->textures.south_texture);
	mlx_destroy_image(game->mlx_ptr, game->textures.west_texture);
	mlx_destroy_image(game->mlx_ptr, game->textures.east_texture);
	i = 0;
	while (i < DOOR_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.door_texture[i]);
		mlx_destroy_image(game->mlx_ptr, game->textures.exit[i]);
		++i;
	}
}
