/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:26:48 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/30 17:19:51 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	render_game(t_game *game)
{
	if (game->main_menu || game->player_dead || game->won_game)
		render_main_menu(game);
	else
	{
		render_background(game);
		raycaster(game);
		render_crosshair(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image->img, 0, 0);
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
	while (tex_y < MINIMAP_SIZE)
	{
		tex_x = 0;
		while (tex_x < MINIMAP_SIZE)
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
	map_y = (int)game->data->player->y / SQUARE_SIZE - (MINIMAP_SIZE_SQUARES / 2);
	while (screen_y < MINIMAP_SIZE_SQUARES)
	{
		screen_x = 0;
		map_x = (int)game->data->player->x / SQUARE_SIZE - (MINIMAP_SIZE_SQUARES / 2);
		while (screen_x < MINIMAP_SIZE_SQUARES)
		{
			tex_y = 0;
			while (tex_y < MINIMAP_SCALE)
			{
				tex_x = 0;
				while (tex_x < MINIMAP_SCALE)
				{
					if (map_x < 0 || map_y < 0 || map_y >= game->data->number_lines_map_element || !game->data->map_element[map_y] || !game->data->map_element[map_y][map_x])
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

void    render_border(t_game *game, int size, int x, int y)
{
	int x_iter;
	int y_iter;

	y_iter = y;
	while (y_iter < size + y)
	{
		x_iter = x;
		while (x_iter < size + x)
		{
			if ((x_iter >= x && x_iter < BORDER_THICKNESS + x)
			    || x_iter >= size + x - BORDER_THICKNESS
			    || (y_iter >= 0 && y_iter < BORDER_THICKNESS + y)
			    || y_iter >= size + y - BORDER_THICKNESS)
				game->image->data[y_iter * SCREEN_WIDTH + x_iter] = rgb_to_hex(32, 204, 0);
			++x_iter;
		}
		++y_iter;
	}
}

void    render_minimap_player(t_game *game)
{
	int x;
	int y;
	float tex_x;
	float tex_y;
	int color;
	
	tex_y = 0;
	y = 0;
	while (y < MINIMAP_SCALE)
	{
		x = 0;
		tex_x = 0;
		while (x < MINIMAP_SCALE)
		{
			color = get_pixel_color(game->textures->player_texture, tex_x, tex_y);
			game->image->data[(MINIMAP_SIZE / 2 + y) * SCREEN_WIDTH + (MINIMAP_SIZE / 2 + x)] = color;
			tex_x += (float)TEXTURE_SIZE_MINIMAP / (float)MINIMAP_SCALE;
			++x;
		}
		tex_y += (float)TEXTURE_SIZE_MINIMAP / (float)MINIMAP_SCALE;
		++y;
	}
	render_border(game, MINIMAP_SIZE, 0, 0);
}

void	render_gun(t_game *game)
{
	int	x;
	int	y;
	float	tex_x;
	float	tex_y;
	int	color;
	
	y = SCREEN_HEIGHT - TEXTURE_SIZE_GUN;
	tex_y = 0;
	while (y < SCREEN_HEIGHT && tex_y < TEXTURE_SIZE_GUN)
	{
		x = SCREEN_WIDTH - TEXTURE_SIZE_GUN;
		tex_x = 0;
		
		while (x < SCREEN_WIDTH && tex_x < TEXTURE_SIZE_GUN)
		{
			color = get_pixel_color(game->textures->gun_current_texture, (int)tex_x, (int)tex_y);
			if (color != rgb_to_hex(255, 0, 255))
				game->image->data[y * SCREEN_WIDTH +x] = color;
			++x;
			tex_x += (float)SIZE_GUN / (float)TEXTURE_SIZE_GUN;
		}
		++y;
		tex_y += (float)SIZE_GUN / (float)TEXTURE_SIZE_GUN;
	}
	
}

//void	render_gun(t_game *game)
//{
//	int	x;
//	int	y;
//	float	tex_x;
//	float	tex_y;
//	int	color;
//
//	y = SCREEN_HEIGHT - SIZE_GUN;
//	tex_y = 0;
//	while (y < SCREEN_HEIGHT && tex_y < DESERT_EAGLE_HEIGHT)
//	{
//		x = SCREEN_WIDTH - SIZE_GUN;
//		tex_x = 0;
//
//		while (x < SCREEN_WIDTH && tex_x < DESERT_EAGLE_WIDTH)
//		{
//			color = get_pixel_color(game->textures->gun_current_texture, (int)tex_x, (int)tex_y);
//			if (color != rgb_to_hex(255, 0, 255))
//				game->image->data[y * SCREEN_WIDTH +x] = color;
//			++x;
//			tex_x += (float)SIZE_GUN / (float)DESERT_EAGLE_WIDTH;
//		}
//		++y;
//		tex_y += (float)SIZE_GUN / (float)DESERT_EAGLE_HEIGHT;
//	}
//
//}

void	render_hp(t_game *game)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;
	
	x = SIZE_AVATAR;
	while (x < TEXTURE_WIDTH_HP + SIZE_AVATAR)
	{
		y = SCREEN_HEIGHT - TEXTURE_HEIGHT_HP;
		while (y < SCREEN_HEIGHT)
		{
			tex_x = x;
			tex_y = y - (SCREEN_HEIGHT - TEXTURE_HEIGHT_HP);
			color = get_pixel_color(game->textures->hp_current_texture, tex_x, tex_y);
			game->image->data[y * SCREEN_WIDTH + x] = color;
			y++;
		}
		x++;
	}
}

void    render_avatar(t_game *game)
{
	int	    x;
	int	    y;
	float	tex_x;
	float	tex_y;
	
	y = SCREEN_HEIGHT - SIZE_AVATAR;
	tex_y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		tex_x = 0;
		while (x < SIZE_AVATAR)
		{
			game->image->data[y * SCREEN_WIDTH + x] = get_pixel_color(game->textures->avatar_current, (int)tex_x, (int)tex_y);
			++x;
			tex_x += (float)TEXTURE_SIZE_AVATAR / (float)SIZE_AVATAR;
		}
		++y;
		tex_y += (float)TEXTURE_SIZE_AVATAR / (float)SIZE_AVATAR;
	}
	render_border(game, SIZE_AVATAR, 0, SCREEN_HEIGHT - SIZE_AVATAR);
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
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_x * TEXTURE_SIZE_DEFAULT);
	else
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_y * TEXTURE_SIZE_DEFAULT);
	color = rgb_to_hex(255, 0, 255);
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE_DEFAULT) / line_height / 2;
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
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_x * TEXTURE_SIZE_DEFAULT);
	else
		tex_x = (int)(game->depth[game->depth_lvl].ray_hit_y * TEXTURE_SIZE_DEFAULT);
	color = 0;
	while (y_iterator < y_end)
	{
		tex_y = ((y_iterator * 2 - SCREEN_HEIGHT + line_height) * TEXTURE_SIZE_DEFAULT) / line_height / 2;
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
			if (!game->enemy[enemy_i].dead)
				game->enemy[enemy_i].hit_body[game->dist_idx] = true;
		}
		++y;
		tex_y += (float)TEXTURE_SIZE_DEFAULT / (float)game->enemy[enemy_i].size;
	}
	game->enemy[enemy_i].tex_x += (float)TEXTURE_SIZE_DEFAULT / (float)game->enemy[enemy_i].size;
}

void    render_main_menu(t_game *game)
{
	int	x;
	int	y;
	float tex_x;
	float tex_y;
	
	x = 0;
	tex_x = 0;
	while (x < SCREEN_WIDTH && tex_x < TEXTURE_MENU_WIDTH)
	{
		y = 0;
		tex_y = 0;
		while (y < SCREEN_HEIGHT && tex_y < TEXTURE_MENU_HEIGHT)
		{
			if (game->player_dead)
				game->image->data[y * SCREEN_WIDTH + x] = get_pixel_color(game->textures->game_over_texture, (int)tex_x, (int)tex_y);
			else if (game->won_game)
				game->image->data[y * SCREEN_WIDTH + x] = get_pixel_color(game->textures->win_screen, (int)tex_x, (int)tex_y);
			else
				game->image->data[y * SCREEN_WIDTH + x] = get_pixel_color(game->textures->main_menu_current, (int)tex_x, (int)tex_y);
			tex_y += (float)TEXTURE_MENU_HEIGHT / (float)SCREEN_HEIGHT;
			y++;
		}
		tex_x += (float)TEXTURE_MENU_WIDTH / (float)SCREEN_WIDTH;
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
