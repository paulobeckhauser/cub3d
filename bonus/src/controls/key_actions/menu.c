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
	destroy_images(game);
	mlx_destroy_image(game->mlx_ptr, game->image.img);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	free(game->data.player);
	free(game->data.texture_north);
	free(game->data.texture_south);
	free(game->data.texture_west);
	free(game->data.texture_east);
	free_2d_array(game->data.map_element);
	free_2d_array(game->data.cub_file);
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
