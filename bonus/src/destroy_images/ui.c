/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:04:07 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:04:28 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	destroy_images_ui(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx_ptr, game->textures.door_minimap);
	mlx_destroy_image(game->mlx_ptr, game->textures.skull);
	mlx_destroy_image(game->mlx_ptr, game->textures.player_texture);
	i = 0;
	while (i < HP_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.hp_texture[i]);
		++i;
	}
	mlx_destroy_image(game->mlx_ptr, game->textures.main_menu[0]);
	mlx_destroy_image(game->mlx_ptr, game->textures.main_menu[1]);
	mlx_destroy_image(game->mlx_ptr, game->textures.game_over_texture);
	mlx_destroy_image(game->mlx_ptr, game->textures.win_screen);
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx_ptr, game->textures.avatar[i]);
		++i;
	}
}
