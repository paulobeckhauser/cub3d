/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/28 19:01:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void    init_image(t_image *image, t_game *game)
{
	image->img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	image->bits_per_pixel = 32;
	image->line_length = SCREEN_WIDTH;
	image->endian = 0;
	image->data = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

void    mark_doors(t_game *game)
{
	int y;
	int x;
	int i;
	
	y = 0;
	i = 0;
	while (game->data->map_element[y])
	{
		x = 0;
		while (game->data->map_element[y][x])
		{
			if (game->data->map_element[y][x] == '2' || game->data->map_element[y][x] == '3')
			{
				game->door[i].dist = 0;
				game->door[i].y = y;
				game->door[i].x = x;
				if (game->data->map_element[y][x] == '2')
					game->door[i].texture = game->textures->door_texture[0];
				else
					game->door[i].texture = game->textures->door_texture[4];
				++i;
			}
			++x;
		}
		++y;
	}
}

void    mark_enemies(t_game *game)
{
	int y;
	int x;
	int i;
	
	y = 0;
	i = 0;
	while (game->data->map_element[y])
	{
		x = 0;
		while (game->data->map_element[y][x])
		{
			if (game->data->map_element[y][x] == '4')
			{
				game->enemy[i].texture = game->textures->dark_priest_texture[0];
				game->enemy[i].y = y;
				game->enemy[i].x = x;
				game->enemy[i].size = 0;
				++i;
			}
			++x;
		}
		++y;
	}
}

int main(int argc, char **argv)
{
    t_game      game;
	t_textures	textures;
	t_image     image;
	t_vectors   vectors[ANGLE_MAX / ROTATION_SPEED];
	t_data		data;
	int status;
	
	status = 0;
	if (argc == 2)
	{
		status = parser(argv[1], &data);
		if (status != 0)
			return(status);
		game.data = &data;
		init_game(&game);
		init_image(&image, &game);
		game.image = &image;
		game.vectors = vectors;
		game.textures = &textures;
		calc_dir_vectors(&game);
		load_images_from_dir(&game);
		mark_doors(&game);
		mark_enemies(&game);
		init_hooks(&game);
		render_game(&game);
		mlx_mouse_hide(game.mlx_ptr, game.win_ptr);
		mlx_loop(game.mlx_ptr);
		free(game.map);
		mlx_destroy_image(game.mlx_ptr, image.img);
		image.img = NULL;
	}
	else
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		ft_putstr_fd(RESET, 2);
		return (1);
	}

    return (status);
}
