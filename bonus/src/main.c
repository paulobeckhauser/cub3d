/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 20:09:02 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* Function: assign_door_texture
Assigns textures to door elements in the game map.
game: A pointer to the game structure containing all game information and state.
x: The x-coordinate of the door position.
y: The y-coordinate of the door position.
i: The index of the door in the game's door array.
This function checks the type of door based on the map element value ('2', '3',
or other) and assigns the corresponding texture from the game's texture resources. */
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

/* Function: mark_doors
Identifies and marks door positions in the game map.
game: A pointer to the game structure containing all game information and state.
This function iterates through the game map, identifies door elements (marked as '2', '3', 
or '6'), and calls assign_door_texture to assign the correct texture to each door.
 It also increments the door index for each door found. */
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

/* Function: mark_enemies
Identifies and marks enemy positions in the game map.
game: A pointer to the game structure containing all game information and state.
This function iterates through the game map, identifies enemy elements (marked as '4'),
assigns the correct texture to each enemy, and updates the game's enemy count. */
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

/* Function: main
The main function of the game.
argc: The number of command-line arguments.
argv: The array of command-line arguments.
This function initializes the game by parsing the map file,
initializing the game structure, loading images, marking doors and enemies,
setting up hooks, rendering the game, and starting the game loop. If the
 number of command-line arguments is incorrect, it prints an error message. */
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
