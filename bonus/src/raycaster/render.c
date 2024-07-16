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

void	render_game(t_game *game)
{
	render_background(game);
	raycaster(game);
	render_crosshair(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image->img, 0, 0);
	render_minimap(game);
	render_minimap_player(game);
	render_gun(game);
	render_hp(game);
}

void	render_background(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++] = game->data->color_ceiling;
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
			game->image->data[y * SCREEN_WIDTH + x++] = game->data->color_floor;
		y++;
	}
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
						color = get_pixel_color(game->textures->wall_texture, tex_x, tex_y);
					else
						color = get_pixel_color(game->textures->floor_texture, tex_x, tex_y);
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
	
	int minimap_player_x = (int)(game->data->player->x / (float)SCREEN_WIDTH * 200 / ((float)SCREEN_HEIGHT / (float)SCREEN_WIDTH) - MINIMAP_SCALE);
	int minimap_player_y = (int)(game->data->player->y / (float)SCREEN_HEIGHT * 200 - MINIMAP_SCALE);
	
	tex_y = 0;
	while (tex_y < MINIMAP_SCALE)
	{
		tex_x = 0;
		while (tex_x < MINIMAP_SCALE)
		{
			color = get_pixel_color(game->textures->player_texture, tex_x, tex_y);
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

	x = SCREEN_WIDTH / 2 + 150;
	while (x < SCREEN_WIDTH / 2 + 150 + 241)
	{
		y = SCREEN_HEIGHT - 357;
		while (y < SCREEN_HEIGHT)
		{
			tex_x = x - (SCREEN_WIDTH / 2 + 150);
			tex_y = y - (SCREEN_HEIGHT - 357);
			color = get_pixel_color(game->textures->gun_current_texture, tex_x, tex_y);
			if (color != rgb_to_hex(255, 0, 255))
				game->image->data[y * SCREEN_WIDTH + x] = color;
			y++;
		}
		x++;
	}
}

void	render_hp(t_game *game)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;
	
	x = 0;
	while (x < 120)
	{
		y = SCREEN_HEIGHT - 77;
		while (y < SCREEN_HEIGHT)
		{
			tex_x = x;
			tex_y = y - (SCREEN_HEIGHT - 77);
			color = get_pixel_color(game->textures->hp_current_texture, tex_x, tex_y);
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
	if (game->wall_direction == NORTH || game->wall_direction == SOUTH)
		tex_x = (int)(game->ray_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->ray_hit_y * TEXTURE_SIZE);
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
		if (game->wall_direction == NORTH)
			color = get_pixel_color(game->textures->north_texture, tex_x, tex_y);
		else if (game->wall_direction == SOUTH)
			color = get_pixel_color(game->textures->south_texture, tex_x, tex_y);
		else if (game->wall_direction == WEST)
			color = get_pixel_color(game->textures->west_texture, tex_x, tex_y);
		else if (game->wall_direction == EAST)
			color = get_pixel_color(game->textures->east_texture, tex_x, tex_y);
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
		color = get_pixel_color(game->textures->door_current_texture, tex_x, tex_y);
		if (color != rgb_to_hex(255, 0, 255))
			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
		y_iterator++;
	}
	game->hit_opened_door = false;
	game->hit_closed_door = false;
}

void render_enemy_line(t_game *game)
{
	int line_height;
	int y_iterator;
	int y_end;
	int tex_x;
	int tex_y;
	int color;
	
	if (game->first_enemy_dist == -1)
		game->first_enemy_dist = game->dist_idx;
	line_height = (400 * TEXTURE_SIZE) / (game->enemy_dists[game->dist_idx] + 1);
	if (line_height > SCREEN_HEIGHT) line_height = SCREEN_HEIGHT;
	if (line_height < 290) line_height = 290;
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	tex_x = game->dist_idx - game->first_enemy_dist + 120;
	if (tex_x >= TEXTURE_SIZE)
		tex_x = TEXTURE_SIZE - 1;
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator - (SCREEN_HEIGHT / 2 - line_height / 2)) * TEXTURE_SIZE) / line_height;
		if (tex_y < 0) tex_y = 0;
		if (tex_y >= TEXTURE_SIZE)
			tex_y = TEXTURE_SIZE - 1;
		color = get_pixel_color(game->textures->dark_priest_current_texture, tex_x, tex_y);
		if (color != rgb_to_hex(255, 0, 255) && game->enemy_dists[game->dist_idx] < game->wall_dists[game->dist_idx]
			&& (game->open_door_visible || game->door_dists[game->dist_idx] == 0 || game->enemy_dists[game->dist_idx] < game->door_dists[game->dist_idx]))
		{
			game->body_hit[game->dist_idx] = true;
			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
		}
		y_iterator++;
	}
	game->hit_enemy = false;
}

void	render_game_over(t_game *game)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			color = get_pixel_color(game->textures->game_over_texture, x, y);
			game->image->data[y * SCREEN_WIDTH + x] = color;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image->img, 0, 0);
}
