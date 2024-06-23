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

void	render_map(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++] = rgb_to_hex(50, 50, 170); // Very dark blue
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++]
					= rgb_to_hex((int)(20 + (y - SCREEN_HEIGHT / 2) * 0.01), // Dark gradient from blue to violet
					             (int)(10 + (y - SCREEN_HEIGHT / 2) * 0.01),
					             (int)(40 + (y - SCREEN_HEIGHT / 2) * 0.01));
		y++;
	}
	raycaster(game);
	render_crosshair(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image->img, 0, 0);
	render_minimap(game);
	render_minimap_player(game);
	render_gun(game);
}

void    render_minimap(t_game *game)
{
	int map_x;
	int map_y;
	int tex_x;
	int tex_y;
	int color;
	
	map_y = 0;
	while (map_y < 10)
	{
		map_x = 0;
		while (map_x < 10)
		{
			tex_y = 0;
			while (tex_y < MINIMAP_SCALE)
			{
				tex_x = 0;
				while (tex_x < MINIMAP_SCALE)
				{
					if (game->map[map_y][map_x] == '1')
						color = get_pixel_color(game->wall_texture, tex_x, tex_y);
					else
						color = get_pixel_color(game->floor_texture, tex_x, tex_y);
					game->image->data[(map_y * MINIMAP_SCALE + tex_y) * SCREEN_WIDTH + (map_x * MINIMAP_SCALE + tex_x)] = color;
					tex_x++;
				}
				tex_y++;
			}
			map_x++;
		}
		map_y++;
	}
}

void    render_minimap_player(t_game *game)
{
	int tex_x;
	int tex_y;
	int color;
	
	int minimap_player_x = (int)(game->player_x / (float)SCREEN_WIDTH * 200 / ((float)SCREEN_HEIGHT / (float)SCREEN_WIDTH) - MINIMAP_SCALE);
	int minimap_player_y = (int)(game->player_y / (float)SCREEN_HEIGHT * 200 - MINIMAP_SCALE);
	
	tex_y = 0;
	while (tex_y < MINIMAP_SCALE)
	{
		tex_x = 0;
		while (tex_x < MINIMAP_SCALE)
		{
			color = get_pixel_color(game->player_texture, tex_x, tex_y);
			game->image->data[(minimap_player_y + tex_y) * SCREEN_WIDTH + (minimap_player_x + tex_x)] = color;
			tex_x++;
		}
		tex_y++;
	}
}

void	render_gun(t_game *game)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	x = SCREEN_WIDTH / 2 + 100;
	while (x < SCREEN_WIDTH / 2 + 100 + 357)
	{
		y = SCREEN_HEIGHT - 357;
		while (y < SCREEN_HEIGHT)
		{
			tex_x = x - (SCREEN_WIDTH / 2 + 100);
			tex_y = y - (SCREEN_HEIGHT - 357);
			color = get_pixel_color(game->gun_texture, tex_x, tex_y);
			if (color != rgb_to_hex(255, 0, 255))
				game->image->data[y * SCREEN_WIDTH + x] = color;
			y++;
		}
		x++;
	}
}

void	render_crosshair(t_game *game)
{
	int	x;
	int	y;

	(void)game;
	x = SCREEN_WIDTH / 2 - 10.0;
	y = SCREEN_HEIGHT / 2 - 10.0;
	while (x < SCREEN_WIDTH / 2 + 10)
		game->image->data[SCREEN_HEIGHT / 2 * SCREEN_WIDTH + x++] = rgb_to_hex(0, 255, 0);
	while (y < SCREEN_HEIGHT / 2 + 10)
		game->image->data[y++ * SCREEN_WIDTH + SCREEN_WIDTH / 2] = rgb_to_hex(0, 255, 0);
}

void    render_wall_line(t_game *game)
{
	int line_height;
	int y_iterator;
	int y_end;
	int tex_x;
	int	tex_y;
	int color;
	
	line_height = DRAWING_SCALE / (game->wall_dists[game->dist_idx] + 1);
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	// Calculate tex_x based on where the ray hit the wall block
	if (game->wall_direction == NORTH || game->wall_direction == SOUTH)
		tex_x = (int)(game->ray_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->ray_hit_y * TEXTURE_SIZE);
	while (y_iterator < y_end)
	{
		// Calculate tex_y based on the current y_iterator value
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
//		if (game->hit_closed_door)
//			color = get_pixel_color(game->door_current_texture, tex_x, tex_y);
		if (game->wall_direction == NORTH)
			color = get_pixel_color(game->north_texture, tex_x, tex_y);
		else if (game->wall_direction == SOUTH)
			color = get_pixel_color(game->south_texture, tex_x, tex_y);
		else if (game->wall_direction == WEST)
			color = get_pixel_color(game->west_texture, tex_x, tex_y);
		else if (game->wall_direction == EAST)
			color = get_pixel_color(game->east_texture, tex_x, tex_y);
		if (color != rgb_to_hex(255, 0, 255))
			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
		y_iterator++;
	}
}

void    render_door_line(t_game *game)
{
	int line_height;
	int y_iterator;
	int y_end;
	int tex_x;
	int	tex_y;
	int color;
	
	line_height = DRAWING_SCALE / (game->door_dists[game->dist_idx] + 1);
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	if (game->door_direction == NORTH || game->door_direction == SOUTH)
		tex_x = (int)(game->ray_door_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->ray_door_hit_y * TEXTURE_SIZE);
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
		color = get_pixel_color(game->door_current_texture, tex_x, tex_y);
		if (color != rgb_to_hex(255, 0, 255))
			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
		y_iterator++;
	}
	game->hit_opened_door = false;
	game->hit_closed_door = false;
}

// void    render_enemy_line(t_game *game)
// {
// 	int line_height;
// 	int y_iterator;
// 	int y_end;
// 	int tex_x;
// 	int	tex_y;
// 	int color;
//
// 	line_height = DRAWING_SCALE / (game->enemy_dists[game->dist_idx] + 1);
// 	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
// 	if (y_iterator < 0)
// 		y_iterator = 0;
// 	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
// 	if (y_end > SCREEN_HEIGHT)
// 		y_end = SCREEN_HEIGHT;
// 	tex_x = game->dist_idx;
// 	while (y_iterator < y_end)
// 	{
// 		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
// 		color = get_pixel_color(game->dark_priest_current_texture, tex_x, tex_y);
// 		if (color != rgb_to_hex(255, 0, 255))
// 			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
// 		y_iterator++;
// 	}
// 	game->hit_enemy = false;
// }


void render_enemy_line(t_game *game)
{
	int x_iterator;
	int y_iterator;
	int tex_x;
	int tex_y;
	int color;
	int line_height;

	line_height = DRAWING_SCALE / (game->enemy_dists[game->dist_idx] + 1);
	if (line_height > 500)
		line_height = 500;
	x_iterator = game->dist_idx;
	// while (x_iterator < game->dist_idx + 500 && x_iterator < SCREEN_WIDTH)
	// {
		y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
		while (y_iterator < SCREEN_HEIGHT / 2 + line_height / 2 && y_iterator < SCREEN_HEIGHT)
		{
			tex_x = game->dist_idx - x_iterator + 150;
			if (tex_x < 0)
				tex_x = 0;
			if (tex_x > 500)
				break;
			tex_y = y_iterator - (SCREEN_HEIGHT / 2 - line_height / 2);
			color = get_pixel_color(game->dark_priest_current_texture, tex_x, tex_y);
			if (color != rgb_to_hex(255, 0, 255) && game->hit_enemy)
				printf("%i\n", game->dist_idx),game->image->data[y_iterator * SCREEN_WIDTH + x_iterator] = color;
			y_iterator++;
		}
		x_iterator++;
	// }
	game->hit_enemy = false;
}

// try this

// void drawEnemy(t_game *game, Enemy* enemy, Player* player) {
	// Calculate distance from the player to the enemy
	// enemy->distance = sqrtf((enemy->x - player->x) * (enemy->x - player->x) + (enemy->y - player->y) * (enemy->y - player->y));

	// Calculate enemy's angle relative to the player's viewing direction
	// float dx = enemy->x - player->x;
	// float dy = enemy->y - player->y;
	// float angleToPlayer = atan2(dy, dx) - player->fov;

	// Convert angle to screen position
	// float enemyScreenX = tan(angleToPlayer) * SCREEN_WIDTH;

	// Calculate scale based on distance (simple perspective)
	// float scale = 100.0f / enemy->distance; // Arbitrary scale factor for demonstration

	// Calculate the height and width of the enemy sprite on screen
	// int enemyHeight = (int)(SCREEN_HEIGHT * scale);
	// int enemyWidth = (int)(SCREEN_HEIGHT * scale);

	// Calculate the top left position
	// int screenX = (int)(SCREEN_WIDTH / 2 + enemyScreenX - enemyWidth / 2);
	// int screenY = SCREEN_HEIGHT / 2 - enemyHeight / 2;

	// Draw the enemy sprite using your method
	// int x, y, tex_x, tex_y, color;
	// for (x = screenX; x < screenX + enemyWidth; x++) {
		// for (y = screenY; y < screenY + enemyHeight; y++) {
			// tex_x = (x - screenX) * (500 / enemyWidth); // Assuming the enemy texture width is 500 pixels
			// tex_y = (y - screenY) * (357 / enemyHeight); // Assuming the enemy texture height is 357 pixels
			// color = get_pixel_color(game->enemy_texture, tex_x, tex_y); // Assuming each enemy has an 'enemy_texture'
			// if (color != rgb_to_hex(255, 0, 255)) // Assuming magenta is the transparency color
				// game->image->data[y * SCREEN_WIDTH + x] = color;
		// }
	// }
// }