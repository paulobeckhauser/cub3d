/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:25:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 20:01:47 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* Function: init_game
Initializes the game structure with default values and setups.
game: A pointer to the game structure to be initialized.
This function initializes various components of the game, including the MLX library,
image handling, utility variables, and game state variables. It also resets the states 
of keys, doors, and enemies, and calculates directional vectors for the player's movement. */
void	init_game(t_game *game)
{
	int	i;

	init_mlx(game);
	init_image(game);
	init_utils(game);
	game->animation.door_are_opening = false;
	game->animation.door_are_closing = false;
	game->animation.hp_frame_updated = false;
	game->animation.animation_gun = false;
	i = 0;
	while (i < NUM_KEYS)
		game->keys[i++] = false;
	i = 0;
	while (i < DEPTH_MAX)
	{
		game->door[i].y = 0;
		game->door[i].x = 0;
		game->enemy[i].x = 0;
		game->enemy[i].y = 0;
		game->enemy[i].dead = false;
		++i;
	}
	calc_dir_vectors(game);
}

/* Function: init_utils
Initializes utility variables within the game structure based on the player's starting direction.
game: A pointer to the game structure containing utility variables to be initialized.
This function sets the initial main ray angle based on the player's starting direction, 
initializes ray collision points, and sets default values for various game state flags and counters. */
void	init_utils(t_game *game)
{
	if (game->data.player->direction == 'N')
		game->ray_main_angle = 0.75f * ANGLE_MAX;
	else if (game->data.player->direction == 'W')
		game->ray_main_angle = 0.5f * ANGLE_MAX;
	else if (game->data.player->direction == 'S')
		game->ray_main_angle = 0.25f * ANGLE_MAX;
	else
		game->ray_main_angle = 0;
	game->ray_hit_x = 0;
	game->ray_hit_y = 0;
	game->ray_new_x = 0;
	game->ray_new_y = 0;
	game->dist_idx = 0;
	game->wall_direction = 0;
	game->door_direction = 0;
	game->img_x = 0;
	game->img_y = 0;
	game->mouse_x = 0;
	game->player_dead = false;
	game->main_menu = true;
	game->enemy_count = 0;
	game->won_game = false;
	game->player = PABECKHA;
}

/* Function: init_image
Initializes the image structure within the game structure for rendering.
game: A pointer to the game structure containing the image structure to be initialized.
This function creates a new image using the MLX library, sets the image properties such 
as bits per pixel, line length, and endian, and stores the address of the image
data for later access. */
void	init_image(t_game *game)
{
	game->image.img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->image.bits_per_pixel = 32;
	game->image.line_length = SCREEN_WIDTH;
	game->image.endian = 0;
	game->image.data = (int *)mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
}

/* Function: init_mlx
Initializes the MiniLibX library and creates a new window for the game.
game: A pointer to the game structure containing the MLX pointers to be initialized.
This function initializes the MLX library and creates a new window with a specified 
width and height. It exits the program if the initialization fails. */
void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		perror("mlx");
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3d");
	if (!game->win_ptr)
	{
		perror("mlx window");
		exit(EXIT_FAILURE);
	}
}

/* Function: calc_dir_vectors
Calculates directional vectors for player movement based on rotation speed and the main ray angle.
game: A pointer to the game structure containing the vectors array to be filled.
This function calculates the directional vectors for player movement by iterating over angles
incremented by the rotation speed, converting these angles to radians, and then calculating the 
cosine and sine for each angle to get the x and y components of each vector. */
void	calc_dir_vectors(t_game *game)
{
	float	angle_incr_radians;
	float	angle_iter;

	angle_incr_radians = to_radians(ROTATION_SPEED);
	angle_iter = to_radians(game->ray_main_angle);
	if (angle_iter < 0)
		angle_iter += 2 * M_PI;
	else if (angle_iter > 2 * M_PI)
		angle_iter -= 2 * M_PI;
	game->vec_idx = 0;
	while (game->vec_idx < ANGLE_MAX / ROTATION_SPEED)
	{
		game->vectors[game->vec_idx].x = cosf(angle_iter);
		game->vectors[game->vec_idx].y = sinf(angle_iter);
		game->vec_idx++;
		angle_iter += angle_incr_radians;
		if (angle_iter >= 2 * M_PI)
			angle_iter -= 2 * M_PI;
	}
	game->vec_idx = 0;
}
