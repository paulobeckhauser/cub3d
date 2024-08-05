/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:33:32 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 13:38:53 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	keypress(const int keysymbol, t_game *game)
{
	if (keysymbol == 65307)
		game->keys[ESC] = true;
	if (keysymbol == 119)
		game->keys[W] = true;
	if (keysymbol == 115)
		game->keys[S] = true;
	if (keysymbol == 97)
		game->keys[A] = true;
	if (keysymbol == 100)
		game->keys[D] = true;
	if (keysymbol == 65361)
		game->keys[LEFT_ARROW] = true;
	if (keysymbol == 65363)
		game->keys[RIGHT_ARROW] = true;
	if (keysymbol == 101)
		game->keys[E] = true;
	if (keysymbol == 65293)
		game->keys[ENTER] = true;
	return (0);
}

int	keyrelease(const int keysymbol, t_game *game)
{
	if (keysymbol == 65307)
		game->keys[ESC] = false;
	if (keysymbol == 119)
		game->keys[W] = false;
	if (keysymbol == 115)
		game->keys[S] = false;
	if (keysymbol == 97)
		game->keys[A] = false;
	if (keysymbol == 100)
		game->keys[D] = false;
	if (keysymbol == 65361)
		game->keys[LEFT_ARROW] = false;
	if (keysymbol == 65363)
		game->keys[RIGHT_ARROW] = false;
	if (keysymbol == 101)
		game->keys[E] = false;
	if (keysymbol == 65293)
		game->keys[ENTER] = false;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	game->mouse_x = x;
	(void)y;
	return (0);
}

int	mouse_press(int button, int x, int y, t_game *game)
{
	int				i;

	(void)x;
	(void)y;
	if (button == 1 && !game->animation.animation_gun)
	{
		i = 0;
		while (i < ENEMY_MAX)
		{
			if (game->enemy[i].hit_body[SCREEN_WIDTH / 2])
			{
				game->data.map_element[game->enemy[i].y][game->enemy[i].x]
					= '5';
				--game->enemy_count;
				break ;
			}
			++i;
		}
		game->keys[MOUSE_LEFT_CLICK] = true;
	}
	return (0);
}
