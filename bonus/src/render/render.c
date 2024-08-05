/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:13:31 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:27:30 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	render_game(t_game *game)
{
	if (game->main_menu || game->player_dead || game->won_game)
		render_main_menu(game);
	else
	{
		render_background(game);
		raycaster(game);
		render_crosshair(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.img,
			0, 0);
		render_minimap_bg(game);
		render_minimap(game);
		render_minimap_player(game);
		if (game->player == PABECKHA)
			render_gun(game);
		else
			render_gun(game);
		render_hp(game);
		render_avatar(game);
	}
}

void	render_vertical(t_game *game)
{
	while (game->depth_lvl >= 0)
	{
		if (game->depth[game->depth_lvl].obj == WALL)
			render_wall_line(game);
		else if (game->depth[game->depth_lvl].obj == DOOR)
			render_door_line(game);
		else if (game->depth[game->depth_lvl].obj == ENEMY)
			render_enemy_line(game, find_enemy(game));
		--game->depth_lvl;
	}
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image.data[y * SCREEN_WIDTH
				+ x++] = game->data.color_ceiling;
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image.data[y * SCREEN_WIDTH + x++] = game->data.color_floor;
		y++;
	}
}

int	get_pixel_color(void *img_ptr, int x, int y)
{
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (*(int *)(data + ((x + y * size_line / 4) * bits_per_pixel / 8)));
}
