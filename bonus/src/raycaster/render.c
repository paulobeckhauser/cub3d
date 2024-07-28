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
	render_minimap_bg(game);
	render_minimap(game);
	render_minimap_player(game);
	render_minimap_border(game);
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

void    render_minimap_bg(t_game *game)
{
	int tex_x;
	int tex_y;
	
	tex_y = 0;
	while (tex_y < 200)
	{
		tex_x = 0;
		while (tex_x < 200)
		{
			game->image->data[tex_y * SCREEN_WIDTH + tex_x] = rgb_to_hex(0, 0, 0);
			++tex_x;
		}
		++tex_y;
	}
}

void    render_minimap(t_game *game)
{
	int screen_x;
	int screen_y;
	int map_x;
	int map_y;
	int tex_x;
	int tex_y;
	int color;
	
	screen_y = 0;
	map_y = (int)game->data->player->y / 100 - 5;
	while (screen_y < 10)
	{
		screen_x = 0;
		map_x = (int)game->data->player->x / 100 - 5;
		while (screen_x < 10)
		{
			tex_y = 0;
			while (tex_y < MINIMAP_SCALE)
			{
				tex_x = 0;
				while (tex_x < MINIMAP_SCALE)
				{
					if (map_y < 0 ||    map_y >= game->data->number_lines_map_element || !game->data->map_element[map_y] || !game->data->map_element[map_y][map_x])
						break ;
					if (game->data->map_element[map_y][map_x] == '0')
						color = rgb_to_hex(74, 17, 17);
					else if (game->data->map_element[map_y][map_x] == '1')
						color = rgb_to_hex(30, 28, 87);
					else if (game->data->map_element[map_y][map_x] == '2' || game->data->map_element[map_y][map_x] == '3')
						color = get_pixel_color(game->textures->door_minimap, tex_x, tex_y);
					else if (game->data->map_element[map_y][map_x] == '4')
						color = get_pixel_color(game->textures->skull, tex_x, tex_y);
					else
						break ;
					game->image->data[(screen_y * MINIMAP_SCALE + tex_y) * SCREEN_WIDTH + (screen_x * MINIMAP_SCALE + tex_x)] = color;
					tex_x++;
				}
				tex_y++;
			}
			map_x++;
			screen_x++;
		}
		screen_y++;
		map_y++;
	}
}

void    render_minimap_border(t_game *game)
{
	int tex_x;
	int tex_y;
	
	tex_y = 0;
	while (tex_y < 200)
	{
		tex_x = 0;
		while (tex_x < 200)
		{
			if ((tex_x >= 0 && tex_x < 5) || tex_x >= 195 || (tex_y >= 0 && tex_y < 5) || tex_y >= 195)
				game->image->data[tex_y * SCREEN_WIDTH + tex_x] = rgb_to_hex(32, 204, 0);
			++tex_x;
		}
		++tex_y;
	}
}

void    render_minimap_player(t_game *game)
{
	int tex_x;
	int tex_y;
	int color;
	
	tex_y = 0;
	while (tex_y < MINIMAP_SCALE)
	{
		tex_x = 0;
		while (tex_x < MINIMAP_SCALE)
		{
			color = get_pixel_color(game->textures->player_texture, tex_x, tex_y);
			game->image->data[(100 + tex_y) * SCREEN_WIDTH + (100 + tex_x)] = color;
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
	
	line_height = DRAWING_SCALE / (game->depth[game->depth_lvl].dist + 1);
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	if (game->wall_direction == NORTH || game->wall_direction == SOUTH)
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_y * TEXTURE_SIZE);
	color = rgb_to_hex(255, 0, 255);
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
	int i;
	
	line_height = DRAWING_SCALE / (game->depth[game->depth_lvl].dist + 1);
	y_iterator = SCREEN_HEIGHT / 2 - line_height / 2;
	if (y_iterator < 0)
		y_iterator = 0;
	y_end = SCREEN_HEIGHT / 2 + line_height / 2;
	if (y_end > SCREEN_HEIGHT)
		y_end = SCREEN_HEIGHT;
	if (game->door_direction == NORTH || game->door_direction == SOUTH)
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_x * TEXTURE_SIZE);
	else
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_y * TEXTURE_SIZE);
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE) / line_height / 2;
		i = 0;
		while (i < DOOR_MAX)
		{
			if ((int)game->depth[game->depth_lvl].colis_y == game->door[i].y
				&& (int)game->depth[game->depth_lvl].colis_x == game->door[i].x)
			{
				color = get_pixel_color(game->door[i].texture, tex_x, tex_y);
				break ;
			}
			++i;
		}
		if (color != rgb_to_hex(255, 0, 255))
			game->image->data[y_iterator * SCREEN_WIDTH + game->dist_idx] = color;
		y_iterator++;
	}
}

void    render_enemy_line(t_game *game, int enemy_i)
{
	int y;
	int y_end;
	float tex_y;
	int color;
	float scale;
	
	scale = 0.1f * (float)game->enemy[enemy_i].size;
	y = SCREEN_HEIGHT / 2 - game->enemy[enemy_i].size / 2 + (int)scale; if (y < 0) y = 0; if (y >= SCREEN_HEIGHT) y = SCREEN_HEIGHT - 1;
	y_end = SCREEN_HEIGHT / 2 + game->enemy[enemy_i].size / 2 + (int)scale; if (y_end < 0) y_end = 0; if (y_end > SCREEN_HEIGHT) y_end = SCREEN_HEIGHT - 1;
	tex_y = 0;
	while (y < y_end)
	{
		color = get_pixel_color(game->enemy[enemy_i].texture, (int)game->enemy[enemy_i].tex_x, (int)tex_y);
		if (color != rgb_to_hex(255, 0 , 255))
		{
			game->image->data[y * SCREEN_WIDTH + game->dist_idx] = color;
			game->enemy[enemy_i].hit_body[game->dist_idx] = true;
		}
		++y;
		tex_y += (float)TEXTURE_SIZE / (float)game->enemy[enemy_i].size;
	}
	game->enemy[enemy_i].tex_x += (float)TEXTURE_SIZE / (float)game->enemy[enemy_i].size;
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

void    render_vertical_line(int x, t_game *game, int red, int green, int blue)
{
	int tex_y = 0;
	while (tex_y < SCREEN_HEIGHT)
	{
		game->image->data[tex_y * SCREEN_WIDTH + x] = rgb_to_hex(red, green, blue);
		++tex_y;
	}
}