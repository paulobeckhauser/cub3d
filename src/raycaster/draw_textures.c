/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:26:48 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 15:26:49 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"
#include "../../incl/raycaster.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	game->map_x = 0;
	game->map_y = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		game->map_x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'N')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_floor, (int)game->map_x, (int)game->map_y);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_wall, (int)game->map_x, (int)game->map_y);
			game->map_x += 64;
			x++;
		}
		game->map_y += 64;
		++y;
	}
	draw_player(game);
	// draw_ray(game);
	cast_rays(game);
}

void	draw_player(const t_game *game)
{
	int	x_iterator;
	int	y_iterator;

	x_iterator = (int)game->player_x - 10;
	y_iterator = (int)game->player_y - 10;
	while (x_iterator < game->player_x + 10)
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x_iterator++, (int)game->player_y, rgb_to_hex(0, 255, 0));
	while (y_iterator < game->player_y + 10)
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)game->player_x, y_iterator++, rgb_to_hex(0, 255, 0));
}

void draw_collision(const t_game *game, double ray_x, double ray_y)
{
	int x_start = (int)ray_x - 2;
	int y_start = (int)ray_y - 2;
	int x_end = x_start + 4;
	int y_end = y_start + 4;

	for (int x = x_start; x <= x_end; x++)
	{
		for (int y = y_start; y <= y_end; y++)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, rgb_to_hex(255, 255, 0));
		}
	}
}

void draw_ray(t_game *game)
{
	double	dir_x;
	double	dir_y;
	double	len;
	double	x_iterator;
	double	y_iterator;
	double	speed;
	int		colis_x;
	int		colis_y;

	dir_x = game->ray_new_x - game->player_x;
	dir_y = game->ray_new_y - game->player_y;
	len = sqrt(dir_x * dir_x + dir_y * dir_y);
	dir_x /= len;
	dir_y /= len;
	x_iterator = game->player_x;
	y_iterator = game->player_y;
	speed = 1;
	while (((dir_x >= 0 && x_iterator <= game->ray_new_x) || (dir_x < 0 && x_iterator >= game->ray_new_x))
			&& ((dir_y >= 0 && y_iterator <= game->ray_new_y) || (dir_y < 0 && y_iterator >= game->ray_new_y)))
	{
		if ((int)x_iterator % 64 == 0 || (int)y_iterator % 64 == 0)
		{
			draw_collision(game, x_iterator, y_iterator);
			if (dir_x > 0)
				colis_x = (int)x_iterator / 64;
			else
				colis_x = (int)(x_iterator - 1) / 64;
			if (dir_y > 0)
				colis_y = (int)y_iterator / 64;
			else
				colis_y = (int)(y_iterator - 1) / 64;
			if (game->map[colis_y][colis_x] == '1')
				return ;
		}
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)x_iterator, (int)y_iterator, rgb_to_hex(255, 0, 0));
		x_iterator += dir_x * speed;
		y_iterator += dir_y * speed;
	}
}