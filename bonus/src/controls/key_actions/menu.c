/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:45:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/04 23:45:38 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	exit(0);
}

void	action_main_menu(t_game *game)
{
	if (game->keys[LEFT_ARROW])
	{
		game->player = PABECKHA;
		game->textures.main_menu_current = game->textures.main_menu[0];
		game->textures.avatar_current = game->textures.avatar[0];
		game->textures.gun_current_texture = game->textures.shotgun[0];
	}
	if (game->keys[RIGHT_ARROW])
	{
		game->player = SFRANKIE;
		game->textures.main_menu_current = game->textures.main_menu[1];
		game->textures.avatar_current = game->textures.avatar[2];
		game->textures.gun_current_texture = game->textures.desert_eagle[0];
	}
	if (game->keys[ENTER])
	{
		game->main_menu = false;
	}
}
