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
#include "../../libs/mlx_linux/mlx.h"
#include "../../incl/raycaster_test.h"
#include "../../incl/standard_libs.h"
#include "../../incl/structs.h"

void	draw_map(t_game *game)
{
	t_line *map_line_start;
	int	j;
	game->map_x = 0;
	game->map_y = 0;
	map_line_start = game->map_line;
	while (game->map_line)
	{
		j = 0;
		game->map_x = 0;
		while (j < game->map_line->len)
		{

			if (game->map_line->sprites[j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_floor, (int)game->map_x, (int)game->map_y);
			else if (game->map_line->sprites[j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_wall, (int)game->map_x, (int)game->map_y);
			else if (game->map_line->sprites[j] == 'N')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_floor, (int)game->map_x, (int)game->map_y);
				if (!game->player_marked)
				{
					game->player_marked = 1;
					game->player_x = game->map_x + 32;
					game->player_y = game->map_y + 32;
					game->ray_x = game->player_x;
					game->ray_y = -640;
				}
			}
			game->map_x += 64;
			j++;
		}
		game->map_y += 64;
		game->map_line = game->map_line->next;
	}
	game->map_line = map_line_start;
	draw_player(game);
	draw_ray(game);
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

void draw_ray(t_game *game)
{
	double	dir_x;
	double	dir_y;
	double	len;
	double	x_iterator;
	double	y_iterator;
	double	speed;

	dir_x = game->ray_x - game->player_x;
	dir_y = game->ray_y - game->player_y;
	len = sqrt(dir_x * dir_x + dir_y * dir_y);
	dir_x /= len;
	dir_y /= len;
	x_iterator = game->player_x;
	y_iterator = game->player_y;
	speed = 1;
	while (((dir_x >= 0 && x_iterator <= game->ray_x) || (dir_x < 0 && x_iterator >= game->ray_x))
			&& ((dir_y >= 0 && y_iterator <= game->ray_y) || (dir_y < 0 && y_iterator >= game->ray_y)))
	{
		if ((int)x_iterator % 64 == 0 || (int)y_iterator % 64 == 0)
		{
			printf("hi\n");
		}
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)x_iterator, (int)y_iterator, rgb_to_hex(255, 0, 0));
		x_iterator += dir_x * speed;
		y_iterator += dir_y * speed;
	}
}