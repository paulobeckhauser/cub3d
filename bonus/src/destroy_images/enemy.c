/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:59:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 00:59:33 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	destroy_images_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < ENEMY_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.dark_priest_texture[i]);
		++i;
	}
}

void	destroy_images_blood(t_game *game)
{
	int	i;

	i = 0;
	while (i < BLOOD_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.blood[i]);
		++i;
	}
}
