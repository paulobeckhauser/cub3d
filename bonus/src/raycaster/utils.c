/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:18:01 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 22:18:02 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster.h"

void	mark_player(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
			{
				game->player_x = (float)x * game->square_size + game->square_size / 2;
				game->player_y = (float)y * game->square_size + game->square_size / 2;
				return ;
			}
			x++;
		}
		y++;
	}
}

float	to_radians(float degrees)
{
	return (degrees * (M_PI / 180));
}

void    calc_directions(t_raycaster *raycaster, t_game *game)
{
	raycaster->dir_x = game->ray_new_x - game->player_x;
	raycaster->dir_y = game->ray_new_y - game->player_y;
	raycaster->len = sqrtf(raycaster->dir_x * raycaster->dir_x + raycaster->dir_y * raycaster->dir_y);
	raycaster->dir_x /= raycaster->len;
	raycaster->dir_y /= raycaster->len;
}

bool    is_ray_on_square_edge(t_raycaster *raycaster, t_game *game)
{
	if ((int)raycaster->x_iterator % (int)game->square_size == 0
		|| (int)raycaster->y_iterator % (int)game->square_size == 0)
		return (true);
	return (false);
}

int get_pixel_color(void *img_ptr, int x, int y)
{
	char    *data;
	int     bits_per_pixel;
	int     size_line;
	int     endian;
	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (*(int *)(data + ((x + y * size_line / 4) * bits_per_pixel / 8)));
}