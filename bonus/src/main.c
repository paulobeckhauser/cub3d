/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 12:53:49 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	assign_door_texture(t_game *game, int x, int y, int i)
{
	game->door[i].y = y;
	game->door[i].x = x;
	if (game->data.map_element[y][x] == '2')
		game->door[i].texture = game->textures.door_texture[0];
	else if (game->data.map_element[y][x] == '3')
		game->door[i].texture = game->textures.door_texture[4];
	else
		game->door[i].texture = game->textures.exit[0];
}

void	mark_doors(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (game->data.map_element[y])
	{
		x = 0;
		while (game->data.map_element[y][x])
		{
			if (game->data.map_element[y][x] == '2'
				|| game->data.map_element[y][x] == '3'
				|| game->data.map_element[y][x] == '6')
			{
				assign_door_texture(game, x, y, i);
				++i;
			}
			++x;
		}
		++y;
	}
}

void	mark_enemies(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (game->data.map_element[y])
	{
		x = 0;
		while (game->data.map_element[y][x])
		{
			if (game->data.map_element[y][x] == '4')
			{
				game->enemy[i].texture = game->textures.dark_priest_texture[0];
				game->enemy[i].y = y;
				game->enemy[i].x = x;
				++i;
				++game->enemy_count;
			}
			++x;
		}
		++y;
	}
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			status;

	if (argc == 2)
	{
		status = parser(argv[1], &game.data);
		if (status != 0)
			return (status);
		init_game(&game);
		load_images_from_dir(&game);
		mark_doors(&game);
		mark_enemies(&game);
		init_hooks(&game);
		render_game(&game);
		mlx_mouse_hide(game.mlx_ptr, game.win_ptr);
		mlx_loop(game.mlx_ptr);
		mlx_destroy_image(game.mlx_ptr, game.image.img);
		game.image.img = NULL;
	}
	else
	{
		print_arg_error();
		return (1);
	}
	return (status);
}
