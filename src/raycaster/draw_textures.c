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

#include <stdio.h>

#include "../../incl/cub3d.h"
#include "../../incl/raycaster_test.h"
#include "../../incl/structs.h"
#include "../../libs/mlx_linux/mlx.h"

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
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->txt_player, (int)game->map_x, (int)game->map_y);
					game->player_marked = 1;
					game->player_x = game->map_x;
					game->player_y = game->map_y;
				}
			}
			game->map_x += 64;
			j++;
		}
		game->map_y += 64;
		game->map_line = game->map_line->next;
	}
	game->map_line = map_line_start;
	// draw_ray(game);
}

void	draw_ray(t_game *game)
{
	t_line	*line_start;

	line_start = game->map_line;
	while (game->ray_y > 0)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->ray_x, game->ray_y, rgb_to_hex(255, 0, 0));
		--game->ray_y;
		if ((int)game->ray_y % 64 == 0)
		{
			printf("ray_x: %f\n", game->ray_x);
			printf("ray_y: %f\n", game->ray_y);
			int sprites_idx = (int)game->ray_x / 64;
			int map_line_idx = (int)game->ray_y / 64 - 1;
			printf("sprites idx: %i\n", sprites_idx);
			printf("map line idx: %i\n", map_line_idx);
			while (game->map_line && game->map_line->idx != map_line_idx)
				game->map_line = game->map_line->next;
			printf("element: %c\n", game->map_line->sprites[sprites_idx]);
			if (game->map_line->sprites[sprites_idx] == '1')
			{
				printf("return\n");
				return;
			}
			game->map_line = line_start;
		}
	}
}

// void	draw_ray(t_game *game)
// {
// 	t_image image;
// 	image.img = mlx_new_image(game->mlx_ptr, 639, 639);
// 	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
// 	game->ray_x = game->player_x + 8;
// 	game->ray_y = game->player_y + 8;
// 	while (game->ray_y < game->player_y + 100)
// 	{
// 		*(int*)(image.addr + (((int)game->ray_x + (int)game->ray_y * 639) * 4)) = rgb_to_hex(255, 0, 0);
// 		++game->ray_y;
// 	}
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image.img, 0, 0);
// 	mlx_destroy_image(game->mlx_ptr, image.img);
// }