/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 01:13:31 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:57:52 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: render_game
Renders the entire game scene or main menu depending on the game state.
game: A pointer to the game structure containing all game information and state.
This function checks the game state (main menu, player dead, or game won) and renders the main menu if any are true. Otherwise, it renders the game background, performs raycasting to determine visible walls, doors, and enemies, and then renders the crosshair, minimap, player avatar, and health points. */
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

/* Function: render_vertical
Renders vertical elements in the game scene, such as walls, doors, and enemies.
game: A pointer to the game structure containing all game information and state.
This function iterates through the depth levels of the game, checking the object type at each level (wall, door, or enemy) and calling the appropriate rendering function for each. */
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

/* Function: render_background
Renders the game's background, including the sky (ceiling) and ground (floor).
game: A pointer to the game structure containing all game information and state.
This function divides the screen in half horizontally, rendering the top half with the ceiling color and the bottom half with the floor color. */
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

/* Function: get_pixel_color
Retrieves the color of a specific pixel from an image.
img_ptr: A pointer to the image from which to retrieve the pixel color.
x: The x-coordinate of the pixel.
y: The y-coordinate of the pixel.
This function accesses the image data, calculates the position of the specified pixel, and returns its color value. */
int	get_pixel_color(void *img_ptr, int x, int y)
{
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (*(int *)(data + ((x + y * size_line / 4) * bits_per_pixel / 8)));
}
