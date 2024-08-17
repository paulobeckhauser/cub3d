/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:56:30 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/17 13:45:47 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	destroy_images_guns(t_game *game)
{
	int	i;

	i = 0;
	while (i < DESERT_EAGLE_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.desert_eagle[i]);
		++i;
	}
	i = 0;
	while (i < GUN_RUN_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.desert_eagle_run[i]);
		mlx_destroy_image(game->mlx_ptr, game->textures.shotgun_run[i]);
		++i;
	}
	i = 0;
	while (i < SHOTGUN_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.shotgun[i]);
		++i;
	}
}
